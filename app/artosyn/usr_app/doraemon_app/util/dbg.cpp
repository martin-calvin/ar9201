/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : dbg.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/4/24
*  Last Modified :
*  Description   : dbg file
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/4/24
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/

/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/time.h>
#include "dbg.h"
#include "logutil.h"
#include "basic_typedef.h"
#include "utils.h"
#include "softfilter.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
#define MAX_DBG_CMD_NUM     100
#define MAX_DBG_CMD_LEN     128
#define TEST_DATA_PATH      "/mnt/sdcard/test_data/"

#define dbgmsg(fmt, arg...) \
        do { \
                printf("DBG> ", fmt, ##arg);\
        } while (0)

 
/*==============================================*
*      struct defined                          *
*----------------------------------------------*/
typedef struct
{
    char cmd_name[64];
    char usage[128];
    void (*cmd_func)(char *param);
} dbg_cmd;


 /*==============================================*
  *      project-wide global variables           *
  *----------------------------------------------*/
extern void *Video_Main_Thread(void *arg);
static void dbg_cmd_help_func(char *param);
 
 

 /*==============================================*
  *      routines' or functions' implementations *
  *----------------------------------------------*/
static void dbg_cmd_init_func(char *param)
{
    //start_new_thread("Video Main Thread", NULL, Video_Main_Thread, NULL);
}
 

 static void dbg_cmd_test_func(char *param)
 {
     INFO("jiangxiaohui just for dbg test!\n");

     /*
     小端: 高字节在高地址，低字节在低地址
     大端：高字节在低地址，低字节在高地址
     */
     union data
     {
         int i;
         char ch;
     }a;
 
     a.i = 1;
 
     if (1 == a.ch)
         printf("Little_endian!\n");
     else
         printf("Big_endian!\n");
 
 }
 
#if 0
typedef struct {
    short x;
    short y;
} Point2s;
void Softfilter(unsigned char *buf, unsigned short* img, int width, int height, int maxDiff, int maxSpeckleSize, int newVal)
{
     printf("Start Softfilter!");
     int npixels = width*height;
 
     int i, j, dstep = (int)(width * 2 / sizeof(short));
     int* labels = (int*)buf;
     buf += npixels*sizeof(labels[0]);
     Point2s* wbuf = (Point2s*)buf;
     buf += npixels*sizeof(wbuf[0]);
     unsigned char* rtype = (unsigned char*)buf;
     int curlabel = 0;
     
     // clear out label assignments
     memset(labels, 0, npixels*sizeof(labels[0]));


     for (i = 0; i < height; i++)
     {
         unsigned short* ds = &img[width*i];
         int* ls = labels + width*i;
 
         for (j = 0; j < width; j++)
         {
             if (ds[j] != newVal)    // not a bad disparity
             {
                 if (ls[j])        // has a label, check for bad label
                 {
                     if (rtype[ls[j]]) // small region, zero out disparity
                         ds[j] = (short)newVal;
                 }
                 // no label, assign and propagate
                 else
                 {
                     Point2s* ws = wbuf;    // initialize wavefront
                     Point2s p;
                     p.x = (short)j;
                     p.y = (short)i;
                     //((short)j, (short)i);    // current pixel
                     curlabel++;    // next label
                     int count = 0;    // current region size
                     ls[j] = curlabel;
 
                     // wavefront propagation
                     while (ws >= wbuf) // wavefront not empty
                     {
                         count++;
                         // put neighbors onto wavefront
                         unsigned short* dpp = &img[p.y*width + p.x];//.at<short>(p.y, p.x);
                         short dp = *dpp;
                         int* lpp = labels + width*p.y + p.x;
 
                         if (p.x < width - 1 && !lpp[+1] && dpp[+1] != newVal && abs(dp - dpp[+1]) <= maxDiff)
                         {
                             lpp[+1] = curlabel;
                             Point2s tmp;
                             tmp.x = p.x + 1;
                             tmp.y = p.y;
                             *ws++ = tmp;//Point2s(p.x+1, p.y);
                         }
 
                         if (p.x > 0 && !lpp[-1] && dpp[-1] != newVal && abs(dp - dpp[-1]) <= maxDiff)
                         {
                             lpp[-1] = curlabel;
                             Point2s tmp;
                             tmp.x = p.x - 1;
                             tmp.y = p.y;
                             *ws++ = tmp;//Point2s(p.x-1, p.y);
                         }
 
                         if (p.y < height - 1 && !lpp[+width] && dpp[+dstep] != newVal && abs(dp - dpp[+dstep]) <= maxDiff)
                         {
                             lpp[+width] = curlabel;
                             Point2s tmp;
                             tmp.x = p.x;
                             tmp.y = p.y + 1;
                             *ws++ = tmp;//Point2s(p.x, p.y+1);
                         }
 
                         if (p.y > 0 && !lpp[-width] && dpp[-dstep] != newVal && abs(dp - dpp[-dstep]) <= maxDiff)
                         {
                             lpp[-width] = curlabel;
                             Point2s tmp;
                             tmp.x = p.x;
                             tmp.y = p.y - 1;
                             *ws++ = tmp;//Point2s(p.x, p.y-1);
                         }
 
 
                         p = *--ws;
                     }
 
                     // assign label type
                     if (count <= maxSpeckleSize)    // speckle region
                     {
                         rtype[ls[j]] = 1;    // small region label
                         ds[j] = (short)newVal;
                     }
                     else
                         rtype[ls[j]] = 0;    // large region label
                 }
             }
         }
    }
    printf("End Softfilter!");  
}
#endif


void dbg_softfilter_test_func(char *param)
{  
    int ret = 0;
    uint8_t *pBuffIn = NULL;
    uint8_t *pBuffOut = NULL;
    uint8_t *pTmpbuf = NULL;
    uint32_t size = 0;
    int width = 960; 
    int height = 1280;
    int test_times = 1000000; //测试次数

    int newVal = 0;
    int maxSpeckleSize, maxDiff = 16;

    /*
    shift_540x640.raw
    shift_960x1280.raw
    shift_960x1280_2.raw
    */

    INFO("Enter!\n");
    
    char name_in[]  = "/nfs_share/testdata/shift/shift_960x1280.raw";  
    char name_out[] = "/nfs_share/testdata/shift/shift_960x1280_out.raw";
    FILE *fp = fopen(name_in, "rb");
    if (!fp){
        ERR("open %s fail.\n", name_in);
        goto END;
    }

    fseek(fp, 0, SEEK_END);
    size = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    printf("test in file size:%d\n", size);

    pBuffIn = (uint8_t *)malloc(size);
    if (NULL == pBuffIn){
        ERR("No memory!\n");
        goto END;
    }
    
    pBuffOut = (uint8_t *)malloc(size);
    if (NULL == pBuffOut){
        ERR("No memory!\n");
        goto END;
    }

    ret = fread(pBuffIn, 1, size, fp);
    if (ret < 0){
        ERR("read file failed, ret:%d\n", ret);
        goto END;
    }
    memcpy(pBuffOut, pBuffIn, size);


    //临时buff
    pTmpbuf = (uint8_t*)malloc(9 * sizeof(pTmpbuf) * width * height);
    if (NULL == pTmpbuf){
        ERR("No memory!\n");
        goto END;
    }


    if(width == 1280 || height == 1280)
        maxSpeckleSize = 1920;
    else if(width == 640 || height == 640)
        maxSpeckleSize = 480;
    
    for (int i = 0; i < test_times; i++)
    {
        struct timeval tm1;
        struct timeval tm2;
        long usec1 = 0;
        gettimeofday(&tm1, NULL);

        softfilter((uint8_t *)pTmpbuf, (uint16_t *)pBuffOut, width, height, maxDiff, maxSpeckleSize, newVal);
       
        gettimeofday(&tm2, NULL);
        usec1 = 1000000 * (tm2.tv_sec - tm1.tv_sec) + (tm2.tv_usec - tm1.tv_usec);
        printf("times:%d, cost_time=%ldus\n", i, usec1);

        usleep(22000);

    }

    ob_util_dumpToFile((char *)pBuffOut, size, name_out);

END:
    if (NULL != fp){
        fclose(fp);
        fp = NULL;
    }
    
    if (NULL != pBuffIn){
        free(pBuffIn);
        pBuffIn = NULL;
    }
    
    if (NULL != pBuffOut){
        free(pBuffOut);
        pBuffOut = NULL;
    }


    if (NULL != pTmpbuf){
        free(pTmpbuf);
        pTmpbuf = NULL;
    }


    INFO("Exit!\n");
}

 
/* dbg cmd list*/
static dbg_cmd m_cmd_list[MAX_DBG_CMD_NUM + 1] = {
    {"help",                "0 - help [param]       //debug help info",        dbg_cmd_help_func},
    {"init",                "1 - init               //App Init",               dbg_cmd_init_func},
    {"init",                "2 - cmd test                     ",               dbg_cmd_test_func},
    {"init",                "3 - soft filter test             ",               dbg_softfilter_test_func},
    {"NULL",                "NULL",                                            NULL},
};
 
 
 /*****************************************************************************
 *   Prototype    : dbg_cmd_help_func
 *   Description  : help list
 *   Input        : char *param
 *   Output       : None
 *   Return Value : static void
 *****************************************************************************/
 static void dbg_cmd_help_func(char *param)
 {
     int i = 0;
 
     while (m_cmd_list[i].cmd_func)
     {
         printf("%s\n", m_cmd_list[i].usage);
         i++;
     }
     printf("\n");
 }
 
 
 /*****************************************************************************
 *   Prototype    : dbg_cmd_handle
 *   Description  : dgb cmd process
 *   Input        : void
 *   Output       : None
 *   Return Value : static void
 *****************************************************************************/
 static void dbg_cmd_handle(void)
 {
     int i = 0;
     int num = 0;
     char cmd_info[MAX_DBG_CMD_LEN];
     char *pcmd = NULL;
     char *param = NULL;
     char *nouse;
 
     while (1)
     {
         dbgmsg("");
         memset(cmd_info, 0, sizeof(cmd_info));
 
         /* 命令格式: cmd param1 param2 ... */
         /* 如果输错了可以用Ctrk-Backspace删除字符 */
         nouse = fgets(cmd_info, sizeof(cmd_info), stdin); //阻塞等待输入
         if (strlen(cmd_info) == 1 && cmd_info[0] == '\n')
         {
             continue;   /* 跳过只敲回车键 */
         }
         else if (isdigit(cmd_info[0]))
         {
             /* 如果是数字则表示是序号 */
             num = atoi(cmd_info);
 
             if (num < MAX_DBG_CMD_NUM)
             {
                 if (NULL != m_cmd_list[num].cmd_func)
                 {
                     m_cmd_list[num].cmd_func(NULL);
                 }
             }
             continue;
         }
 
         /* 输入的是字符串
         说明: 命令格式: cmd param1 param2 ...
         比如 "help"     */
         cmd_info[strlen(cmd_info) - 1] = '\0';
         for (i = 0; i < strlen(cmd_info); i++)
         {
             if (cmd_info[i] == ' ' || cmd_info[i] == '\0')
                 break;
         }
 
         if (cmd_info[i] == '\0')
         {
             param = NULL;
             pcmd = cmd_info;
         }
         else if (cmd_info[i] == ' ')
         {
             cmd_info[i] = '\0';
             pcmd =  cmd_info;
             param = &cmd_info[i + 1];
         }
 
         for (i = 0; i < MAX_DBG_CMD_NUM; i++)
         {
             if (m_cmd_list[i].cmd_func == NULL)
                 break;
             if (strcmp(m_cmd_list[i].cmd_name, pcmd) == 0)
                 break;
         }
 
         if (m_cmd_list[i].cmd_func)
         {
             m_cmd_list[i].cmd_func(param);
         }
         else
         {
             dbgmsg("cmd %s not found\n", pcmd);
         }
     }
 }
 
 
 /*****************************************************************************
 *   Prototype    : dbg_console
 *   Description  : 
 *   Input        : void
 *   Output       : None
 *   Return Value : void
 *****************************************************************************/
 void dbg_console(void)
 {
     char *value = NULL;
 
     //export DBG_AR=on
     value = getenv("DBG_AR");
     if (value && (strncmp(value, "on", 2) == 0))
     {
         INFO("DBG_AR is on: enter dbg console.\n");
         dbg_cmd_help_func(NULL);
         dbg_cmd_handle();
     }
 
     WARN("DBG_AR=on is not set, So skip dbg_console.\n");
 }
 
 

