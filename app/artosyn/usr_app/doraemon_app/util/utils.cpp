/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : utils.cpp
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/4/24
*  Last Modified :
*  Description   : utils
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
#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/statfs.h> 
#include "utils.h"
#include "dbg.h"
#include "logutil.h"
#include "utils.h"


/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/


/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/


static char *_strdup(const char *s)
{
    char *ptr = NULL;
	
    ptr = strdup(s);
    if(NULL != ptr)
    {
        return ptr;
    }
    else
    {
	return NULL;
    }		
}

//获取执行shell指令后返回的字符串
char *get_shell(char *cmd)
{
    FILE *fp = NULL;
    char *ptr = NULL;
    char *tag = NULL;
    char buf[128] = {0}; 
	
    if(cmd == NULL)
    {
    	return NULL;
    }
	   
    memset(buf,0,sizeof(buf));
    if(NULL != (fp=popen((const char *)cmd,"r")))
    {    
    	if(NULL != fgets(buf,sizeof(buf)-1,fp))
    	{    
    	    tag = buf; 
     
    	    while( ('\n'!= *tag)&&('\0'!=*tag))
    	    {    
    		tag++;
    	    }    
    	    *tag = '\0';
     
    	    ptr = _strdup(buf);
    	}
    	else
    	{
    	    printf("cmd:%s, err\n",cmd);
    	}    
    	pclose(fp);
    	return ptr; 
    }
    else
    {
    	return NULL;
    }
}

//十六进制字符串转十进制整数
int32_t str_to_int(char* str)
{
     int32_t number = 0;
     int32_t cnt = 0,size = 0;
     int32_t data = 0;
     char *string = NULL;

     if(str == NULL)
     {
         return 0;
     }
	
     size = strlen(str);
     string = &str[size -1];
     
     while(*string != 'x'){

         if(*string >= 'a' && *string <= 'f')      //十六进制还要判断他是不是在A-F或者a-f 
	 {
	     data = *string - 'a' + 10;
	 }
         else if(*string >= 'A' && *string <= 'F')  
         {
             data =*string - 'A' + 10;
         }
	 else
	 {
	     data = *string - '0';
	 }

         if(data)
         {
             //printf("data is :%d cnt is :%d\n",data,cnt);
             number += data << cnt * 4;
         }
         //printf("number is :%d\n",number);
          
         string--;
         cnt++;	  
     }
     return number;
}


//将双字节中某一位置位置
void ob_util_set_bit_16(unsigned short *pBuff, int n)
{
    (*pBuff) |= 1 << n;
}

//将双字节中某一位清零
void ob_util_clear_bit_16(unsigned short *pBuff, int n)
{
    (*pBuff) &= ~(1 << n);
}

//获取双字节中某一位的值
int ob_util_get_bit_16(unsigned short buff, int n)
{
    return (buff >> n) & 0x01;
}


//将单字节中某一位置位置
void ob_util_set_bit_8(unsigned char *pBuff, int n)
{
    (*pBuff) |= 1 << n;
}

//将单字节中某一位清零
void ob_util_clear_bit_8(unsigned char *pBuff, int n)
{
    (*pBuff) &= ~(1 << n);
}

//获取单字节中某一位的值
int ob_util_get_bit_8(unsigned char buff, int n)
{
    return (buff >> n) & 0x01;
}


/*****************************************************************************
*   Prototype    : ob_util_dumpToFile
*   Description  : 保存文件
*   Input        : const char *buf
*                  int size
*                  char *filename
*   Output       : None
*   Return Value : static int
*   Calls        :
*   Called By    :
*****************************************************************************/
int ob_util_dumpToFile(const char *buf, int size, char *filename)
{
	FILE *fp = NULL;

	fp = fopen(filename, "wb");
	if (fp == NULL)
	{
		ERR("open %s fail.\n", filename);
		return -errno;
	}

	if(1 != fwrite(buf, size, 1, fp))
	{
		ERR("fwrite failed.\n");
		return -1;
	}

	fflush(fp);

	if(NULL != fp)
	{
		fclose(fp);
	}

	INFO("save file:%s success.\n", filename);

	return 0;
}


int ob_util_force_create_dir(const char *dirname)
{
	int nRet = access(dirname, F_OK);
	if(0 == nRet)
	{
		//printf("dirname:%s is exisits\n", dirname);
	}

    nRet = mkdir(dirname, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);

	return 0;
} 


