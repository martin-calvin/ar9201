/*****************************************************************************
Copyright: 2016-2020, Artosyn. Co., Ltd.
File name: ar_ipcam_gdbus_wrap.h
Description: define ipcam gdbus api
Author: klbai@artosyn.cn
Version: v1.0
Date:2019-06-03
History:2019-06-03 : first release sdk
*****************************************************************************/
#define ENABALE_ALL_LOG
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ar_log.h"
#include "ar_ipcam_dbus_generated.h"
#include "ar_ipcam_gdbus_wrap.h"
#include "ar_ipcam.h"

#define IPCAM_GDBUS_BUS_NAME                   "com.artosyn.ipcam"
#define IPCAM_GDBUS_OBJECT_PATH                "/com/artosyn/ipcam"
#define IPCAM_GDBUS_INTERFACE                  "com.artosyn.ipcam.interface"


static GVariant *prepare_int_struct_to_variant(int32_t* structure, int32_t size)
{
    GVariant * gdata_ret = NULL;
    GVariantBuilder *builder = NULL;
    builder = g_variant_builder_new(G_VARIANT_TYPE("a(i)"));
    if(!builder){
        log_err("create build failed.");
        return NULL;
    }
    for (int i = 0; i < size; i++) {
        g_variant_builder_add(builder, "(i)", ((int32_t *)structure)[i]);
    }
    gdata_ret = g_variant_new ("a(i)", builder);

    g_variant_builder_unref(builder);
    return gdata_ret;
}
static gboolean ar_ipcam_gdbus_change_resolution(ComArtosynIpcamInterface  *interface_object,
                                                           GDBusMethodInvocation *invocation,
                                                           guint idx,
                                                           guint width,
                                                           guint height,
                                                           gpointer user_data)
{
    gboolean ret = TRUE;
    GVariant *g_status = NULL;
    gint result = 0;
    ar_ipcam_gdbus_obj_t* gdbus_obj = (ar_ipcam_gdbus_obj_t*)user_data;

    if(!user_data) {
        log_err("param is NULL.");
        return FALSE;
    }
    result = ipcam_change_resolution_impl(gdbus_obj->context, idx, width, height);
    if(result)
        return FALSE;
    com_artosyn_ipcam_interface_complete_set_resolution(interface_object, invocation, result);
    return TRUE;
}

static gboolean ar_ipcam_gdbus_change_bitrate(ComArtosynIpcamInterface  *interface_object,
                                                           GDBusMethodInvocation *invocation,
                                                           guint idx,
                                                           guint max_bitrate,
                                                           guint avg_bitrate,
                                                           gpointer user_data)
{
    gboolean ret = TRUE;
    GVariant *g_status = NULL;
    gint result = 0;
    ar_ipcam_gdbus_obj_t* gdbus_obj = (ar_ipcam_gdbus_obj_t*)user_data;

    if(!user_data) {
        log_err("param is NULL.");
        return FALSE;
    }
    result = ipcam_change_bitrate_impl(gdbus_obj->context, idx, max_bitrate, avg_bitrate);
    if(result)
        return FALSE;
    com_artosyn_ipcam_interface_complete_set_bitrate(interface_object, invocation, result);
    return TRUE;
}

static gboolean ar_ipcam_gdbus_change_codec(ComArtosynIpcamInterface  *interface_object,
                                                           GDBusMethodInvocation *invocation,
                                                           guint codec_type,
                                                           gpointer user_data)
{
    gboolean ret = TRUE;
    GVariant *g_status = NULL;
    gint result = 0;
    ar_ipcam_gdbus_obj_t* gdbus_obj = (ar_ipcam_gdbus_obj_t*)user_data;

    if(!user_data) {
        log_err("param is NULL.");
        return FALSE;
    }
    result = ipcam_change_codec_impl(gdbus_obj->context, codec_type);
    if(result)
        return FALSE;
    com_artosyn_ipcam_interface_complete_set_codec(interface_object, invocation, result);
    return TRUE;
}

