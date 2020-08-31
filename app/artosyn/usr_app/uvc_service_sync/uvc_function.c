#define ENABALE_ALL_LOG

#include "ar_meta_define.h"
#include "ar_multimedia_base.h"

#include "uvc_function.h"
#include "uvc_configfs.h"
#include "pipeline_service.h"

static int uvc_video_stream(uvc_server_t *server_l, struct uvc_device *dev, int enable)
{
    struct v4l2_buffer buf;
    unsigned int i;
    int type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    int ret = 0;

    if (!enable) {
        log_info("Stopping video stream.\n");
        ioctl(dev->fd, VIDIOC_STREAMOFF, &type);
        server_l->g_stream_on = 0;
        return 0;
    }

    log_info("Starting video stream.\n");

    for (i = 0; i < dev->nbufs; ++i) {
        memset(&buf, 0, sizeof buf);

        buf.index = i;
        buf.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
        buf.memory = V4L2_MEMORY_USERPTR;//V4L2_MEMORY_MMAP;

        buf.length = MAX_BUFFER_SIZE;
        //memcpy(dev->mem[buf.index], first_image_data, first_image_size);
        buf.bytesused = server_l->first_image_size;
        buf.m.userptr = (uint32_t)server_l->first_image_data;

        //uvc_video_fill_buffer(dev, &buf);

        log_info("Queueing buffer %u.\n", i);
        if ((ret = ioctl(dev->fd, VIDIOC_QBUF, &buf)) < 0) {
            log_err("Unable to queue buffer: %s (%d).\n",
                strerror(errno), errno);
            break;
        }
    }

    ioctl(dev->fd, VIDIOC_STREAMON, &type);
    server_l->g_stream_on = 1;
    return ret;
}

static int uvc_video_reqbufs(uvc_server_t *server_l, struct uvc_device *dev, int nbufs)
{
    struct v4l2_requestbuffers rb;
    int ret;

    //for (i = 0; i < dev->nbufs; ++i)
    //    munmap(dev->mem[i], dev->bufsize);

    //free(dev->mem);
    //dev->mem = 0;
    dev->nbufs = 0;

    memset(&rb, 0, sizeof rb);
    rb.count = nbufs;
    rb.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    rb.memory = V4L2_MEMORY_USERPTR;//V4L2_MEMORY_MMAP;

    ret = ioctl(dev->fd, VIDIOC_REQBUFS, &rb);
    if (ret < 0) {
        printf("Unable to allocate buffers: %s (%d).\n",
            strerror(errno), errno);
        return ret;
    }

    log_info("%u buffers allocated.\n", rb.count);
    dev->nbufs = rb.count;

    return 0;
}

static void uvc_events_process_standard(uvc_server_t *server_l, struct uvc_device *dev, struct usb_ctrlrequest *ctrl,
                struct uvc_request_data *resp)
{
    log_info("pid %d standard request\n", getpid());
    (void)dev;
    (void)ctrl;
    (void)resp;
}

static void uvc_events_process_control(uvc_server_t *server_l, struct uvc_device *dev, uint8_t req, uint8_t cs, uint8_t entity_id,  uint8_t len,
               struct uvc_request_data *resp)
{
    //log_info("pid %d control request (req %02x cs %02x en %02x len %02x)\n", getpid(), req, cs, entity_id, len);
    dev->cs = cs;
    dev->entity_id = entity_id;
    basic_3a_info_t info;
    unsigned int * p;
    unsigned short * p_s;

