#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <errno.h>
#include "ar_log.h"

#include <fcntl.h>
#include <unistd.h>

#include "test_mem_watch.h"

///////////////////////////////////////////////

#define TEST_MEM_WATCH_VALUE (0xA55a0Ff0)
#define TEST_MEM_WATCH_CHECKINTERVAL (1000*1000)

#define TEST_MEM_ITEM1_CALCU_ENABLE
// #define TEST_MEM_ITEM2_CALCU_ENABLE

// #define TEST_MEM_EXIT_WHEN_DETECT_ERROR
// #define TEST_MEM_DETECT_ERROR_ONCE_AND_KEEP

// #define TEST_MEM_ERROR_SHOW_VALUE_ENABLE
#define TEST_MEM_MAX_SHOW_ERROR_MEM_VALUE_NUM   (2)

unsigned int g_page_size = 0;
unsigned int g_page_mask;

unsigned int parse_param(char const *param)
{
    if(NULL == param)
    {
        log_err("empty input");
        return 0;
    }

    log_always("param : %s", param);

    unsigned int ret_len = 0;
    unsigned int str_len = strlen(param);
    if(0 == str_len)
    {
        log_err("param len %d", str_len);
        return 0;
    }

    unsigned int loop_count;
    unsigned int tmp;
    unsigned int tmp_count;
    for(loop_count=0; loop_count<str_len; loop_count++)
    {
        if(param[loop_count]<='9' && param[loop_count]>='0')
        {
            tmp = param[loop_count] - '0';
            for(tmp_count = 1; tmp_count< str_len-loop_count; tmp_count++)
            {
                tmp *= 10;
            }
            ret_len += tmp;
        }
        else
        {
            log_err("param %c", param[loop_count]);
            return 0;
        }
    }

    ret_len <<= 20;//(MB)

    return ret_len;
}


#ifdef TEST_MEM_ITEM2_CALCU_ENABLE
typedef union{
    unsigned int data_int;
    unsigned char data_c[4];
} test_endian_t;
int test_addr_get_pAddr2(unsigned int v_addr, unsigned int *p_ret)
{
    unsigned int v_pageIndex = v_addr/g_page_size;
    unsigned int v_offset = v_pageIndex * sizeof(uint64_t);
    unsigned int page_offset = v_addr % g_page_size;

    uint64_t item = 0;

    // log_always("index %x, offset 0x%x | 0x%x",v_pageIndex,page_offset,sizeof(uint64_t));

    unsigned char c_buf[sizeof(uint64_t)];
    unsigned int loop_count;
    unsigned char tmp_c;

    test_endian_t endian_test;
    endian_test.data_int = 0x11223344;
    // log_always("int : *(0x%x) = 0x%x", &endian_test.data_int, endian_test.data_int);
    // for(loop_count = 0; loop_count<4; loop_count++)
    // {
    //     log_always("char No. %d : *(0x%x) = 0x%x", loop_count, &endian_test.data_c[loop_count],endian_test.data_c[loop_count]);
    // }

    int is_big;
    if(0x11 == endian_test.data_c[0])
    {
        is_big = 1;
        // log_always("big");
    }
    else
    {
        is_big = 0;
        // log_always("little");
    }

    // is_big = 1;//test

    // log_always("open");
    int fd = fopen("/proc/self/pagemap", "rb");
    // log_always("seek");
    if(fseek(fd, v_offset, SEEK_SET) == -1)
    {
        log_err("lseek fail");
        close(fd);
        return -1;
    }

    int test;

    // log_always("read");
    for(loop_count = 0; loop_count<sizeof(uint64_t); loop_count++)
    {
        tmp_c = getc(fd);
        if(EOF == tmp_c)
        {
            log_err("get tmp_c fail");
            fclose(fd);
            return -1;
        }

        if(is_big)
        {
            c_buf[loop_count] = tmp_c;
        }
        else
        {
            c_buf[sizeof(uint64_t)-1-loop_count] = tmp_c;
        }
    }
    fclose(fd);

    for(loop_count = 0; loop_count<sizeof(uint64_t); loop_count++)
    {
        item = (item<<8)+c_buf[loop_count];
        // log_always("No. %d : 0x%x", loop_count, c_buf[loop_count]);
    }

    // log_always("item 0x%llx", item);

#if 0
    if( 0 == ( ((uint64_t)1) <<63 ) & item  )
    {
        log_err("page present is 0");
        return -1;
    }

    uint64_t phy_pageIndex = ( ( ((uint64_t)1) << 55 ) -1 ) & item;

    *p_ret = (phy_pageIndex * g_page_size) + page_offset;

    return 0;
#endif
    // log_always("present 0x%x", c_buf[0]&0x80);
    if( 0 == (c_buf[0]&0x80) )
    {
        log_err("page present is 0");
        return -1;
    }

    unsigned int phy_pageIndex = c_buf[7] | (c_buf[6]<<8) | (c_buf[5]<<16) | (c_buf[4]<<24);

    *p_ret = (phy_pageIndex * g_page_size) + page_offset;

    return 0;
}
#endif

