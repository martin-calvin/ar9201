#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <pthread.h>
#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <sys/time.h>
#include "cam_tuning_server.h"
#include "ar_dbg.h"
#include "stddef.h"
#include "execinfo.h"
#include "signal.h"
#include "backtrace.h"

#define AR_DBG_MAX_CLIENT 1
#define AR_DBG_CLIENT_BUF_SIZE 0x2000000
#define AR_DBG_PORT 1234

struct ar_dbg_msg {
    uint8_t  header1;
    uint8_t  header2;
    uint8_t  version;
    uint8_t  msg_id;
    uint16_t seq_num;
    uint32_t msg_len;
    uint8_t  header_sum;
    uint16_t checksum;
    uint8_t  payload[];
}__attribute__((packed));

struct ar_dbg_client {
    struct sockaddr_in addr;
    uint8_t *req_buffer;
    uint8_t *ack_buffer;
    int server, client;
    uint32_t status;
    pthread_t handler;
    pthread_mutex_t lock;
};

static struct ar_dbg_client *clients = NULL;
static int clients_num = 0;
static pthread_mutex_t service_lock;
static pthread_cond_t cond;
static uint16_t seq_num = 0;

static uint32_t calc_checksum(uint8_t *req, uint32_t req_len)
{
    uint32_t cs = 0;
    int i;

    for(i = 0; i < req_len; i++) {
        cs += req[i];
    }
    return cs;
}

static int client_handle_request(struct ar_dbg_client *client, uint32_t req_len)
{
    struct ar_dbg_msg *recv_msg = (struct ar_dbg_msg *)(client->req_buffer);
    uint8_t *payload = client->req_buffer + sizeof(*recv_msg);
    uint16_t cs;
    uint32_t ack_payload_len;
    int ret;

    switch(recv_msg->msg_id) {
    case AR_DBG_MSG_SYS:
        ret = dbg_handle_sys((void *)client, payload, recv_msg->msg_len);
        break;
    case AR_DBG_MSG_REG:
        ret = dbg_handle_reg((void *)client, payload, recv_msg->msg_len, recv_msg->seq_num);
        break;
    case AR_DBG_MSG_BB:
        break;
    case AR_DBG_MSG_CMR:
        ret=dbg_handle_cam_tuning((void *)client,payload,recv_msg->msg_len);
        break;
    default:
        printf("invalid msg id\n");
        ret = -EINVAL;
        break;
    }

    /* Encounter errro, return empty pack */
    if(ret){
        printf("Encounter errro, return empty pack");
        client_send_ack(client, NULL, 0, recv_msg->msg_id, 0);
    }

    return ret;
}

int client_recv_req(struct ar_dbg_client *client)
{
    int ret;
    uint32_t recv_len = 0, cs = 0;
    uint8_t *payload;
    struct ar_dbg_msg *recv_msg = (struct ar_dbg_msg *)(client->req_buffer);

    /*
     * ret < 0: receive error
     * ret = 0: peer closed
     */
    ret = recv(client->client, client->req_buffer, sizeof(*recv_msg), 0);
    if (ret < 0) {
        printf("client_recv_req Socket receive failed %d\n",__LINE__);
        return -EINVAL;
    }
    if (ret == 0) {
        printf("Peer closed\n");
        return -EINVAL;
    }

    recv_len += ret;

    while(1) {
        ret = recv(client->client, client->req_buffer + recv_len,
                recv_msg->msg_len + sizeof(*recv_msg) - recv_len, 0);

        if (ret < 0) {
            printf("client_recv_req recv Socket receive failed %d\n",__LINE__);
            return -EINVAL;
        }
        if (ret == 0) {
            printf("client_recv_req Peer closed\n");
            return -EINVAL;
        }

        recv_len += ret;

        if(recv_len >= recv_msg->msg_len + sizeof(*recv_msg)) {
            break;
        }

    }
    if(recv_msg->header1 != 0xff || recv_msg->header2 != 0x5a) {
        printf("bad magic\n");
        return -EINVAL;
    }

    if(sizeof(*recv_msg) + recv_msg->msg_len > recv_len) {
        printf("bad msg length %d %d %d\n",
            sizeof(*recv_msg), recv_msg->msg_len, recv_len);
        return -EINVAL;
    }

    payload = client->req_buffer + sizeof(*recv_msg);

    cs = calc_checksum(payload, recv_msg->msg_len);
    if (cs != recv_msg->checksum) {
        printf("bad checksum  cs=%d,recv_msg->checksum=%d\n",cs,recv_msg->checksum);
        // return -EINVAL;
    }

    return recv_len;
}