    switch (entity_id) {
    case 0:
        switch (cs) {
        case UVC_VC_REQUEST_ERROR_CODE_CONTROL:
            /* Send the request error code last prepared. */
            resp->data[0] = dev->request_error_code.data[0];
            resp->length = dev->request_error_code.length;
            break;

        default:
            /*
             * If we were not supposed to handle this
             * 'cs', prepare an error code response.
             */
            dev->request_error_code.data[0] = 0x06;
            dev->request_error_code.length = 1;
            break;
        }
        break;

    /* Camera terminal unit 'UVC_VC_INPUT_TERMINAL'. */
    case 1:
        switch (cs) {
#if 0
    case UVC_CT_SCANNING_MODE_CONTROL:
            switch (req) {
                case UVC_SET_CUR:
                    resp->data[0] = 0x01;
                    resp->length = len;
                    /*
                     * For every successfully handled control
                     * request set the request error code to no
                     * error.
                     */
                    dev->request_error_code.data[0] = 0x00;
                    dev->request_error_code.length = 1;

                case UVC_GET_CUR:
                    resp->data[0] = 0x01;
                    resp->length = 1;

                    dev->request_error_code.data[0] = 0x00;
                    dev->request_error_code.length = 1;
                    break;

                case UVC_GET_INFO:
                    resp->data[0] = 0x03;
                    resp->length = 1;
                    /*
                     * For every successfully handled control
                     * request set the request error code to no
                     * error.
                     */
                    dev->request_error_code.data[0] = 0x00;
                    dev->request_error_code.length = 1;
                    break;

                default:

                    resp->length = -EL2HLT;

                    dev->request_error_code.data[0] = 0x07;
                    dev->request_error_code.length = 1;
                    break;
            }
            break;
#endif
        /*
         * We support only 'UVC_CT_AE_MODE_CONTROL' for CAMERA
         * terminal, as our bmControls[0] = 2 for CT. Also we
         * support only auto exposure.
         */
        case UVC_CT_AE_MODE_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                /* Incase of auto exposure, attempts to
                 * programmatically set the auto-adjusted
                 * controls are ignored.
                 */
                resp->data[0] = 0x01;
                resp->length = len;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_INFO:
                /*
                 * TODO: We support Set and Get requests, but
                 * don't support async updates on an video
                 * status (interrupt) endpoint as of
                 * now.
                 */
                resp->data[0] = 0x03;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_CUR:
                resp->length = 1;
                memcpy(&resp->data[0], &dev->camera_terminal.auto_exposure_mode_control, resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_DEF:
                resp->data[0] = CT_AUTO_EXPOSURE_MODE_DEFAULF_VAL;//0x02;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_RES:
                /* Auto Mode and auto Exposure Time, auto Iris. */
                resp->data[0] = CT_AUTO_EXPOSURE_MODE_RES;//0x02;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            default:
                /*
                 * We don't support this control, so STALL the
                 * control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * value.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_CT_EXPOSURE_TIME_ABSOLUTE_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_MIN:
                p = (unsigned int *)resp->data;
                *p = CT_EXPOSURE_TIME_ABSOLUTE_MIN_VAL;
                resp->length = 4;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_MAX:
                p = (unsigned int *)resp->data;
                *p = CT_EXPOSURE_TIME_ABSOLUTE_MAX_VAL;
                resp->length = 4;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_CUR:
                resp->length = 4;

                if(CT_AUTO_EXPOSURE_MODE_AUTO_MODE == dev->camera_terminal.auto_exposure_mode_control)
                {
                    while(*(server_l->run_flag) && (server_l->status <= UVC_STATUS_INIT || server_l->status >= UVC_STATUS_EXIT))
                    {
                        usleep(1000);
                    }

                    ar_cam_get_3a_info(dev->camera_fd, &info);
                    dev->camera_terminal.auto_exposure_aec_info = info.aec_info;
                    dev->camera_terminal.exposure_time_absolute_val = dev->camera_terminal.auto_exposure_aec_info.exp_time_us * 10000;
                    /*printf("exposure_time_absolute_val: %u %f %f\n",
                           dev->camera_terminal.exposure_time_absolute_val,
                           dev->camera_terminal.auto_exposure_aec_info.exp_time_us,
                           dev->camera_terminal.auto_exposure_aec_info.gain);*/
                }
                memcpy(&resp->data[0], &dev->camera_terminal.exposure_time_absolute_val, resp->length);

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_DEF:
                p = (unsigned int *)resp->data;
                //ar_cam_get_3a_info(dev->camera_fd, &info);
                //dev->camera_terminal.auto_exposure_aec_info = info.aec_info;
                *p = dev->camera_terminal.auto_exposure_aec_info.exp_time_us * 10000;
                resp->length = 4;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_RES:
                resp->data[0] = CT_EXPOSURE_TIME_ABSOLUTE_STEP_SIZE;
                resp->length = len;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            default:
                /*
                 * We don't support this control, so STALL the
                 * control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * value.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;
#if 0
        case UVC_CT_IRIS_ABSOLUTE_CONTROL:
            switch (req) {
            case UVC_GET_INFO:
            case UVC_GET_CUR:
            case UVC_GET_MIN:
            case UVC_GET_MAX:
            case UVC_GET_DEF:
            case UVC_GET_RES:
                resp->data[0] = 10;
                resp->length = len;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                /*
                 * We don't support this control, so STALL the
                 * control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * value.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
            }
            break;
#endif

        case UVC_CT_ZOOM_ABSOLUTE_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->camera_terminal.zoom_absolute_val, resp->length);

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_MIN:
                resp->data[0] = CT_ZOOM_ABSOLUTE_MIN_VAL;// ZOOM_ABSOLUTE val is unsigned short, but the MAX value is 200, so only use low byte
                resp->length = 2;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_MAX:
                resp->data[0] = CT_ZOOM_ABSOLUTE_MAX_VAL;
                resp->length = 2;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_DEF:
                resp->data[0] = CT_ZOOM_ABSOLUTE_DEFAULT_VAL;
                resp->length = 2;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_RES:
                resp->data[0] = CT_ZOOM_ABSOLUTE_STEP_SIZE;
                resp->length = 2;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            default:
                /*
                 * We don't support this control, so STALL the
                 * control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * value.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;

                break;
            }
            break;

        case UVC_CT_ROLL_ABSOLUTE_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->camera_terminal.roll_absolute_val, resp->length);

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;


            case UVC_GET_MIN:
                resp->data[0] = CT_ROLL_ABSOLUTE_MIN_VAL;
                resp->length = 2;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_MAX:
                resp->data[0] = CT_ROLL_ABSOLUTE_MAX_VAL;
                resp->length = 2;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_DEF:
                resp->data[0] = CT_ROLL_ABSOLUTE_DEFAULT_VAL;
                resp->length = 2;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_RES:
                resp->data[0] = CT_ROLL_ABSOLUTE_STEP_SIZE;
                resp->length = 2;

                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            default:
                /*
                 * We don't support this control, so STALL the
                 * control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * value.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;

                break;
            }
            break;

        default:
            /*
             * We don't support this control, so STALL the control
             * ep.
             */
            resp->length = -EL2HLT;
            /*
             * If we were not supposed to handle this
             * 'cs', prepare a Request Error Code response.
             */
            dev->request_error_code.data[0] = 0x06;
            dev->request_error_code.length = 1;
            break;
        }
        break;

    /* processing unit 'UVC_VC_PROCESSING_UNIT' */
    case 2:
        switch (cs) {
        /*
         * We support only 'UVC_PU_BRIGHTNESS_CONTROL' for Processing
         * Unit, as our bmControls[0] = 1 for PU.
         */
        case UVC_PU_BRIGHTNESS_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_BRIGHTNESS_MIN_VAL;
                resp->length = 2;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_BRIGHTNESS_MAX_VAL;
                resp->length = 2;
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->processing_unit.brightness_val, resp->length);
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                /*
                 * We support Set and Get requests and don't
                 * support async updates on an interrupt endpt
                 */
                resp->data[0] = 0x03;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_BRIGHTNESS_DEFAULT_VAL;
                resp->length = 2;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_BRIGHTNESS_STEP_SIZE;
                resp->length = 2;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                /*
                 * We don't support this control, so STALL the
                 * default control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * code.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_PU_CONTRAST_CONTROL:

            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_CONTRAST_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_CONTRAST_MAX_VAL % 256;
                resp->data[1] = PU_CONTRAST_MAX_VAL / 256;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->processing_unit.contrast_val,
                       resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_CONTRAST_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_CONTRAST_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_PU_HUE_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_HUE_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_HUE_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->processing_unit.hue_val,
                       resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_HUE_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_HUE_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_PU_SATURATION_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_SATURATION_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_SATURATION_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->processing_unit.saturation_val,
                       resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_SATURATION_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_SATURATION_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_PU_SHARPNESS_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_SHARPNESS_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_SHARPNESS_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->processing_unit.sharpness_val,
                       resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_SHARPNESS_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_SHARPNESS_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MIN:
                p_s = (unsigned short *)resp->data;
                *p_s = PU_WHITE_BALANCE_TEMPERATURE_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                p_s = (unsigned short *)resp->data;
                *p_s = PU_WHITE_BALANCE_TEMPERATURE_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->processing_unit.white_balance_temperature_val,
                       resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                p_s = (unsigned short *)resp->data;
                *p_s = PU_WHITE_BALANCE_TEMPERATURE_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                p_s = (unsigned short *)resp->data;
                *p_s = PU_WHITE_BALANCE_TEMPERATURE_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_PU_BACKLIGHT_COMPENSATION_CONTROL:

            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MIN:
                resp->data[0] = PU_BACKLIGHT_COMPENSATION_MIN_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_MAX:
                resp->data[0] = PU_BACKLIGHT_COMPENSATION_MAX_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->processing_unit.backlight_compensation_val,
                       resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_BACKLIGHT_COMPENSATION_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_RES:
                resp->data[0] = PU_BACKLIGHT_COMPENSATION_STEP_SIZE;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;


        case UVC_PU_POWER_LINE_FREQUENCY_CONTROL:

            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                /*
                * For every successfully handled control
                * request set the request error code to no
                * error
                */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;

            case UVC_GET_CUR:
                resp->length = 1;
                memcpy(&resp->data[0], &dev->processing_unit.power_line_frequency_val, resp->length);
                /*
                 * For every successfully handled control
                 * request set the request error code to no
                 * error
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_INFO:
                /*
                 * We support Set and Get requests and don't
                 * support async updates on an interrupt endpt
                 */
                resp->data[0] = 0x03;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            case UVC_GET_DEF:
                resp->data[0] = PU_POWER_LINE_FREQUENCY_DEFAULT_VAL;
                resp->length = 1;
                /*
                 * For every successfully handled control
                 * request, set the request error code to no
                 * error.
                 */
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;

            default:
                /*
                 * We don't support this control, so STALL the
                 * default control ep.
                 */
                resp->length = -EL2HLT;
                /*
                 * For every unsupported control request
                 * set the request error code to appropriate
                 * code.
                 */
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_PU_HUE_AUTO_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 2;
                memcpy(&resp->data[0], &dev->processing_unit.hue_auto_val,
                       resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = PU_HUE_AUTO_DEFAULT_VAL;
                resp->length = 2;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        case UVC_PU_WHITE_BALANCE_TEMPERATURE_AUTO_CONTROL:
            switch (req) {
            case UVC_SET_CUR:
                resp->data[0] = 0x0;
                resp->length = len;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_CUR:
                resp->length = 1;
                memcpy(&resp->data[0], &dev->processing_unit.white_balance_temperature_auto_val,
                       resp->length);
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_INFO:
                resp->data[0] = 0x03;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            case UVC_GET_DEF:
                resp->data[0] = WHITE_BALANCE_TEMPERATURE_AUTO_DEFAULT_VAL;
                resp->length = 1;
                dev->request_error_code.data[0] = 0x00;
                dev->request_error_code.length = 1;
                break;
            default:
                resp->length = -EL2HLT;
                dev->request_error_code.data[0] = 0x07;
                dev->request_error_code.length = 1;
                break;
            }
            break;

        default:
            /*
             * We don't support this control, so STALL the control
             * ep.
             */
            resp->length = -EL2HLT;
            /*
             * If we were not supposed to handle this
             * 'cs', prepare a Request Error Code response.
             */
            dev->request_error_code.data[0] = 0x06;
            dev->request_error_code.length = 1;
            break;
        }

        break;

    default:
        /*
         * If we were not supposed to handle this
         * 'cs', prepare a Request Error Code response.
         */
        dev->request_error_code.data[0] = 0x06;
        dev->request_error_code.length = 1;
        break;
    }
}

