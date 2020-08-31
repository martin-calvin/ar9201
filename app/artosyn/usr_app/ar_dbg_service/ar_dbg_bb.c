#include <stdint.h>
#include <stdio.h>
#include <fcntl.h>
#include <errno.h>
#include <malloc.h>
#include <sys/mman.h>
#include <unistd.h>
#include <pthread.h>
#include "ar_dbg.h"
#include <stdbool.h>
#include "v4ar_dev.h"
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include "ar_bb.h"
#include "ar_video_codec.h"
#include "ar_bb_tool_app.h"

//STATIC FOR OSD
static pthread_t osd_handler = NULL;
static int32_t osd_fd = 0xffffffff;
static pthread_mutex_t bb_osd_lock;
static void * client_p = NULL;
//#define BB_CMD_LEN_MAX 512



void ar_bb_osd_plot_callback(void* msg_buf ,uint16_t msg_len)
{
	int ret = 0;
	uint8_t buf[BB_CMD_LEN_MAX];
	struct bb_rcv_msg_header *rcv_header = (struct bb_rcv_msg_header *)buf;

	if(0 == pthread_mutex_trylock(&bb_osd_lock)){
		if(NULL != client_p){
			rcv_header->bb_msg_id = BB_LOCAL_MSG_TOOL_UINT8(GET_OSD_INFO);
			rcv_header->ret_type = 0x00;
			memcpy(rcv_header->payload, msg_buf, msg_len);
			ret = client_send_ack(client_p, buf, msg_len + sizeof(struct bb_rcv_msg_header), AR_DBG_MSG_BB, 1);
		}
		pthread_mutex_unlock(&bb_osd_lock);
	}else{
		//stop osd_plot
		ar_bb_osd_plot_stop();
	}

	if(ret < 0) {
		printf("dbg_handle_bb osd send_tcp_data err!\n");
		return;
	}

}

void bb_osd_mutex_unlock_callback(void* client)
{
	static int  mutex_inited = 0;
	if(0 == mutex_inited){
		if( 0!= pthread_mutex_init(&bb_osd_lock, NULL) )
		{
			printf("mutex for bb_osd create failed!!\n");
		}
		mutex_inited = 1;
	}

	client_p = client;

	ar_bb_rpc_r2l_callback_set(AR_R2L_OSD, ar_bb_osd_plot_callback);
	pthread_mutex_unlock(&bb_osd_lock);

}

void bb_osd_mutex_lock_callback(void)
{
	pthread_mutex_lock(&bb_osd_lock);
	client_p = NULL;
	ar_bb_osd_plot_stop();
}

int32_t ar_bb_osd_plot_stop(void)
{
	int ret = 0;
	uint8_t msg_buf[BB_CMD_LEN_MAX];

	msg_buf[0] = 0x00;//stop osd plot
	ret = ar_bb_rpc_l2r_msg( AR_BB_CMD, BB_LOCAL_MSG_TOOL_UINT8(GET_OSD_INFO), msg_buf, 1, sizeof(msg_buf));
	if(ret < 0){
		printf("stop osd plot failed!\n");
		return ret;
	}
	//printf("ar_bb_osd_plot_stop succ\n");
	//relese osd callback
	return ret;
}

static int ar_bb_cmd_set_video_rc(uint8_t code, void* data )
{
    //LOG_BUF(PRN_BUFF," ");
    static ar_vcodec_handle_t vcodec_handle = NULL;
    ar_vcodec_ctrl_rc_param_t rc_param;
    char ret = 0;
    uint16_t coderate_khz = 0;
    struct bb_rpc_msg_header *bbmsg = data;

    uint8_t rw_mode = *((uint8_t*)bbmsg->data); //0:write   1:read
    uint8_t cr_l    = *((uint8_t*)bbmsg->data+1);
    uint8_t cr_h    = *((uint8_t*)bbmsg->data+2);

    //printf("ar_bb_cmd_set_video_cr tid:0x%lx\n",pthread_self());

    if( (rw_mode != 0) && ( rw_mode != 1) ){
        ret = -1;
        printf("ar_bb_cmd_set_video_cr open param err tid:0x%lx\n",pthread_self());
        goto END;
    }

    if(NULL == vcodec_handle){
        vcodec_handle = ar_video_codec_open("/dev/hevc_encoder-0");
        if(NULL == vcodec_handle){
            ret = -1;
            printf("open video_enc_handle failed tid:0x%lx\n",pthread_self());
            goto END;
        }

        printf("ar_bb_cmd_set_video_cr open done tid:0x%lx\n",pthread_self());
    }

    coderate_khz = (uint16_t)cr_l + (((uint16_t)cr_h)<<8);
    if(rw_mode){//1:read

        //printf("ar_bb_cmd_set_video_cr read tid:0x%lx\n",pthread_self());
        if(0 == ar_video_encoder_get_rc_param(vcodec_handle, &rc_param)){
            coderate_khz = rc_param.target_bitrate;
            printf("ar_video_encoder_get_rc:%d\n",coderate_khz);
        }else{
            ret = -1;
            printf("ar_video_encoder_get_rc_param failed tid:0x%lx\n",pthread_self());
            goto END;
        }
    }else{//write
        printf("ar_bb_cmd_set_video_cr write tid:0x%lx\n",pthread_self());
        if(0 != ar_video_encoder_get_rc_param(vcodec_handle, &rc_param)){
            ret = -1;
            printf("ar_video_encoder_get_rc_param failed tid:0x%lx\n",pthread_self());
            goto END;
        }
        rc_param.target_bitrate = coderate_khz;//update coderate
        rc_param.max_bitrate = coderate_khz;//update coderate
        printf("ar_video_encoder_set_rc:%d\n",coderate_khz);
        if(0 != ar_video_encoder_set_rc_param(vcodec_handle, &rc_param)){
            ret = -1;
            printf("ar_video_encoder_set_rc_param failed tid:0x%lx\n",pthread_self());
            goto END;
        }
        coderate_khz = 0;
    }
END:
    bbmsg->len_l = ( sizeof(struct bb_rpc_msg_header) + BB_RET_TYPE_LEN + sizeof(coderate_khz))&0xff;
    bbmsg->len_h = (( sizeof(struct bb_rpc_msg_header) + BB_RET_TYPE_LEN + sizeof(coderate_khz))>>8)&0xff;
    *((char*)bbmsg->data) = ret;
    *((uint8_t*)bbmsg->data+1) = coderate_khz&0xff;
    *((uint8_t*)bbmsg->data+2) = (coderate_khz>>8)&0xff;
    return 0;

}

