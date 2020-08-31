#ifdef ENABLE_SWEEPER_OPTION

#include <stdlib.h>
#define GLIB_VERSION_MIN_REQUIRED GLIB_VERSION_2_50
#include <glib-2.0/glib.h>
#include "libar_sweeper_gdbus.h"
#include "ar_alg_define.h"
#include "ar_dsp_alg.h"
#include "ar_dsp_common.h"

static GMainLoop *g_mainloop = NULL;
static guint g_gdbus_own_name;
const  gchar* g_node_name;

typedef enum
{
    GDBUS_DATA_TYPE_BYTE = 0,
    GDBUS_DATA_TYPE_BOOLEAN,
    GDBUS_DATA_TYPE_INT16,
    GDBUS_DATA_TYPE_UINT16,
    GDBUS_DATA_TYPE_INT32,
    GDBUS_DATA_TYPE_UINT32,
    GDBUS_DATA_TYPE_INT64,
    GDBUS_DATA_TYPE_UINT64,
    GDBUS_DATA_TYPE_DOUBLE,
    GDBUS_DATA_TYPE_STRING,
    GDBUS_DATA_TYPE_OBJECT_PATH,
    GDBUS_DATA_TYPE_UNIX_FD,
    GDBUS_DATA_TYPE_SIGNATURE
} enum_gdbus_data_type;

gboolean deinit_gdbus_server(void);
GVariant* variant_prepare(enum_gdbus_data_type data_type, void* data_array, unsigned int data_size);
unsigned int variant_retreive(enum_gdbus_data_type data_type, GVariant * gdata_input, void * data_array, unsigned int data_max_size);

// user specific -----------------------------------------------------------------------

#define GDBUS_BUS_NODE_NAME                 "/com/artosyn/module/arsweepergdbus"
#define GDBUS_BUS_INTERFACE_NAME            "com.artosyn.module.ar_dsp_alg.interface"
#define GDBUS_CONNECT_TO_GIVEN_BUS          com_artosyn_module_ar_dsp_alg_interface_proxy_new_sync
#define GDBUS_GET_CONNECT_FROM_GIVEN_BUS    com_artosyn_module_ar_dsp_alg_interface_skeleton_new
#define GDBUS_CALLBACK_OBJECT               ComArtosynModuleAr_dsp_algInterface
#define GDBUS_COMPLETE_CLIENT_REQUEST_GET_DETECT_RESULTS       com_artosyn_module_ar_dsp_alg_interface_complete_ar_get_detect_results

//#define GDBUS_EMIT_BROADCAST_ROBOT_INFO_MESSAGE           com_artosyn_module_ar_sweeper_data_center_interface_emit_broadcast_robot_info_msg

static GDBUS_CALLBACK_OBJECT *g_proxy = NULL;
static GDBUS_CALLBACK_OBJECT *g_skeleton = NULL;

/** specific callback is added here **/

static gboolean ar_get_detect_results_callback(GDBUS_CALLBACK_OBJECT *object,
                                        GDBusMethodInvocation *invocation,
                                        GVariant *arg_output_array,
                                        guint arg_output_size)
{
    //g_print("enter %s =====> \n", __FUNCTION__);

    /** output array **/
    GVariant * output_data = NULL;
    int output_size = 0;
    AR_ALG_OBSTACLE_st obstacle_info = {0};

	//g_print("%s %d\n", __FUNCTION__, __LINE__);
    ar_get_detect_results(&obstacle_info);

	//g_print("%s %d\n", __FUNCTION__, __LINE__);

    output_data = variant_prepare(GDBUS_DATA_TYPE_INT32, &obstacle_info, sizeof(obstacle_info)/sizeof(int));
	//g_print("%s %d\n", __FUNCTION__, __LINE__);

    if(output_data)
    {
        GDBUS_COMPLETE_CLIENT_REQUEST_GET_DETECT_RESULTS(object, invocation, output_data, sizeof(obstacle_info)/sizeof(int), 1);
    }

    //g_print("exit %s <===== \n", __FUNCTION__);

    return TRUE;
}

// lib test ----------------------------------------------------------------------------