static void uvc_fill_streaming_control(uvc_server_t *server_l, struct uvc_device *dev,
              struct uvc_streaming_control *ctrl,
              int iframe, int iformat)
{
    struct uvc_format_info *format;
    struct uvc_frame_info *frame;
    unsigned int nframes;

    if (iformat < 0)
        iformat = server_l->uvc_formats_num + iformat;
    if (iformat < 0 || iformat >= (int)server_l->uvc_formats_num)
        return;

    format = &server_l->uvc_formats[iformat];

    nframes = 0;
    while (format->frames[nframes].width != 0)
        ++nframes;

    if (iframe < 0)
        iframe = nframes + iframe;
    if (iframe < 0 || iframe >= (int)nframes)
        return;
    frame = &format->frames[iframe];

    memset(ctrl, 0, sizeof *ctrl);

    ctrl->bmHint = 1;
    ctrl->bFormatIndex = iformat + 1;
    ctrl->bFrameIndex = iframe + 1;
    ctrl->dwFrameInterval = frame->intervals[0];
    switch (format->fcc) {
    case V4L2_PIX_FMT_YUYV:
        ctrl->dwMaxVideoFrameSize = frame->width * frame->height * 2;
        break;
    case V4L2_PIX_FMT_NV12:
        ctrl->dwMaxVideoFrameSize = frame->width * frame->height * 3 / 2;
        break;
    case V4L2_PIX_FMT_MJPEG:
    case V4L2_PIX_FMT_H264:
    case V4L2_PIX_FMT_HEVC:
        ctrl->dwMaxVideoFrameSize = MAX_BUFFER_SIZE * 3;//dev->imgsize * 3;
        break;
    }
    ctrl->dwMaxPayloadTransferSize = getMaxPayloadTransferSize(server_l->pipe_index);
    ctrl->bmFramingInfo = 3;
    ctrl->bPreferedVersion = 1;
    ctrl->bMaxVersion = 1;
}


static void uvc_events_process_streaming(uvc_server_t *server_l, struct uvc_device *dev, uint8_t req, uint8_t cs,
                struct uvc_request_data *resp)
{
    struct uvc_streaming_control *ctrl;

    log_info("pid %d streaming request (req %02x cs %02x)\n", getpid(), req, cs);

    if (cs != UVC_VS_PROBE_CONTROL && cs != UVC_VS_COMMIT_CONTROL)
        return;

    ctrl = (struct uvc_streaming_control *)&resp->data;
    resp->length = sizeof *ctrl;