int32_t ar_bb_msg_dispose(uint8_t msg_type, uint8_t msg_sub_type, void* msg_buf, uint16_t msg_len, uint16_t msg_buf_len)
{
    int32_t ret = 0;
    uint8_t cmd_buf[BB_CMD_LEN_MAX];
    uint16_t len;

    if(msg_len > (BB_CMD_LEN_MAX))
        return -1;

    struct bb_rpc_msg_header *header = (struct bb_rpc_msg_header *)cmd_buf;

    header->len_l = (msg_len+sizeof(struct bb_rpc_msg_header))&0xff;
    header->len_h = ((msg_len+sizeof(struct bb_rpc_msg_header))>>8)&0xff;
    header->msg_type = msg_type;
    header->msg_sub_type = msg_sub_type;
    memcpy(header->data, msg_buf, msg_len);

    if(AR_BB_CMD == msg_type){
        switch (msg_sub_type){
            case BB_LOCAL_MSG_TOOL_UINT8(SET_VIDEO_CR):
                ret = ar_bb_cmd_set_video_rc(msg_sub_type, header);
                break;

            default:
                printf("warn: donot support the msg\n");
            ret = -1;
                break;
        }
	}

    if(0 == ret){
        len = ((uint16_t)header->len_h<<8) + (uint16_t)header->len_l - sizeof(struct bb_rpc_msg_header);
        if( len > msg_buf_len ){
            len = msg_buf_len;
            printf("warn: bb rpc lose some msg\n");
        }
        memcpy(msg_buf, header->data, len);
        ret = len;
    }

    return ret;
}


int dbg_handle_bb(void *client, uint8_t *payload, uint32_t payload_len)
{
	int ret = 0;
	uint8_t msg_buf[BB_CMD_LEN_MAX+1];

	printf("ar_bb_rcv:");
	for(int i=0;i<payload_len;i++)
		{printf("-0x%x",*(payload+i));}
	printf("\n");

	memcpy(msg_buf , payload, payload_len);
	struct bb_msg_header *header =
				(struct bb_msg_header *)msg_buf;

    if( SET_VIDEO_CR == BB_TOOL_MSG_TO_LOCAL_UINT32(header->bb_msg_id )){
        ret = ar_bb_msg_dispose( AR_BB_CMD, BB_TOOL_MSG_TO_LOCAL_UINT32(header->bb_msg_id),
                             header->payload, payload_len-sizeof(struct bb_msg_header), sizeof(msg_buf)-sizeof(struct bb_msg_header));
    }else{
        ret = ar_bb_rpc_l2r_msg( AR_BB_CMD, BB_TOOL_MSG_TO_LOCAL_UINT32(header->bb_msg_id),
                              header->payload, payload_len-sizeof(struct bb_msg_header), sizeof(msg_buf)-sizeof(struct bb_msg_header));
    }

    if(ret < 0){
        printf("dbg_handle_bb send_cmd_to_rtos err!\n");
        return ret;
    }

	ret = client_send_ack(client, msg_buf, ret+1, AR_DBG_MSG_BB, 1);
	if(ret < 0) {
		printf("dbg_handle_bb send_tcp_data err!\n");
		return ret;
	}
    //printf("<\n");
	return ret;
}