#ifdef TEST_MEM_ITEM1_CALCU_ENABLE
int test_addr_get_pAddr(unsigned int v_addr, unsigned int *p_ret)
{
    unsigned int v_pageIndex = v_addr/g_page_size;
    unsigned int v_offset = v_pageIndex * sizeof(uint64_t);
    unsigned int page_offset = v_addr % g_page_size;

    uint64_t item = 0;

    // log_always("index %x, offset 0x%x | 0x%x",v_pageIndex,page_offset,sizeof(uint64_t));

    int fd = open("/proc/self/pagemap", O_RDONLY);
    if(fd < 0)
    {
        log_err("fail to get pAddr");
        return -1;
    }

    if(lseek(fd, v_offset, SEEK_SET) == -1)
    {
        log_err("lseek fail");
        close(fd);
        return -1;
    }

    if(read(fd, &item, sizeof(uint64_t)) != sizeof(uint64_t))
    {
        log_err("read item fail");
        close(fd);
        return -1;
    }
    close(fd);

    // log_always("item 0x%llx", item);

    if( 0 == ( ( ((uint64_t)1) <<63 ) & item ) )
    {
        log_err("page present is 0");
        return -1;
    }

    uint64_t phy_pageIndex = ( ( ((uint64_t)1) << 55 ) -1 ) & item;

    *p_ret = (phy_pageIndex * g_page_size) + page_offset;

    return 0;
}
#endif

int test_mem_init_mem(unsigned int *p_mem, unsigned int len_buf, unsigned int value)
{
    unsigned int len = len_buf/sizeof(unsigned int);
    unsigned int loop_count;
    unsigned int phy_addr;
    unsigned int end_addr;

    for(loop_count=0;loop_count<len;loop_count++)
    {
        p_mem[loop_count] = value;
    }
#ifdef TEST_MEM_ITEM1_CALCU_ENABLE
    phy_addr = 0;
    end_addr = 0;
    test_addr_get_pAddr(p_mem, &phy_addr);
    test_addr_get_pAddr(&p_mem[len-1], &end_addr);
    log_always("mem start : s-vAddr 0x%08x - pAddr 0x%08x e-vAddr 0x%08x - pAddr 0x%08x, len %d-0x%x"\
        , p_mem, phy_addr\
        , &p_mem[len-1], end_addr, len_buf, len_buf);
#endif

#ifdef TEST_MEM_ITEM2_CALCU_ENABLE
    phy_addr = 0;
    end_addr = 0;
    test_addr_get_pAddr2(p_mem, &phy_addr);
    test_addr_get_pAddr2(&p_mem[len-1], &end_addr);
    log_always("mem2 start : s-vAddr 0x%08x - pAddr 0x%08x e-vAddr 0x%08x - pAddr 0x%08x, len %d-0x%x"\
        , p_mem, phy_addr\
        , &p_mem[len-1], end_addr, len_buf, len_buf);
#endif

    return 0;
}

unsigned int test_mem_watch(unsigned int *p_mem, unsigned int len_buf, unsigned int value)
{
    unsigned int len = len_buf/sizeof(unsigned int);
    unsigned int loop_count;

    unsigned int *start_positon = 0;
    unsigned int error_len = 0;
    unsigned int error_len_total = 0;

    unsigned int flag_print = 0;
    unsigned int phy_addr = 0;

    unsigned int erro_ouptut_len;
    unsigned int loop_err_count;

    unsigned int error_flag = 0;

    for(loop_count=0;loop_count<len;loop_count++)
    {
        if(p_mem[loop_count] != value)
        {
            if(0 == error_len)
            {
                start_positon = &p_mem[loop_count];
            }
            error_len++;
            flag_print = 1;
            error_flag = 1;
        }
        else if(flag_print)
        {
            flag_print = 0;
#ifdef TEST_MEM_ITEM1_CALCU_ENABLE
            phy_addr = 0;
            test_addr_get_pAddr(start_positon, &phy_addr);
            log_err("mem error : vAddr 0x%08x - pAddr 0x%08x, len %d(%d)", start_positon, phy_addr, error_len<<2, len_buf);
#endif

#ifdef TEST_MEM_ITEM2_CALCU_ENABLE
            phy_addr = 0;
            test_addr_get_pAddr2(start_positon, &phy_addr);
            log_err("mem2 error : vAddr 0x%08x - pAddr 0x%08x, len %d(%d)", start_positon, phy_addr, error_len<<2, len_buf);
#endif

#ifdef TEST_MEM_ERROR_SHOW_VALUE_ENABLE
            erro_ouptut_len = (error_len>TEST_MEM_MAX_SHOW_ERROR_MEM_VALUE_NUM) ? TEST_MEM_MAX_SHOW_ERROR_MEM_VALUE_NUM : error_len;
            for(loop_err_count = 0; loop_err_count<erro_ouptut_len; loop_err_count++)
            {
                log_err("\t No. %d - value 0x%08x", loop_err_count, start_positon[loop_err_count]);
            }
#endif

#ifndef TEST_MEM_DETECT_ERROR_ONCE_AND_KEEP
            for(loop_err_count = 0; loop_err_count<error_len; loop_err_count++)
            {
                start_positon[loop_err_count] = value;
            }
#endif
            error_len_total += error_len;
            error_len = 0;
        }

    }

    if(error_flag)
    {
        log_err("total len %d\n\n",error_len_total);
    }

    return error_len_total;
}

