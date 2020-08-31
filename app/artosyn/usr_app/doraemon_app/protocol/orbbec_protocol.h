/******************************************************************************
*
*  Copyright (C), 2020-2030, Orbbec Co.,Ltd.
*
*******************************************************************************
*  File Name     : orbbec_protocol.h
*  Version       : Initial Draft
*  Author        : jiangxiaohui
*  Created       : 2020/5/7
*  Last Modified :
*  Description   : orbbec_protocol.cpp header file
*  Function List :
*
*
*  History:
* 
*       1.  Date         : 2020/5/7
*           Author       : jiangxiaohui
*           Modification : Created file
*
******************************************************************************/
#ifndef __ORBBEC_PROTOCOL_H__
#define __ORBBEC_PROTOCOL_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */


/*==============================================*
 *      include header files                    *
 *----------------------------------------------*/
 #include "obshareDataType.h"

/*==============================================*
 *      constants or macros define              *
 *----------------------------------------------*/
//每个控制指令包的最大长度  : Header+data+len
#define MAX_PACKET_SIZE 512

//控制指令包中数据部分的长度: 整包长度减去8字节包头长度和2字节包尾部的len
#define MAX_PACKET_DATA_SIZE (512-8-2) // 502

#define PROTOCOL_REQUEST_MAGIC 0x4d47
#define PROTOCOL_RESPONE_MAGIC 0x4252


/*==============================================*
 *      project-wide global variables           *
 *----------------------------------------------*/
typedef struct _ob_device ob_device;


/*==============================================*
 *      enum definition                         *
 *----------------------------------------------*/


/*==============================================*
 *      structure definition                    *
 *----------------------------------------------*/
/* 
Total Buff lenght: 512Bytes

cmd: host->device
--------------------------------------------------------------------
| header(8Bytes)  | data(502Bytes)                      |Len(2Bytes)|
--------------------------------------------------------------------

ack: device->host
--------------------------------------------------------------------
| header(8Bytes)  | res(2Bytes) |     data(500Bytes)    |Len(2Bytes)|
--------------------------------------------------------------------
*/
typedef struct
{
    uint16_t nMagic;   //发送时SDK填充0x4d47,固件填充0x4252再发出去
    uint16_t nSize;    //lenght(data)/2
    uint16_t nOpcode;  //操作码
    uint16_t nId;      //当前传输的id, 发送出的id与响应的id要保持一致
} ProtocolHeader;

typedef struct
{
    uint16_t res; //ack code, refer FIRMWARE_ACK_CODE_EM
    uint8_t data[MAX_PACKET_DATA_SIZE - 2]; //固件上报给上位机的实际数据部分
} ProtocolResp;

typedef struct __attribute__((__packed__))
{
    union
    {
        uint8_t _data[MAX_PACKET_DATA_SIZE];  //上位机下发的buff
        ProtocolResp resp;                    //固件上报给上位机的buff
    } data;
    uint16_t len;  //数据data长度 + header长度, (缓存中实际使用的byteused长度)
}ProtocolBuf;

typedef struct __attribute__((__packed__))
{
    ProtocolHeader header;
    ProtocolBuf buf;
}ProtocolMsg;



/*==============================================*
 *      routines' or functions' implementations *
 *----------------------------------------------*/
extern int32_t ob_protocol_process(ob_device *dev, const ProtocolMsg *request, ProtocolMsg *response);




#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif /* __ORBBEC_PROTOCOL_H__ */