    switch (req) {
    case UVC_SET_CUR:
        dev->control = cs;
        resp->length = 34;
        break;

    case UVC_GET_CUR:
        if (cs == UVC_VS_PROBE_CONTROL)
           memcpy(ctrl, &dev->probe, sizeof *ctrl);
        else
           memcpy(ctrl, &dev->commit, sizeof *ctrl);
        break;

    case UVC_GET_MIN:
    case UVC_GET_MAX:
    case UVC_GET_DEF:
        uvc_fill_streaming_control(server_l, dev, ctrl, req == UVC_GET_MAX ? -1 : 0,
                      req == UVC_GET_MAX ? -1 : 0);
        break;

    case UVC_GET_RES:
        memset(ctrl, 0, sizeof *ctrl);
        break;

    case UVC_GET_LEN:
        resp->data[0] = 0x00;
        resp->data[1] = 0x22;
        resp->length = 2;
        break;

    case UVC_GET_INFO:
        resp->data[0] = 0x03;
        resp->length = 1;
        break;
    }
}


static void uvc_events_process_class(uvc_server_t *server_l, struct uvc_device *dev, struct usb_ctrlrequest *ctrl,
             struct uvc_request_data *resp)
{
    if ((ctrl->bRequestType & USB_RECIP_MASK) != USB_RECIP_INTERFACE)
        return;

    if ((ctrl->wIndex & 0xff) == dev->control_interface)
        uvc_events_process_control(server_l, dev, ctrl->bRequest, ctrl->wValue >> 8, ctrl->wIndex >> 8, ctrl->wLength, resp);
    else if ((ctrl->wIndex & 0xff) == dev->streaming_interface)
        uvc_events_process_streaming(server_l, dev, ctrl->bRequest, ctrl->wValue >> 8, resp);
}

static void uvc_events_process_setup(uvc_server_t *server_l, struct uvc_device *dev, struct usb_ctrlrequest *ctrl,
             struct uvc_request_data *resp)
{
    dev->control = 0;

    //log_info("pid %d bRequestType %02x bRequest %02x wValue %04x wIndex %04x "
    //    "wLength %04x\n",getpid(), ctrl->bRequestType, ctrl->bRequest,
    //    ctrl->wValue, ctrl->wIndex, ctrl->wLength);

    switch (ctrl->bRequestType & USB_TYPE_MASK) {
    case USB_TYPE_STANDARD:
        uvc_events_process_standard(server_l, dev, ctrl, resp);
        break;

    case USB_TYPE_CLASS:
        uvc_events_process_class(server_l, dev, ctrl, resp);
        break;

    default:
        break;
    }
}