unsigned int ob_util_get_remaining_capacity_MB(const char *dirname)
{
	struct statfs diskInfo;
    memset(&diskInfo, 0, sizeof(diskInfo));

	if (statfs(dirname, &diskInfo) == -1)
	{
		ERR("Get %s information failed\n", dirname);
		return 0;
	}

	/* 可用空间大小(单位: MB) = (可用块个数 * 每块大小(单位: B => KB))(单位: KB => MB)) */
	return (unsigned int)((diskInfo.f_bfree * (diskInfo.f_bsize >> 10)) >> 10);
}


/*****************************************************************************
*   Prototype    : start_new_thread
*   Description  : new thread
*   Input        : const char *pThdName
*                  pthread_t *pThdId
*                  THREAD_FUNC pThdFunc
*                  void *arg
*   Output       : None
*   Return Value : int
*****************************************************************************/
int start_new_thread(const char *pThdName, pthread_t *pThdId, THREAD_FUNC pThdFunc, void *arg)
{
	pthread_t thdThreadId;

	int iRet = pthread_create(&thdThreadId, NULL, pThdFunc, arg);
	if (iRet)
	{
		ERR("Create thread: %s failed, Error no: %d(%s)\n", pThdName, errno, strerror(errno));
		return errno;
	}
	//PRT("Create thread: %s succeed, ID: %X\n", pThdName, thdThreadId);

	pthread_detach(thdThreadId);

	if (NULL != pThdId)
		*pThdId = thdThreadId;

	return iRet;
}


/*****************************************************************************
*   Prototype    : start_new_thread_join
*   Description  : 创建一个线程, 使用join回收线程
*   Input        : const char *pThdName
*                  pthread_t *pThdId
*                  THREAD_FUNC pThdFunc
*                  void *arg
*   Output       : None
*   Return Value : int
*****************************************************************************/
int start_new_thread_join(const char *pThdName, pthread_t *pThdId, THREAD_FUNC pThdFunc, void *arg)
{
	pthread_t thdThreadId;

	int iRet = pthread_create(&thdThreadId, NULL, pThdFunc, arg);
	if (iRet)
	{
		ERR("Create thread: %s failed, Error no: %d(%s)\n", pThdName, errno, strerror(errno));
		return errno;
	}
	//PRT("Create thread: %s succeed, ID: %X\n", pThdName, thdThreadId);

	if (pThdId)
		*pThdId = thdThreadId;

	return iRet;
}


/*****************************************************************************
*   Prototype    : start_new_thread_ext
*   Description  : create thread ext
*   Input        : const char *pThdName  
*                  pthread_t *pThdId     
*                  THREAD_FUNC pThdFunc  
*                  void *arg             
*                  bool flag: true:thread detach, flase:thread wait to jion
*                  int priority: 优先级 1-99
*   Output       : None
*   Return Value : int
*****************************************************************************/
int start_new_thread_ext(const char *pThdName, pthread_t *pThdId, THREAD_FUNC pThdFunc, void *arg, bool flag, int priority)
{
	pthread_t thdThreadId;
    pthread_attr_t thread_attr;
    struct sched_param schedule_param; 
    
    if (pthread_attr_init(&thread_attr)){
        ERR("pthread_attr_init failed!\n");
        return -1;
    }

    //优先级 1-99
    schedule_param.sched_priority = priority; 
    pthread_attr_setinheritsched(&thread_attr, PTHREAD_EXPLICIT_SCHED);
    pthread_attr_setschedpolicy(&thread_attr,SCHED_RR);
    pthread_attr_setschedparam(&thread_attr, &schedule_param);

	int iRet = pthread_create(&thdThreadId, &thread_attr, pThdFunc, arg);
	if (iRet){
		ERR("Create thread: %s failed, Error no: %d(%s)\n", pThdName, errno, strerror(errno));
		return errno;
	}
	//PRT("Create thread: %s succeed, ID: %X\n", pThdName, thdThreadId);

    if (flag)
        pthread_detach(thdThreadId);

	if (NULL != pThdId)
		*pThdId = thdThreadId;


    if (pthread_attr_destroy(&thread_attr)){
        ERR("pthread_attr_destroy failed!\n");
        return -1;
    }

	return iRet;
}