static unsigned int test_mem_align_test1()
{
    unsigned char p_buff_char[8]={
        0x11,0x22,0x33,0x44,0x55,0x66,0x77,0x88
    };

    unsigned short *p_test_short;
    unsigned int *p_test_int;

    for(unsigned int loop_count = 0; loop_count<8; loop_count++)
    {
        printf("char No. %d - addr : 0x%x value : 0x%x\n"\
            , loop_count\
            , &p_buff_char[loop_count]\
            , p_buff_char[loop_count]);
    }

    for(unsigned int offset_test = 0; offset_test<4; offset_test++)
    {
        p_test_short = (unsigned short *) &p_buff_char[offset_test];
        printf("short offset test - offset : %d addr : 0x%x\n"\
            , offset_test, p_test_short);
        for(unsigned int loop_count = 0; loop_count<2; loop_count++)
        {
            printf("short No. %d - addr : 0x%x value : 0x%x\n"\
                , loop_count\
                , &p_test_short[loop_count]\
                , p_test_short[loop_count]);
        }
    }

    for(unsigned int offset_test = 0; offset_test<4; offset_test++)
    {
        p_test_int = (unsigned int *) &p_buff_char[offset_test];
        printf("int offset test - offset : %d addr : 0x%x\n"\
            , offset_test, p_test_int);
        for(unsigned int loop_count = 0; loop_count<1; loop_count++)
        {
            printf("int No. %d - addr : 0x%x value : 0x%x\n"\
                , loop_count\
                , &p_test_short[loop_count]\
                , p_test_short[loop_count]);
        }
    }

    return 0;
}

int main(int argc, char const *argv[])
{
    /* code */
    unsigned int test_size;
    unsigned int ret;

    g_page_size = getpagesize();
    if(g_page_size == 0)
    {
        log_err("fail to get page size");
        g_page_size = 4096;
    }
    g_page_mask = ~(g_page_size-1);
    // log_always("page size %d, mask 0x%x",g_page_size, g_page_mask);

    if(argc < 2){
        test_mem_align_test1();
        test_size = g_page_size;
    }
    else
    {
        test_size = parse_param(argv[1]);
        if(0 == test_size)
        {
            log_err("block size %d", test_size);
            return -1;
        }
    }

    unsigned char *p_buff = NULL;
    unsigned int *p_int_align = NULL;
    unsigned int buff_size = test_size;

    unsigned char mem_done = 0;

    while(!mem_done)
    {
        while( !p_buff && buff_size)
        {
            // log_always("try to malloc buff size %d (%d) - 0x%x",test_size, buff_size, p_buff);
            p_buff = malloc(buff_size);
            if(!p_buff)
            {
                buff_size -= g_page_size;
                log_always("get 0x%x -change size %d",p_buff, buff_size);
            }
        }

        // log_always("try to mlock ...");


        buff_size =test_size;
        if( (unsigned int)p_buff % g_page_size)
        {
            p_int_align = ( (unsigned int)p_buff & g_page_mask) + g_page_size;
            buff_size -= ( (unsigned char *)p_int_align - p_buff);
        }
        else
        {
            p_int_align = p_buff;
        }
        if(mlock(p_int_align, buff_size)<0)
        {
            switch(errno)
            {
                case EAGAIN:
                    log_err("over system/pre-process limit, reducing ...");
                    free(p_buff);
                    p_buff = NULL;
                    test_size -= g_page_size;
                    break;
                // case ENOMEN:
                //     log_err("too many pages, reducing ...");
                //     free(p_buff);
                //     p_buff = NULL;
                //     test_size -= g_page_size;
                //     break;
                case EPERM:
                    log_err("insufficient permission. Trying again");
                    break;
                default:
                    log_err("failed for unknown reason 0x%x", errno);
                    mem_done = 1;
                    break;
            }
        }
        else
        {
            // log_always("locked\n");
            mem_done = 1;
        }
    }

    // log_always("init mem ...\n");
    test_mem_init_mem(p_int_align, test_size, TEST_MEM_WATCH_VALUE);

    log_always("start watch...\n");

    ret = 0;
    while(1)
    {
#ifdef TEST_MEM_DETECT_ERROR_ONCE_AND_KEEP
        if(!ret)
#endif
        {
            ret = test_mem_watch(p_int_align, test_size, TEST_MEM_WATCH_VALUE);
            if(ret)
            {
                log_always("error detected ...%d\n",ret);
#ifdef TEST_MEM_EXIT_WHEN_DETECT_ERROR
                free(p_buff);
                return 0;
#endif
            }
        }


        usleep(TEST_MEM_WATCH_CHECKINTERVAL);
    }

    return 0;
}