static int uvc_events_process_control_data(uvc_server_t *server_l, struct uvc_device *dev, uint8_t cs,
                                                 uint8_t entity_id, struct uvc_request_data *data)
{
    //unsigned int *val = (unsigned int *)data->data;
    int ret;

    //printf(" data = %d, length = %d  , current_cs = %d\n", *val , data->length, dev->cs);

    while(*(server_l->run_flag) && (server_l->status <= UVC_STATUS_INIT || server_l->status >= UVC_STATUS_EXIT))
    {
        usleep(1000);
    }

    switch (entity_id) {
        case 1:
            //printf("entity_id: %d cs: %d\n", entity_id, cs);
            switch (cs) {
                case UVC_CT_AE_MODE_CONTROL:
                    if(0 == data->data[0] || data->data[0] & (unsigned char)CT_AUTO_EXPOSURE_MODE_RES)
                    {
                        memcpy(&dev->camera_terminal.auto_exposure_mode_control, data->data, data->length);
                        if(CT_AUTO_EXPOSURE_MODE_AUTO_MODE == dev->camera_terminal.auto_exposure_mode_control)
                        {
                            aec_set_info_t aec_info;
                            aec_info.aec_mode = AEC_AUTO;
                            aec_info.gain = dev->camera_terminal.auto_exposure_aec_info.gain;
                            aec_info.exp_time_us = dev->camera_terminal.exposure_time_absolute_val * 100;
                            //printf("set auto mode %f %f\n", aec_info.gain, aec_info.exp_time_us);
                            ret = ar_cam_aec_manu_set(dev->camera_fd, aec_info);
                            if (ret < 0)
                            {
                                printf("set exposure_time failed!(%d)\n", ret);
                            }
                        }
                        else
                        {
                            basic_3a_info_t info;
                            ar_cam_get_3a_info(dev->camera_fd, &info);
                            dev->camera_terminal.auto_exposure_aec_info = info.aec_info;
                        }
                        //printf("set exposure_mode to %d\n", dev->camera_terminal.auto_exposure_mode_control);
                    }
                    else
                    {
                        printf("set exposure_mode to %d unsupported!\n", data->data[0]);
                    }
                    break;

                case UVC_CT_EXPOSURE_TIME_ABSOLUTE_CONTROL:
                    memcpy(&dev->camera_terminal.exposure_time_absolute_val, data->data, data->length);
                    //printf("set exposure_time to %d\n", dev->camera_terminal.exposure_time_absolute_val);
                    if (-1 != dev->camera_fd && dev->camera_terminal.exposure_time_absolute_val >= CT_EXPOSURE_TIME_ABSOLUTE_MIN_VAL &&
                        dev->camera_terminal.exposure_time_absolute_val <= CT_EXPOSURE_TIME_ABSOLUTE_MAX_VAL)
                    {
                        aec_set_info_t aec_info;
                        aec_info.aec_mode = AEC_MANUAL;
                        aec_info.gain = dev->camera_terminal.auto_exposure_aec_info.gain;
                        aec_info.exp_time_us = dev->camera_terminal.exposure_time_absolute_val * 100;
                        ret = ar_cam_aec_manu_set(dev->camera_fd, aec_info);
                        if (ret < 0)
                        {
                            printf("set exposure_time failed!(%d)\n", ret);
                        }
                    }
                    else
                    {
                        printf("check exposure_time setting failed!(fd:%d, br:%d)\n", dev->camera_fd, dev->camera_terminal.exposure_time_absolute_val);
                    }
                    break;

                case UVC_CT_ZOOM_ABSOLUTE_CONTROL:
                    memcpy(&dev->camera_terminal.zoom_absolute_val, data->data, data->length);
                    if (dev->camera_terminal.zoom_absolute_val >= CT_ZOOM_ABSOLUTE_MIN_VAL &&
                        dev->camera_terminal.zoom_absolute_val <= CT_ZOOM_ABSOLUTE_MAX_VAL)
                    {
                        uvc_server_t *server_uvc = server_l;
                        if(NULL == server_uvc || NULL == server_uvc->handle)
                        {
                            printf("check server_uvc handle failed!\n");
                        }
                        else
                        {
                            double zoom;
                            int ret;

                            zoom = dev->camera_terminal.zoom_absolute_val * 1.0 / 100;
                            //printf("set zoom to %f\n", zoom);

                            ret = ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,server_uvc->context->cam_src.element, 0),AR_COMMON_META_VIDEO_DIGITAL_ZOOM_NAME,&zoom,sizeof(double));
                            if(0 != ret)
                            {
                                printf("0 meta_value failed\n");
                            }
                            ar_pad_modify_meta_value(server_uvc->handle,ar_element_get_src_pad_by_idx(server_uvc->handle,server_uvc->context->cam_src.element, 1),AR_COMMON_META_VIDEO_DIGITAL_ZOOM_NAME,&zoom,sizeof(double));
                            if(0 != ret)
                            {
                                printf("1 meta_value failed\n");
                            }
                        }
                    }
                    break;

                case UVC_CT_ROLL_ABSOLUTE_CONTROL:
                    memcpy(&dev->camera_terminal.roll_absolute_val, data->data, data->length);
                    if (-1 != dev->camera_fd && dev->camera_terminal.roll_absolute_val >= CT_ROLL_ABSOLUTE_MIN_VAL &&
                        dev->camera_terminal.roll_absolute_val <= CT_ROLL_ABSOLUTE_MAX_VAL)
                    {
                        //printf("roll_absolute_val: %x %x %x\n", dev->camera_terminal.roll_absolute_val,
                        //                                        dev->camera_terminal.roll_absolute_val & CT_ROLL_ABSOLUTE_MIRROR,
                        //                                        (dev->camera_terminal.roll_absolute_val & CT_ROLL_ABSOLUTE_FLIP) == 0 ? 0 : 1);
                        if(ar_cam_mirror_set_state(dev->camera_fd, dev->camera_terminal.roll_absolute_val & CT_ROLL_ABSOLUTE_MIRROR) != 0)
                        {
                            printf("failed to set mirror!\n");
                        }

                        if(ar_cam_flip_set_state(dev->camera_fd, (dev->camera_terminal.roll_absolute_val & CT_ROLL_ABSOLUTE_FLIP) == 0 ? 0 : 1) != 0)
                        {
                            printf("failed to set flip!\n");
                        }
                    }
                    break;

                default:
                    break;
            }
            break;

        case 2:
            switch (cs) {
                case UVC_PU_BRIGHTNESS_CONTROL:
                    memcpy(&dev->processing_unit.brightness_val, data->data, data->length);
                    //printf("set brightness to %d\n", dev->processing_unit.brightness_val);
                    if (-1 != dev->camera_fd && dev->processing_unit.brightness_val >= PU_BRIGHTNESS_MIN_VAL &&
                        dev->processing_unit.brightness_val <= PU_BRIGHTNESS_MAX_VAL)
                    {
                        ret = ar_cam_set_brightness(dev->camera_fd, dev->processing_unit.brightness_val);
                        if (ret < 0)
                        {
                            printf("set brightness failed!(%d)\n", ret);
                        }
                    }
                    else
                    {
                        printf("check brightness setting failed!(fd:%d, br:%d)\n", dev->camera_fd, dev->processing_unit.brightness_val);
                    }
                    break;

                case UVC_PU_CONTRAST_CONTROL:
                    memcpy(&dev->processing_unit.contrast_val, data->data, data->length);
                    //printf("set contrast to %d\n", dev->processing_unit.contrast_val);
                    if (-1 != dev->camera_fd && dev->processing_unit.contrast_val >= PU_CONTRAST_MIN_VAL &&
                        dev->processing_unit.contrast_val <= PU_CONTRAST_MAX_VAL)
                    {
                        ret = ar_cam_set_contrast(dev->camera_fd, dev->processing_unit.contrast_val);
                        if (ret < 0)
                        {
                            printf("set contrast failed!(%d)\n", ret);
                        }
                    }
                    else
                    {
                        printf("check contrast setting failed!(fd:%d, ct:%d)\n", dev->camera_fd, dev->processing_unit.contrast_val);
                    }
                    break;

                case UVC_PU_HUE_CONTROL:
                    memcpy(&dev->processing_unit.hue_val, data->data, data->length);
                    //printf("set hue to %d\n", dev->processing_unit.hue_val);
                    if (-1 != dev->camera_fd && dev->processing_unit.hue_val >= PU_HUE_MIN_VAL &&
                        dev->processing_unit.hue_val <= PU_HUE_MAX_VAL)
                    {
                        //no API now(SATURATION instead)
                        ret = ar_cam_set_saturability(dev->camera_fd, dev->processing_unit.hue_val);
                        if (ret < 0)
                        {
                            printf("set hue failed!(%d)\n", ret);
                        }
                    }
                    else
                    {
                        printf("check hue setting failed!(fd:%d, ct:%d)\n", dev->camera_fd, dev->processing_unit.hue_val);
                    }
                    break;

                case UVC_PU_SATURATION_CONTROL:
                    memcpy(&dev->processing_unit.saturation_val, data->data, data->length);
                    //printf("set saturation to %d\n", dev->processing_unit.saturation_val);
                    if (-1 != dev->camera_fd && dev->processing_unit.saturation_val >= PU_SATURATION_MIN_VAL &&
                        dev->processing_unit.saturation_val <= PU_SATURATION_MAX_VAL)
                    {
                        ret = ar_cam_set_saturability(dev->camera_fd, dev->processing_unit.saturation_val);
                        if (ret < 0)
                        {
                            printf("set saturation failed!(%d)\n", ret);
                        }
                    }
                    else
                    {
                        printf("check saturation setting failed!(fd:%d, ct:%d)\n", dev->camera_fd, dev->processing_unit.saturation_val);
                    }
                    break;

                case UVC_PU_SHARPNESS_CONTROL:
                    memcpy(&dev->processing_unit.sharpness_val, data->data, data->length);
                    //printf("set sharpness to %d\n", dev->processing_unit.sharpness_val);
                    if (-1 != dev->camera_fd && dev->processing_unit.sharpness_val >= PU_SHARPNESS_MIN_VAL &&
                        dev->processing_unit.sharpness_val <= PU_SHARPNESS_MAX_VAL)
                    {
                        ret = ar_cam_set_shapeness(dev->camera_fd, dev->processing_unit.sharpness_val);
                        if (ret < 0)
                        {
                            printf("set sharpness failed!(%d)\n", ret);
                        }
                    }
                    else
                    {
                        printf("check sharpness setting failed!(fd:%d, ct:%d)\n", dev->camera_fd, dev->processing_unit.sharpness_val);
                    }
                    break;

                case UVC_PU_GAMMA_CONTROL:
                    //set brightness
                    break;

                case UVC_PU_WHITE_BALANCE_TEMPERATURE_CONTROL:
                    memcpy(&dev->processing_unit.white_balance_temperature_val, data->data, data->length);
                    //printf("set white_balance_temperature to %d\n", dev->processing_unit.white_balance_temperature_val);
                    if (-1 != dev->camera_fd && dev->processing_unit.white_balance_temperature_val >= PU_WHITE_BALANCE_TEMPERATURE_MIN_VAL &&
                        dev->processing_unit.white_balance_temperature_val <= PU_WHITE_BALANCE_TEMPERATURE_MAX_VAL)
                    {
                        awb_set_info_t awb_info;
                        awb_info.awb_mode = AWB_MANUAL;
                        awb_info.cct = dev->processing_unit.white_balance_temperature_val;
                        awb_info.r_gain = -1;
                        awb_info.g_gain = -1;
                        awb_info.b_gain = -1;
                        ret = ar_cam_awb_manu_set(dev->camera_fd, awb_info);
                        /*ret = ar_cam_awb_set_mode(dev->camera_fd,
                             PU_WHITE_BALANCE_TEMPERATURE_MAX_VAL == (PU_WHITE_BALANCE_TEMPERATURE_MAX_VAL - dev->processing_unit.white_balance_temperature_val) ?
                             PU_WHITE_BALANCE_TEMPERATURE_AUTO_VAL :
                             PU_WHITE_BALANCE_TEMPERATURE_MAX_VAL - dev->processing_unit.white_balance_temperature_val);*/
                        if (ret < 0)
                        {
                            printf("set white_balance_temperature failed!(%d)\n", ret);
                        }
                    }
                    else
                    {
                        printf("check white_balance_temperature setting failed!(fd:%d, ct:%d)\n", dev->camera_fd, dev->processing_unit.white_balance_temperature_val);
                    }
                    break;

                case UVC_PU_BACKLIGHT_COMPENSATION_CONTROL:
                    memcpy(&dev->processing_unit.backlight_compensation_val, data->data, data->length);
                    //printf("set backlight_compensation_val to %d\n", dev->processing_unit.backlight_compensation_val);
                    if (-1 != dev->camera_fd)
                    {
                        //no API now
                    }
                    else
                    {
                        printf("check backlight_compensation_val setting failed!(fd:%d, ct:%d)\n", dev->camera_fd, dev->processing_unit.backlight_compensation_val);
                    }
                    break;

                case UVC_PU_GAIN_CONTROL:
                    //set brightness
                    break;

                case UVC_PU_POWER_LINE_FREQUENCY_CONTROL:
                    memcpy(&dev->processing_unit.power_line_frequency_val, data->data, data->length);
                    //printf("set power_line_frequency_val to %d\n", dev->processing_unit.power_line_frequency_val);
                    if (-1 != dev->camera_fd && dev->processing_unit.power_line_frequency_val >= PU_POWER_LINE_FREQUENCY_MIN_VAL &&
                        dev->processing_unit.power_line_frequency_val <= PU_POWER_LINE_FREQUENCY_MAX_VAL)
                    {
                        ret = ar_cam_banding_set_state(dev->camera_fd, dev->processing_unit.power_line_frequency_val);
                        if (ret < 0)
                        {
                            printf("set banding failed!(%d)\n", ret);
                        }
                    }
                    else
                    {
                        printf("check banding setting failed!\n");
                    }
                    break;

                case UVC_PU_HUE_AUTO_CONTROL:
                    memcpy(&dev->processing_unit.hue_auto_val, data->data, data->length);
                    //printf("set hue_auto_val to %d\n", dev->processing_unit.hue_auto_val);
                    if (-1 != dev->camera_fd)
                    {
                        //no API now
                    }
                    else
                    {
                        printf("check hue_auto_val setting failed!(fd:%d, ct:%d)\n", dev->camera_fd, dev->processing_unit.hue_auto_val);
                    }
                    break;

                case UVC_PU_WHITE_BALANCE_TEMPERATURE_AUTO_CONTROL:
                    memcpy(&dev->processing_unit.white_balance_temperature_auto_val, data->data, data->length);
                    //printf("set hue_auto_val to %d\n", dev->processing_unit.white_balance_temperature_auto_val);
                    if (-1 != dev->camera_fd && dev->processing_unit.white_balance_temperature_auto_val == WHITE_BALANCE_TEMPERATURE_AUTO_DEFAULT_VAL)
                    {
                        awb_set_info_t awb_info;
                        awb_info.awb_mode = AWB_AUTO;
                        awb_info.cct = PU_WHITE_BALANCE_TEMPERATURE_DEFAULT_VAL;
                        awb_info.r_gain = -1;
                        awb_info.g_gain = -1;
                        awb_info.b_gain = -1;
                        ret = ar_cam_awb_manu_set(dev->camera_fd, awb_info);
                        if (ret < 0)
                        {
                            printf("set white_balance_temperature_auto_control failed!(%d)\n", ret);
                        }
                    }
                    else if(0 != dev->processing_unit.white_balance_temperature_auto_val)
                    {
                        printf("check white_balance_temperature_auto_val setting failed!(fd:%d, ct:%d)\n", dev->camera_fd, dev->processing_unit.white_balance_temperature_auto_val);
                    }
                    break;

                default:
                    break;
            }
            break;

        default:
            break;
    }

    return 0;
}

