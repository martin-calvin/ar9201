/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: ar_ipcam_gdbus_wrap.h
Description: define ipcam gdbus api
Author: klbai@artosyn.cn
Version: v1.0
Date:2019-06-03
History:2019-06-03 : first release sdk
*****************************************************************************/
#ifndef _AR_IPCAM_GDBUS_WRAP_
#define _AR_IPCAM_GDBUS_WRAP_
#ifdef __cplusplus
extern "C" {
#endif
#include "ar_multimedia_base.h"
#include "ar_ipcam_client.h"

typedef struct {
    char* bus_name;
    char* object_path;
    char* interfaces;
    int32_t bus_id;
    void* object_manager;
    void* skeleton_object;
    void* interface_object;
    void* main_loop;
    void* context;
} ar_ipcam_gdbus_obj_t;

/* dbus api */
ar_ipcam_gdbus_obj_t* ar_ipcam_gdbus_create(void* context);
void ar_ipcam_gdbus_run(ar_ipcam_gdbus_obj_t* gdbus_obj);
void ar_ipcam_gdbus_destroy(ar_ipcam_gdbus_obj_t* gdbus_obj);
/* raise event apis */
int32_t ar_ipcam_raise_error_info(int32_t error_code);

#ifdef __cplusplus
}
#endif
#endif // _AR_IPCAM_GDBUS_WRAP_