int client_send_ack(void *client, uint8_t *payload, uint32_t payload_size,
        uint8_t msg_id, uint8_t need_checksum)
{
    int ret;
    struct ar_dbg_client *dbg_client = (struct ar_dbg_client *)client;
    struct ar_dbg_msg *ack_msg = (struct ar_dbg_msg *)dbg_client->ack_buffer;

    pthread_mutex_lock(&dbg_client->lock);
    ack_msg->header1 = 0xff;
    ack_msg->header2 = 0x5a;
    ack_msg->version = 0;
    ack_msg->msg_id = msg_id;
    ack_msg->seq_num = seq_num++;
    ack_msg->msg_len = payload_size;
    ack_msg->header_sum = calc_checksum((uint8_t *)ack_msg,
            sizeof(*ack_msg) - sizeof(uint8_t) - sizeof(uint16_t));
    if(need_checksum)
        ack_msg->checksum = calc_checksum(payload, payload_size);
    else
        ack_msg->checksum = 0;

    if(payload != dbg_client->ack_buffer + sizeof(*ack_msg))
        memcpy(dbg_client->ack_buffer + sizeof(*ack_msg), payload, payload_size);

    ret = send(dbg_client->client, dbg_client->ack_buffer,
        sizeof(*ack_msg) + payload_size, 0);
    pthread_mutex_unlock(&dbg_client->lock);

    if(ret <=0) {
        if (ret < 0) {
            printf("client_send_ack Socket receive failed\n");
        }
        if (ret == 0) {
            printf("Peer closed\n");
        }
        return -EINVAL;
    }
    return 0;
}

static void *client_handle_thread(void *p)
{
    struct ar_dbg_client *client = (struct ar_dbg_client *)p;
    int ret;
    uint8_t *ack_payload = client->ack_buffer;
    uint32_t ack_payload_len = AR_DBG_CLIENT_BUF_SIZE;

    while (1) {
        ret = client_recv_req(client);
        if(ret <= 0) {
            break;
        }

        ret = client_handle_request(client, ret);
        if(ret < 0) {
        }
    }
    unregister_cam_tuning_client(client);
    close(client->client);
    free(client->req_buffer);
    free(client->ack_buffer);
    free(client);

    pthread_mutex_lock(&service_lock);
    clients_num--;
    pthread_mutex_unlock(&service_lock);
    pthread_cond_signal(&cond);
}

static void *client_accept_thread(void *p)
{
    struct ar_dbg_client *client;
    int ret;
    int server = *(int *)p;
    int sockaddr_in_size;
    pthread_t handler;
    struct timeval now;
    struct timespec outtime;

    sockaddr_in_size = sizeof(struct sockaddr_in);

    printf("client accept thread running\n");

    pthread_cond_init(&cond, NULL);

    while (1) {
        pthread_mutex_lock(&service_lock);
        if (clients_num >= AR_DBG_MAX_CLIENT) {
            gettimeofday(&now, NULL);
            outtime.tv_sec = now.tv_sec + 5;
            outtime.tv_nsec = now.tv_usec * 1000;
            pthread_cond_timedwait(&cond, &service_lock, &outtime);
            pthread_mutex_unlock(&service_lock);
            continue;
        }
        clients_num++;
        pthread_mutex_unlock(&service_lock);

        client = malloc(sizeof(*client));
        if(!client) {
            printf("Malloc client failed\n");
            continue;
        }

        ret = accept(server, (struct sockaddr *)&client->addr, &sockaddr_in_size);
        if (ret < 0) {
            printf("Accept socket failed\n");
            free(client);
            continue;
        }

        printf("accept one client\n");

        memset(client, 0, sizeof(*client));
        client->client = ret;
        client->server = server;
        client->req_buffer = malloc(AR_DBG_CLIENT_BUF_SIZE);
        if(!client->req_buffer) {
            printf("Malloc client buffer failed\n");
            close(client->client);
            free(client);
            continue;
        }

        client->ack_buffer = malloc(AR_DBG_CLIENT_BUF_SIZE);
        if(!client->ack_buffer) {
            printf("Malloc client buffer failed\n");
            close(client->client);
            free(client->req_buffer);
            free(client);
            continue;
        }
        pthread_mutex_init(&client->lock, NULL);

        pthread_create(&handler, NULL, client_handle_thread, client);

        client->handler = handler;
        register_cam_tuning_send_ops(client_send_ack,client,AR_DBG_MSG_CMR);
    }
}
int main(int argc, char *argv)
{
    struct sockaddr_in server_addr;
    int server, ret;
    pthread_t accept_thread;
    back_trace_t *back_trace=creat_back_trace();

    server = socket(AF_INET, SOCK_STREAM, 0);
    if (server < 0) {
        printf("Create socked failed\n");
        exit(-1);
    }
    printf("Create socked success\n");

    pthread_mutex_init(&service_lock, NULL);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(AR_DBG_PORT);

    ret = bind(server, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if(ret < 0) {
        printf("Bind socket failed\n");
        exit(-1);
    }

    printf("Bind socket success\n");

    ret = listen(server, 10);
    if (ret < 0) {
        printf("Listen socket fail\n");
        exit(-1);
    }

    printf("Listen socket success\n");

    pthread_create(&accept_thread, NULL, client_accept_thread, &server);

    //test_back_trace();

    pthread_join(accept_thread, NULL);

    printf("Debug server exit\n");

    exit(0);
}