int uvc_video_set_format(uvc_server_t       *server_l, struct uvc_device *dev)
{
    struct v4l2_format fmt;
    int ret = 0;
    char *p = (char *)&dev->fcc;

    log_info("Setting format to 0x%08x(%c%c%c%c) %ux%u\n", dev->fcc, p[0], p[1], p[2], p[3], dev->width, dev->height);
    memset(&fmt, 0, sizeof fmt);
    fmt.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    fmt.fmt.pix.width = dev->width;
    fmt.fmt.pix.height = dev->height;
    fmt.fmt.pix.pixelformat = dev->fcc;
    fmt.fmt.pix.field = V4L2_FIELD_NONE;
    if (dev->fcc == V4L2_PIX_FMT_MJPEG)
        fmt.fmt.pix.sizeimage = MAX_BUFFER_SIZE;//first_image_size * 3;//dev->imgsize * 2;
    if(dev->fcc == V4L2_PIX_FMT_YUYV)
        fmt.fmt.pix.sizeimage = dev->width * dev->height * 2;
    if(dev->fcc == V4L2_PIX_FMT_NV12)
        fmt.fmt.pix.sizeimage = dev->width * dev->height * 3 / 2;
    if (dev->fcc == V4L2_PIX_FMT_H264)
        fmt.fmt.pix.sizeimage = MAX_BUFFER_SIZE;//first_image_size * 3;//dev->imgsize * 2;
    if (dev->fcc == V4L2_PIX_FMT_HEVC)
        fmt.fmt.pix.sizeimage = MAX_BUFFER_SIZE;//first_image_size * 3;//dev->imgsize * 2;
    if ((ret = ioctl(dev->fd, VIDIOC_S_FMT, &fmt)) < 0)
        log_err("Unable to set format: %s (%d).\n",
            strerror(errno), errno);

    return ret;
}