static gboolean ar_ipcam_gdbus_start_stream(ComArtosynIpcamInterface  *interface_object,
                                                           GDBusMethodInvocation  *invocation,
                                                           gpointer               user_data)
{
    gint ret = 0;
    ar_ipcam_gdbus_obj_t* gdbus_obj = (ar_ipcam_gdbus_obj_t*)user_data;

    if(!user_data) {
        log_err("param is NULL.");
        return FALSE;
    }
    ret = ipcam_start_stream_impl(gdbus_obj->context);
    com_artosyn_ipcam_interface_complete_start_stream(interface_object, invocation, ret);
    if (ret == 0)
        return TRUE;
    else
        return FALSE;
}
static gboolean ar_ipcam_gdbus_stop_stream(ComArtosynIpcamInterface  *interface_object,
                                                           GDBusMethodInvocation  *invocation,
                                                           gpointer               user_data)
{
    gint ret = 0;
    ar_ipcam_gdbus_obj_t* gdbus_obj = (ar_ipcam_gdbus_obj_t*)user_data;

    if(!user_data) {
        log_err("param is NULL.");
        return FALSE;
    }
    ret = ipcam_stop_stream_impl(gdbus_obj->context);
    com_artosyn_ipcam_interface_complete_stop_stream(interface_object, invocation, ret);
    if (ret == 0)
        return TRUE;
    else
        return FALSE;
}

static void ar_ipcam_connect_api_and_signal(ar_ipcam_gdbus_obj_t* gdbus_obj)
{
    if(!gdbus_obj || !gdbus_obj->interface_object) {
        log_err("connect gdbus api failed, param is NULL");
        return;
    }
    g_signal_connect (gdbus_obj->interface_object,
                  "handle-set-resolution",
                  G_CALLBACK (ar_ipcam_gdbus_change_resolution),
                  gdbus_obj);
    g_signal_connect (gdbus_obj->interface_object,
                  "handle-set-bitrate",
                  G_CALLBACK (ar_ipcam_gdbus_change_bitrate),
                  gdbus_obj);
    g_signal_connect (gdbus_obj->interface_object,
                  "handle-set-codec",
                  G_CALLBACK (ar_ipcam_gdbus_change_codec),
                  gdbus_obj);
    g_signal_connect (gdbus_obj->interface_object,
                  "handle-start-stream",
                  G_CALLBACK (ar_ipcam_gdbus_start_stream),
                  gdbus_obj);
    g_signal_connect (gdbus_obj->interface_object,
                  "handle-stop-stream",
                  G_CALLBACK (ar_ipcam_gdbus_stop_stream),
                  gdbus_obj);
}

static void ar_ipcam_handle_bus_acquired(
                                                  GDBusConnection *connection,
                                                  const gchar     *name,
                                                  gpointer        user_data) {
  ar_ipcam_gdbus_obj_t* gdbus_obj = (ar_ipcam_gdbus_obj_t*)user_data;
  GError *error = NULL;

  if (user_data == NULL) {
      log_err("Ipcam acquired a message bus connection, but user data is NULL.");
      return;
  }
  log_info("Ipcam acquired a message bus connection %s.", name);
  // Create a new Dbus ObjectManager
  //gdbus_obj->object_manager = (void*)g_dbus_object_manager_server_new(gdbus_obj->object_path);
  //gdbus_obj->skeleton_object = (void*)object_skeleton_new(gdbus_obj->object_path);
  // Create a new interface
  gdbus_obj->interface_object = (void*)com_artosyn_ipcam_interface_skeleton_new();
  // Connect all the APIs signal
  ar_ipcam_connect_api_and_signal(gdbus_obj);
  /** export interface skeleton **/
  (void) g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(gdbus_obj->interface_object),
                                    connection,
                                    gdbus_obj->object_path,
                                    &error);

    if(error) {
        log_err("Error:Failed to export object.Reason:%s.\n",error->message);
        g_error_free(error);
    }
  return;
}