GVariant* variant_prepare(enum_gdbus_data_type data_type, void* data_array, unsigned int data_size)
{
    GVariant * gdata_ret = NULL;
    GVariantBuilder *builder;

    if (data_array == NULL)
    {
        return NULL;
    }

    switch (data_type)
    {
    case GDBUS_DATA_TYPE_BYTE:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(y)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(y)", ((guchar *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(y)", builder);
        break;
    case GDBUS_DATA_TYPE_BOOLEAN:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(b)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(b)", ((gboolean *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(b)", builder);
        break;
    case GDBUS_DATA_TYPE_INT16:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(n)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(n)", ((gint16 *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(n)", builder);
        break;
    case GDBUS_DATA_TYPE_UINT16:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(q)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(q)", ((guint16 *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(q)", builder);
        break;
    case GDBUS_DATA_TYPE_INT32:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(i)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(i)", ((gint *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(i)", builder);
        break;
    case GDBUS_DATA_TYPE_UINT32:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(u)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(u)", ((guint *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(u)", builder);
        break;
    case GDBUS_DATA_TYPE_INT64:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(x)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(x)", ((gint64 *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(x)", builder);
        break;
    case GDBUS_DATA_TYPE_UINT64:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(t)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(t)", ((guint64 *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(t)", builder);
        break;
    case GDBUS_DATA_TYPE_DOUBLE:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(d)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(d)", ((gdouble *)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(d)", builder);
        break;
    case GDBUS_DATA_TYPE_STRING:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(s)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(s)", ((const gchar **)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(s)", builder);
        break;
    case GDBUS_DATA_TYPE_OBJECT_PATH:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(o)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(o)", ((const gchar **)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(o)", builder);
        break;
    case GDBUS_DATA_TYPE_UNIX_FD:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(h)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(h)", ((GVariant **)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(h)", builder);
        break;
    case GDBUS_DATA_TYPE_SIGNATURE:
        builder = g_variant_builder_new(G_VARIANT_TYPE("a(g)"));
        for (int i = 0; i < data_size; i++)
        {
            g_variant_builder_add(builder, "(g)", ((const gchar **)data_array)[i]);
        }
        gdata_ret = g_variant_new ("a(g)", builder);
        break;
    default:
        g_print("error: variant type unknown\n");
        return NULL;
    }

    g_variant_builder_unref (builder);

    return gdata_ret;
}