static void uvc_events_process_data(uvc_server_t       *server_l, struct uvc_device *dev, struct uvc_request_data *data)
{
    struct uvc_streaming_control *target;
    struct uvc_streaming_control *ctrl;
    struct uvc_format_info *format;
    struct uvc_frame_info *frame;
    unsigned int iformat, iframe;
    unsigned int nframes;

    switch (dev->control) {
        case UVC_VS_PROBE_CONTROL:
            log_info("setting probe control, length = %d\n", data->length);
            target = &dev->probe;
            break;

        case UVC_VS_COMMIT_CONTROL:
            log_info("setting commit control, length = %d\n", data->length);
            target = &dev->commit;
            break;

        default:
            //log_info("setting unknown control, length = %d\n", data->length);
            //printf("cs: %u, entity_id: %u\n", dev->cs, dev->entity_id);
            uvc_events_process_control_data(server_l, dev,
                                         dev->cs,
                                         dev->entity_id,
                                         data);

         return;
    }

    ctrl = (struct uvc_streaming_control *)&data->data;

    if(0 == data->length || 0 == ctrl->dwFrameInterval)
    {
        log_err("####################################uvc event data error###################################!!!\n");
        return;
    }

    iformat = clamp((unsigned int)ctrl->bFormatIndex, 1U, (unsigned int)server_l->uvc_formats_num);

    format = &server_l->uvc_formats[iformat-1];

    nframes = 0;
    while (format->frames[nframes].width != 0)
        ++nframes;

    iframe = clamp((unsigned int)ctrl->bFrameIndex, 1U, nframes);
    log_info("frame idx = %u inveral = %u\n", ctrl->bFrameIndex, ctrl->dwFrameInterval);
    frame = &format->frames[iframe-1];

    target->bFormatIndex = iformat;
    target->bFrameIndex = iframe;
    switch (format->fcc) {
    case V4L2_PIX_FMT_YUYV:
        target->dwMaxVideoFrameSize = frame->width * frame->height * 2;
        break;
    case V4L2_PIX_FMT_NV12:
        target->dwMaxVideoFrameSize = frame->width * frame->height * 3 / 2;
        break;
    case V4L2_PIX_FMT_MJPEG:
        if (dev->imgsize == 0)
            log_info("WARNING: MJPEG requested and no image loaded.\n");
        target->dwMaxVideoFrameSize = MAX_BUFFER_SIZE;
        break;
    case V4L2_PIX_FMT_H264:
        if (dev->imgsize == 0)
            log_info("WARNING: H264 requested and no image loaded.\n");
        target->dwMaxVideoFrameSize = MAX_BUFFER_SIZE;
        break;
    case V4L2_PIX_FMT_HEVC:
        if (dev->imgsize == 0)
            log_info("WARNING: h265 requested and no image loaded.\n");
        target->dwMaxVideoFrameSize = MAX_BUFFER_SIZE;
        break;
    }
    target->dwFrameInterval = ctrl->dwFrameInterval;

    if (dev->control == UVC_VS_COMMIT_CONTROL) {

        if (dev->width != frame->width || dev->height != frame->height || \
            dev->frame_interval != target->dwFrameInterval || \
            (dev->fcc != format->fcc || V4L2_PIX_FMT_H264 == dev->fcc || V4L2_PIX_FMT_HEVC == dev->fcc)) {

            dev->width = frame->width;
            dev->height = frame->height;
            dev->frame_interval = target->dwFrameInterval;

            dev->new_fcc = format->fcc;

            pthread_mutex_lock(server_l->p_chg_fmt_mutex);//get lock

            if(NULL == server_l->master)
            {
                int i;
                server_l->g_chg_fmt_flag = UVC_CHG_FMT_CHANGE;
                for(i = 0; i < server_l->slave_num; ++i)
                {
                    server_l->slave[i]->g_chg_fmt_flag = UVC_CHG_FMT_CHANGE;
                }
                server_l->chg_fmt_server = server_l;
            }
            else
            {
                int i;
                uvc_server_t * master_l = server_l->master;

                master_l->g_chg_fmt_flag = UVC_CHG_FMT_CHANGE;
                for(i = 0; i < master_l->slave_num; ++i)
                {
                    master_l->slave[i]->g_chg_fmt_flag = UVC_CHG_FMT_CHANGE;
                }
                master_l->chg_fmt_server = server_l;
            }
        }

        if (dev->bulk)
            uvc_video_stream(server_l, dev, 1);
    }
}