void ar_ipcam_handle_bus_name_acquired(
                                                  GDBusConnection *connection,
                                                  const gchar     *name,
                                                  gpointer        user_data) {
  log_info("ipcam gdbus acquired the name %s",name);
  return;
}

void ar_ipcam_handle_bus_name_lost(
                                                  GDBusConnection *connection,
                                                  const gchar     *name,
                                                  gpointer        user_data) {
  log_info("ipcam gdbus lost the name %s",name);
  return;
}

static ar_ipcam_gdbus_obj_t* ar_ipcam_gdbus_get_object(void)
{
    static ar_ipcam_gdbus_obj_t* gdbus_obj = NULL;

    if(gdbus_obj) {
        log_info("object has been created");
        return gdbus_obj;
    }
    gdbus_obj = malloc(sizeof(ar_ipcam_gdbus_obj_t));
    if(!gdbus_obj) {
        log_err("malloc ipcam gdbus object failed.");
        return NULL;
    }
    memset(gdbus_obj, 0x0, sizeof(ar_ipcam_gdbus_obj_t));
    gdbus_obj->bus_name = IPCAM_GDBUS_BUS_NAME;
    gdbus_obj->object_path = IPCAM_GDBUS_OBJECT_PATH;
    gdbus_obj->interfaces = IPCAM_GDBUS_INTERFACE;
    gdbus_obj->main_loop = (void*)g_main_loop_new(NULL, FALSE);
    if(!gdbus_obj->main_loop) {
        log_err("malloc ipcam gdbus object failed.");
        goto failed;
    }
    log_info("ipcam gdbus name %s.", gdbus_obj->bus_name);
    gdbus_obj->bus_id = (int32_t)g_bus_own_name (G_BUS_TYPE_SESSION,
                                             gdbus_obj->bus_name,
                                             G_BUS_NAME_OWNER_FLAGS_NONE,
                                             ar_ipcam_handle_bus_acquired,
                                             ar_ipcam_handle_bus_name_acquired,
                                             ar_ipcam_handle_bus_name_lost,
                                             (gpointer)gdbus_obj,
                                             NULL);
    return gdbus_obj;
failed:
    if(gdbus_obj) {
        if(gdbus_obj->main_loop) {
            g_main_loop_unref((GMainLoop*)gdbus_obj->main_loop);
            gdbus_obj->main_loop = NULL;
        }
        free(gdbus_obj);
        gdbus_obj = NULL;
    }
    return NULL;
}
/* dbus api */
ar_ipcam_gdbus_obj_t* ar_ipcam_gdbus_create(void* context)
{
    ar_ipcam_gdbus_obj_t* gdbus_obj = NULL;
    printf("gdbus create in");
    gdbus_obj = ar_ipcam_gdbus_get_object();
    if(!gdbus_obj) {
        log_err("create gdbus failed.");
        return NULL;
    }
    printf("gdbus create out");
    gdbus_obj->context = context;
    return gdbus_obj;
}
void ar_ipcam_gdbus_run(ar_ipcam_gdbus_obj_t* gdbus_obj)
{
    if((!gdbus_obj) || (!gdbus_obj->main_loop))
        return;
    g_main_loop_run(gdbus_obj->main_loop);
    return;
}
void ar_ipcam_gdbus_destroy(ar_ipcam_gdbus_obj_t* gdbus_obj)
{
    return;
}
/* raise event apis */
int32_t ar_ipcam_raise_error_info(int32_t error_code)
{
    ar_ipcam_gdbus_obj_t* gdbus_obj = NULL;

    gdbus_obj = ar_ipcam_gdbus_get_object();
    if((!gdbus_obj) || (!gdbus_obj->interface_object)) {
        log_err("failed to raise video input, gdbus is NULL");
        return AR_FAILURE;
    }
    com_artosyn_ipcam_interface_emit_err_info((ComArtosynIpcamInterface *)gdbus_obj->interface_object,
                                              (guint)error_code);
    return AR_SUCCESS;
}