unsigned int variant_retreive(enum_gdbus_data_type data_type, GVariant * gdata_input, void * data_array, unsigned int data_max_size)
{
    GVariantIter *iter;
    gint ivalue;
    unsigned int icount = 0;

    if (gdata_input == NULL || data_array == NULL || data_max_size == 0)
        return 0;

    switch (data_type)
    {
    case GDBUS_DATA_TYPE_BYTE:
        g_variant_get(gdata_input, "a(y)", &iter);
        while (g_variant_iter_loop (iter, "(y)", &ivalue) && (icount < data_max_size))
        {
            ((guchar *)data_array)[icount++] = (guchar)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_BOOLEAN:
        g_variant_get(gdata_input, "a(b)", &iter);
        while (g_variant_iter_loop (iter, "(b)", &ivalue) && (icount < data_max_size))
        {
            ((gboolean *)data_array)[icount++] = (gboolean)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_INT16:
        g_variant_get(gdata_input, "a(n)", &iter);
        while (g_variant_iter_loop (iter, "(n)", &ivalue) && (icount < data_max_size))
        {
            ((gint16 *)data_array)[icount++] = (gint16)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_UINT16:
        g_variant_get(gdata_input, "a(q)", &iter);
        while (g_variant_iter_loop (iter, "(q)", &ivalue) && (icount < data_max_size))
        {
            ((guint16 *)data_array)[icount++] = (guint16)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_INT32:
        g_variant_get(gdata_input, "a(i)", &iter);
        while (g_variant_iter_loop (iter, "(i)", &ivalue) && (icount < data_max_size))
        {
            ((gint *)data_array)[icount++] = (gint)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_UINT32:
        g_variant_get(gdata_input, "a(u)", &iter);
        while (g_variant_iter_loop (iter, "(u)", &ivalue) && (icount < data_max_size))
        {
            ((guint *)data_array)[icount++] = (guint)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_INT64:
        g_variant_get(gdata_input, "a(x)", &iter);
        while (g_variant_iter_loop (iter, "(x)", &ivalue) && (icount < data_max_size))
        {
            ((gint64 *)data_array)[icount++] = (gint64)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_UINT64:
        g_variant_get(gdata_input, "a(t)", &iter);
        while (g_variant_iter_loop (iter, "(t)", &ivalue) && (icount < data_max_size))
        {
            ((guint64 *)data_array)[icount++] = (guint64)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_DOUBLE:
        g_variant_get(gdata_input, "a(d)", &iter);
        while (g_variant_iter_loop (iter, "(d)", &ivalue) && (icount < data_max_size))
        {
            ((gdouble *)data_array)[icount++] = (gdouble)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_STRING:
        g_variant_get(gdata_input, "a(s)", &iter);
        while (g_variant_iter_loop (iter, "(s)", &ivalue) && (icount < data_max_size))
        {
            ((const gchar **)data_array)[icount++] = (const gchar *)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_OBJECT_PATH:
        g_variant_get(gdata_input, "a(o)", &iter);
        while (g_variant_iter_loop (iter, "(o)", &ivalue) && (icount < data_max_size))
        {
            ((const gchar **)data_array)[icount++] = (const gchar *)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_UNIX_FD:
        g_variant_get(gdata_input, "a(h)", &iter);
        while (g_variant_iter_loop (iter, "(h)", &ivalue) && (icount < data_max_size))
        {
            ((GVariant **)data_array)[icount++] = (GVariant *)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    case GDBUS_DATA_TYPE_SIGNATURE:
        g_variant_get(gdata_input, "a(g)", &iter);
        while (g_variant_iter_loop (iter, "(g)", &ivalue) && (icount < data_max_size))
        {
            ((const gchar **)data_array)[icount++] = (const gchar *)ivalue;
        }
        g_variant_iter_free (iter);
        break;
    default:
        g_print("error: variant type unknown\n");
        return -1;
    }

    return icount;
}

static void bus_acquired_cb(GDBusConnection *connection,
                            const gchar     *bus_name,
                            gpointer         user_data)
{
    GError *pError = NULL;

    g_print("enter bus_acquired_cb =====> \n");

    /** try to get a connection from the given bus **/
    g_skeleton = GDBUS_GET_CONNECT_FROM_GIVEN_BUS();

    /** attach to dbus signals. if more methods are needed, please add callback here. **/
    (void) g_signal_connect(g_skeleton, "handle-ar-get-detect-results", G_CALLBACK(ar_get_detect_results_callback), NULL);

    /** export interface skeleton **/
    (void) g_dbus_interface_skeleton_export(G_DBUS_INTERFACE_SKELETON(g_skeleton),
                                            connection,
                                            g_node_name,
                                            &pError);
    if(pError != NULL)
    {
        g_error_free(pError);
        g_main_loop_quit(g_mainloop);
    }

    g_print("exit bus_acquired_cb <===== \n");
}

static void name_acquired_cb(GDBusConnection *connection,
                                     const gchar     *bus_name,
                                     gpointer         user_data)
{
    g_print("enter name_acquired_cb =====> \n");

    g_print("exit name_acquired_cb <===== \n");
}

static void name_lost_cb(GDBusConnection *connection,
                         const gchar     *bus_name,
                         gpointer         user_data)
{
    g_print("enter name_lost_cb =====> \n");

    if(connection == NULL)
    {
        g_print("name_lost_cb call, Error: Failed to connect to dbus.\n");
    }
    else
    {
        ;
    }
    deinit_gdbus_server();

    g_print("exit name_lost_cb <===== \n");
}

/** init the gdbus server **/
static gboolean init_gdbus_server(const gchar* node_name, const gchar* interface_name)
{
    gboolean bRet = TRUE;

    GError *pConnError = NULL;
    GError *pProxyError = NULL;
    GDBusConnection *pConnection = NULL;

    /** create main loop, but do not start it here. **/
    g_mainloop = g_main_loop_new(NULL, FALSE);

    /** connect to dbus **/
    g_gdbus_own_name = g_bus_own_name(G_BUS_TYPE_SESSION, //session type
                                      interface_name, //own gdbus bus name
                                      G_BUS_NAME_OWNER_FLAGS_NONE,
                                      &bus_acquired_cb,
                                      &name_acquired_cb,
                                      &name_lost_cb,
                                      NULL,
                                      NULL);

    pConnection = g_bus_get_sync(G_BUS_TYPE_SESSION, NULL, &pConnError);

    if (NULL == pConnError)
    {
        /** try to get a connection to the given bus **/
        g_proxy = GDBUS_CONNECT_TO_GIVEN_BUS(
                    pConnection,
                    G_DBUS_PROXY_FLAGS_NONE,
                    interface_name,
                    node_name,
                    NULL,
                    &pProxyError);

        if (NULL == pProxyError)
        {
            g_node_name = node_name;
        }
        else
        {
            g_error_free(pProxyError);
            bRet = FALSE;
        }
    }
    else
    {
        g_error_free(pConnError);
        bRet = FALSE;
    }

    return bRet;
}

gboolean deinit_gdbus_server(void)
{
    gboolean bRet = FALSE;

    if(NULL != g_mainloop)
    {
        /** quit the main loop **/
        g_main_loop_quit(g_mainloop);
        g_main_loop_unref(g_mainloop);
        g_mainloop = NULL;

        /** disconnect to dbus **/
        g_bus_unown_name(g_gdbus_own_name);

        usleep(10000); // wait for glib recycle its resources.

        /** close the proxy **/
        if(g_proxy)
        {
            g_object_unref(g_proxy);
            g_proxy = NULL;
        }

        bRet = TRUE;
    }

    return bRet;
}

// -------------------------------------------------------------------------------------
extern pthread_t gdbus_thread;
static void * run_gdbus_loop(void * args)
{
	if(NULL != g_mainloop)
	{
		g_print("run main loop\n");
		g_main_loop_run(g_mainloop);
	}
}

int start_gdbus_server(void)
{
    gboolean bret;

	pthread_attr_t attr = {0};

    g_print("create gdbus server\n");

    if(!init_gdbus_server(GDBUS_BUS_NODE_NAME, GDBUS_BUS_INTERFACE_NAME))
    {
        return -1;
    }

	pthread_attr_init(&attr);
	if(0 != pthread_create(&gdbus_thread, &attr, run_gdbus_loop, NULL))
	{
		g_print("Create gdbus thread failed!\n");
		return -1;
	}
    //g_timeout_add(1000, timer_process, NULL);

    return 0;
}
int stop_gdbus_server(void)
{
    g_print("delete gdbus server\n");
    deinit_gdbus_server();

	return 0;
}

#endif //ENABLE_SWEEPER_OPTION