void uvc_events_process(uvc_server_t *server_l, struct uvc_device *dev)
{
    struct v4l2_event v4l2_event;
    struct uvc_event *uvc_event = (void *)&v4l2_event.u.data;
    struct uvc_request_data resp;
    int ret;

    ret = ioctl(dev->fd, VIDIOC_DQEVENT, &v4l2_event);
    if (ret < 0) {
        log_err("VIDIOC_DQEVENT failed: %s (%d)\n", strerror(errno),
            errno);
        return;
    }

    memset(&resp, 0, sizeof resp);
    resp.length = -EL2HLT;

    switch (v4l2_event.type) {
    case UVC_EVENT_CONNECT:
        printf("connect!\n");
         return;
    case UVC_EVENT_DISCONNECT:
        uvc_video_stream(server_l, dev, 0);
        uvc_video_reqbufs(server_l, dev, 0);
        log_info(
                "UVC: Possible USB shutdown requested from "
                "Host, seen via UVC_EVENT_DISCONNECT\n");
        return;

    case UVC_EVENT_SETUP:
        uvc_events_process_setup(server_l, dev, &uvc_event->req, &resp);
        break;

    case UVC_EVENT_DATA:
        uvc_events_process_data(server_l, dev, &uvc_event->data);
        return;

    case UVC_EVENT_STREAMON:
        uvc_video_reqbufs(server_l, dev, 3);

        while(*(server_l->run_flag) && server_l->status != UVC_STATUS_STOP &&
              server_l->status != UVC_STATUS_CHANGE_FORMAT &&
              server_l->g_chg_fmt_flag != 0)
        {
            usleep(1000);
        }

        uvc_video_stream(server_l, dev, 1);
        return;

    case UVC_EVENT_STREAMOFF:
        uvc_video_stream(server_l, dev, 0);
        uvc_video_reqbufs(server_l, dev, 0);
        return;
    }

    ioctl(dev->fd, UVCIOC_SEND_RESPONSE, &resp);
    if (ret < 0) {
        log_err("UVCIOC_S_EVENT failed: %s (%d)\n", strerror(errno),
            errno);
        return;
    }
}

static void uvc_video_fill_buffer(uvc_server_t *server_l, struct uvc_device *dev, struct v4l2_buffer *buf)
{
    unsigned int bpl;
    //unsigned int i;

    switch (dev->fcc) {
    case V4L2_PIX_FMT_YUYV:
        /* Fill the buffer with video data. */
        bpl = dev->width * 2;
        buf->m.userptr = (uint32_t)dev->imgdata;
        //for (i = 0; i < dev->height; ++i)
        //    memset(dev->mem[buf->index] + i*bpl, dev->color++, bpl);

        buf->bytesused = bpl * dev->height;
        break;

    case V4L2_PIX_FMT_NV12:
        bpl = dev->width * 3 / 2;
        buf->m.userptr = (uint32_t)dev->imgdata;
        buf->bytesused = bpl * dev->height;

    case V4L2_PIX_FMT_MJPEG:
    case V4L2_PIX_FMT_H264:
    case V4L2_PIX_FMT_HEVC:

        if(NULL != dev && NULL != dev->imgdata)
        {
            buf->m.userptr = (uint32_t)dev->imgdata;
            buf->bytesused = dev->imgsize;
            //buf->length = dev->imgsize;
        }
        else
        {
            buf->m.userptr = (uint32_t)server_l->first_image_data;//g_image_buffer[0];
            buf->bytesused = server_l->first_image_size;//MAX_BUFFER_SIZE;
        }

        break;
    }
}

int uvc_video_process(uvc_server_t *server_l, struct uvc_device *dev)
{
    struct v4l2_buffer buf;
    int ret;
    struct timeval uvc_tv;

    memset(&buf, 0, sizeof buf);
    buf.type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
    buf.memory = V4L2_MEMORY_USERPTR;//V4L2_MEMORY_MMAP;
    buf.length = MAX_BUFFER_SIZE;

    if ((ret = ioctl(dev->fd, VIDIOC_DQBUF, &buf)) < 0)
    {
        log_err("Unable to dequeue buffer: %s (%d).\n", strerror(errno),
                errno);
        return ret;
    }

    gettimeofday(&uvc_tv, NULL);

    server_l->g_uvc_timestamp = (unsigned long long)uvc_tv.tv_sec * 1000 + uvc_tv.tv_usec / 1000;

    buf.timestamp.tv_usec = uvc_tv.tv_usec;//(uvc_tv.tv_usec + 33000) % 1000000;
    buf.timestamp.tv_sec = uvc_tv.tv_sec;//(unsigned long long)uvc_tv.tv_sec + (uvc_tv.tv_usec + 33000) / 1000000;

    uvc_video_fill_buffer(server_l, dev, &buf);

    if ((ret = ioctl(dev->fd, VIDIOC_QBUF, &buf)) < 0)
    {
        log_err("Unable to requeue buffer: %s (%d).\n", strerror(errno),
               errno);
        return ret;
    }

    return 0;
}

int uvc_video_send(uvc_server_t *server_l, struct uvc_device *dev, void * data, unsigned int len, fd_set wfds, struct timeval tv)
{
    int ret = -1;
    pthread_mutex_lock(&server_l->g_wrt_com_mutex);

    dev->imgdata = data;
    dev->imgsize = len;

    if (1 == server_l->g_stream_on && len > 0)
    {
        ret = select(dev->fd + 1, NULL, &wfds, NULL, &tv);//&wfds
        if(ret > 0)
        {
            ret = uvc_video_process(server_l, dev);
            //usleep(len / 24);
        }
        else
        {
            //printf("select time out (%d)\n", ret);
            ret = -1;
        }
    }

    pthread_mutex_unlock(&server_l->g_wrt_com_mutex);

    return ret;
}


void uvc_events_init(uvc_server_t *server_l, struct uvc_device *dev)
{
    struct v4l2_event_subscription sub;

    uvc_fill_streaming_control(server_l, dev, &dev->probe, 0, 0);
    uvc_fill_streaming_control(server_l, dev, &dev->commit, 0, 0);

    if (dev->bulk) {
        /* FIXME Crude hack, must be negotiated with the driver. */
        dev->probe.dwMaxPayloadTransferSize = 16 * 1024;
        dev->commit.dwMaxPayloadTransferSize = 16 * 1024;
    }

    memset(&sub, 0, sizeof sub);

    sub.type = UVC_EVENT_CONNECT;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    sub.type = UVC_EVENT_DISCONNECT;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);

    sub.type = UVC_EVENT_SETUP;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    sub.type = UVC_EVENT_DATA;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    sub.type = UVC_EVENT_STREAMON;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
    sub.type = UVC_EVENT_STREAMOFF;
    ioctl(dev->fd, VIDIOC_SUBSCRIBE_EVENT, &sub);
}

int uvc_video_init(uvc_server_t *server_l, struct uvc_device *dev __attribute__((__unused__)))
{
    return 0;
}


