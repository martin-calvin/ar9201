#define ENABALE_ALL_LOG
#include <stdio.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <mtd/mtd-user.h>
#include "obc_sl_drv.h"
#include "flash_data_types.h"
#include "Mx6300_ctl.h"
int gwidth = 0;
int gheight = 0;
static void *process_sink_buf_0_thread(void *arg)
{
    sl_cam_raw_config_t *obj = (sl_cam_raw_config_t *)arg;
    sl_cam_buffer_t *buf = NULL;
    void *mem = NULL;
    int length = 0;
    int count = 0;
    while (obj->frame_count > 0)
    {
        pthread_mutex_lock(&obj->mutex);
        obj->buf_que->queue_pop(obj->buf_que, &buf);
        while (!buf)
        {
            pthread_cond_wait(&obj->buf_signal, &obj->mutex);
            obj->buf_que->queue_pop(obj->buf_que, &buf);
        }
        mem = buf->buf_mem;
        length = buf->buf_len;
        pthread_mutex_unlock(&obj->mutex);
        if (!mem)
        {
            printf("buf mem is NULL\n");
            free(buf);
            continue;
        }
        int width = gwidth;
        int height = gheight;

        int cnt = length / height;
        printf("width=%d,height=%d,cnt=%d\n", width, height, cnt);
        /* for (int i = 0; i < height; i++)
        {
            write(obj->fd, mem + (i * cnt), width * 2);
        }*/
        write(obj->fd, mem, length);
        free(mem);
        free(buf);
        obj->frame_count--;
        count++;
        printf("buf 0 count = %d\n", count);
        buf = NULL;
    }
    printf("process_sink_buf_0\r\n");
    close(obj->fd);
}

void get_sink_buf_0_thread(void *arg)
{
    struct timeval start, end;
    ar_picture_buffer_t *buffer = NULL;
    ar_picture_handle img_handle = NULL;
    int fd;
    sl_cam_raw_config_t *obj = (sl_cam_raw_config_t *)arg;
    int data_len = 0;
    sl_cam_buffer_t *buf;
    obj->buf_sink_fd = ar_picture_open("/dev/icc_proxy_rpc_sink-0");
    if (obj->buf_sink_fd < 0)
    {
        printf("open sink 0 error\n");
        return;
    }

    img_handle = (ar_picture_handle)(obj->buf_sink_fd);
    if (!img_handle)
    {
        printf("handle is null\n");
        return;
    }

    while (obj->frame_count > 0)
    {
        buffer = NULL;
        buffer = ar_picture_get_img(obj->buf_sink_fd);
        if (!buffer)
        {
            printf("get sink 0 buffer error\n");
            return;
        }
        //obj->fd = open(RAW_DATA_PATH, O_RDWR | O_CREAT);
        if (gwidth == 1280 && gheight == 1024)
        {
            // system("rm ir.raw");
            obj->fd = open("ir.raw", O_RDWR | O_CREAT);
        }
        else if (gwidth == 1024 && gheight == 1280)
        {
            //system("rm 1024x1280.raw");
            obj->fd = open("1024x1280.raw", O_RDWR | O_CREAT | O_APPEND);
        }
        else if (gwidth == 960 && gheight == 1280)
        {
            //system("rm 960x1280.raw");
            obj->fd = open("960x1280.raw", O_RDWR | O_CREAT);
        }
        else if (gwidth == 512 && gheight == 640)
        {
            // system("rm 512x640.raw");
            obj->fd = open("512x640.raw", O_RDWR | O_CREAT);
        }
        else if (gwidth == 480 && gheight == 640)
        {
            // system("rm 480x640.raw");
            obj->fd = open("480x640.raw", O_RDWR | O_CREAT);
        }
        else
        {
            obj->fd = open(RAW_DATA_PATH, O_RDWR | O_CREAT);
        }
        if (obj->fd < 0)
        {
            printf("open file error\n");
            return;
        }
        printf("the mem count = %d\n", buffer->mem_num);
        printf("frame id = %d\n", buffer->frame_id);
        printf("pts = %d\n", buffer->pts);
        printf("width = %d,height= %d\n", buffer->format.width, buffer->format.height);
        printf("luma_stride=%d,chroma_stride=%d\n", buffer->format.luma_stride, buffer->format.chroma_stride);
        data_len = buffer->mem[0].len;
        //buf = (void*)buffer->mem[0].addr;
        buf = (sl_cam_buffer_t *)malloc(sizeof(sl_cam_buffer_t));
        if (buf == NULL)
        {
            printf("malloc buf 0 error\n");
        }
        buf->buf_mem = (char *)malloc(data_len);
        if (!buf->buf_mem)
        {
            printf("malloc buf mem error\n");
        }
        buf->buf_len = data_len;
        printf("buf len = %d, %d, %d\n", buffer->mem[0].len, buffer->mem[1].len, buffer->mem[2].len);
        gettimeofday(&start, NULL);
        memcpy(buf->buf_mem, buffer->mem[0].addr, data_len);
        gettimeofday(&end, NULL);
        pthread_mutex_lock(&obj->mutex);
        if (obj->buf_que->queue_insert(obj->buf_que, buf))
        {
            printf("insert queue err\n");
        }
        pthread_cond_signal(&obj->buf_signal);
        pthread_mutex_unlock(&obj->mutex);
        if (ar_picture_release_img(img_handle, buffer))
        {
            printf("release buffer failed\n");
            return;
        }
    }
    ar_picture_close(obj->buf_sink_fd);
    printf("buf 0 write finish\n");
}

/*int tof_sensor_api_init(void)
{
    tof_sensor.init = s5k33dxx_sensor_init;
    tof_sensor.get_sensor_id = s5k33dxx_get_sensor_id;
    tof_sensor.video_streaming = s5k33dxx_video_streaming;
    tof_sensor.get_fps = s5k33dxx_get_fps;
    tof_sensor.set_fps = s5k33dxx_set_fps;
    tof_sensor.set_illum_power = s5k33dxx_set_illum_power;
    tof_sensor.get_illum_power = s5k33dxx_get_illum_power;
    tof_sensor.illum_power_control = s5k33dxx_illum_power_control;
    tof_sensor.get_integration_time = s5k33dxx_get_integration_time;
    tof_sensor.set_integration_time = s5k33dxx_set_integration_time;
    tof_sensor.get_modulation_frequency = s5k33dxx_get_modulation_frequency;
    tof_sensor.set_modulation_frequency = s5k33dxx_set_modulation_frequency;
    tof_sensor.get_illum_duty_cycle = s5k33dxx_get_illum_duty_cycle;
    tof_sensor.set_illum_duty_cycle = s5k33dxx_set_illum_duty_cycle;
    tof_sensor.get_data_output_mode = s5k33dxx_get_data_output_mode;
    tof_sensor.set_data_output_mode = s5k33dxx_set_data_output_mode;
    tof_sensor.get_img_mirror_flip = s5k33dxx_get_img_mirror_flip;
    tof_sensor.set_img_mirror_flip = s5k33dxx_set_img_mirror_flip;
    tof_sensor.get_pixel_binning = s5k33d_get_pixel_binning;
    tof_sensor.set_pixel_binning = s5k33d_set_pixel_binning;
    tof_sensor.test_pattern = s5k33dxx_test_pattern;

    // tof_sensor.init();
    return 0;
}*/

/*
    obc cam init
    return < 0 err;
*/

/*
    obc cam capture mipi raw data
    return < 0 err;
*/
int capture_cam_raw(uint32_t frame_cnt)
{
    sl_cam_raw_config_t obj;

    obj.frame_count = frame_cnt;
    pthread_cond_init(&obj.buf_signal, NULL);
    pthread_mutex_init(&obj.mutex, NULL);
    obj.buf_que = ar_creat_queue(MAX_MEM_FIFO, "buf_sink_0");
    pthread_create(&obj.thread_id, NULL, (void *)get_sink_buf_0_thread, (void *)&obj);
    pthread_create(&obj.thread_process_id, NULL, (void *)process_sink_buf_0_thread, (void *)&obj);
    pthread_join(obj.thread_id, NULL);
    pthread_join(obj.thread_process_id, NULL);
    return 0;
}

int flash_ops(uint32_t addr)
{
    mtd_info_t mtd_info; // the MTD structure
    erase_info_t ei;     // the erase block structure
    int i;

    unsigned char data[20] = {0xDE, 0xAD, 0xBE, 0xEF, // our data to write
                              0xDE, 0xAD, 0xBE, 0xEF,
                              0xDE, 0xAD, 0xBE, 0xEF,
                              0xDE, 0xAD, 0xBE, 0xEF,
                              0xDE, 0xAD, 0xBE, 0xEF};
    unsigned char read_buf[20] = {0x00}; // empty array for reading

    int fd = open("/dev/mtd0", O_RDWR); // open the mtd device for reading and
                                        // writing. Note you want mtd0 not mtdblock0
                                        // also you probably need to open permissions
                                        // to the dev (sudo chmod 777 /dev/mtd0)

    ioctl(fd, MEMGETINFO, &mtd_info); // get the device info

    // dump it for a sanity check, should match what's in /proc/mtd
    printf("MTD Type: %x\nMTD total size: %x bytes\nMTD erase size: %x bytes\n",
           mtd_info.type, mtd_info.size, mtd_info.erasesize);

    ei.length = mtd_info.erasesize; //set the erase block size
                                    // int offset = mtd_info.size / (1024);
    for (ei.start = addr; ei.start < addr + 0x1000; ei.start += ei.length)
    {
        if (ioctl(fd, MEMUNLOCK, &ei) < 0)
        {
            printf("[Flash] Can not unlock MTD (MEMUNLOCK, errno=%d)!n", errno);
        }
        printf("Eraseing Block %#x\n", ei.start); // show the blocks erasing
                                                  // warning, this prints a lot!
        if (ioctl(fd, MEMERASE, &ei) < 0)
        {
            printf("[Flash] Can erase MTD (MEMERASE, errno=%d)!n", errno);
        }
    }

    lseek(fd, addr, SEEK_SET);            // go to the first block
    read(fd, read_buf, sizeof(read_buf)); // read 20 bytes

    // sanity check, should be all 0xFF if erase worked
    for (i = 0; i < 20; i++)
        printf("buf[%d] = 0x%02x\n", i, (unsigned int)read_buf[i]);

    lseek(fd, addr, SEEK_SET);     // go back to first block's start
    write(fd, data, sizeof(data)); // write our message

    lseek(fd, addr, SEEK_SET);            // go back to first block's start
    read(fd, read_buf, sizeof(read_buf)); // read the data

    // sanity check, now you see the message we wrote!
    for (i = 0; i < 20; i++)
        printf("buf[%d] = 0x%02x\n", i, (unsigned int)read_buf[i]);
    close(fd);
    return 0;
}
int spi_control()
{

    int fd_sys_reg_base = open("/dev/mem", O_RDWR | O_SYNC);
    char *g_va_sys_reg_base = mmap(NULL, 0x100000, PROT_READ | PROT_WRITE, MAP_SHARED, fd_sys_reg_base, 0x40420000); //0x40420024

    /* spi ctrl pin */
    (*(g_va_sys_reg_base + 0x28)) |= (1 << 4); // dir-output

    {
        (*(g_va_sys_reg_base + 0x24)) &= ~(1 << 4); // low
    }
    usleep(1000);
    close(fd_sys_reg_base);
    return 0;
}
int obc_read_flash(uint32_t offset_addr, uint8_t *pdatabuf, uint32_t len)
{
    mtd_info_t mtd_info; // the MTD structure
    erase_info_t ei;     // the erase block structure
    int nread;
    int fd = open("/dev/mtd0", O_RDONLY);
    lseek(fd, offset_addr, SEEK_SET);
    nread = read(fd, pdatabuf, len);
    if (nread <= 0)
    {
        printf("read flash failed (MEMREAD, errno=%d)!n", errno);
        close(fd);
        return -1;
    }
    close(fd);
}
int obc_erase_flash(uint32_t offset_addr, uint32_t len)
{
    mtd_info_t mtd_info; // the MTD structure
    erase_info_t ei;     // the erase block structure
    int nwrite;
    int fd = open("/dev/mtd0", O_RDWR | O_SYNC);
    if (fd < 0)
    {
        printf("open /dev/mtd0 failed\n");
        return -1;
    }
    ioctl(fd, MEMGETINFO, &mtd_info); // get the device info
    ei.length = mtd_info.erasesize;   //set the erase block size
    int left = offset_addr % ei.length;
    offset_addr -= left;
    for (ei.start = offset_addr; ei.start < offset_addr + len; ei.start += ei.length)
    {
        if (ioctl(fd, MEMERASE, &ei) < 0)
        {
            printf("[Flash] Can erase MTD (MEMERASE, errno=%d)!n", errno);
            close(fd);
            return -1;
        }
    }
    close(fd);
}
int obc_write_flash(uint32_t offset_addr, uint8_t *pdatabuf, uint32_t len)
{
    mtd_info_t mtd_info; // the MTD structure
    erase_info_t ei;     // the erase block structure
    int nwrite;
    int fd = open("/dev/mtd0", O_RDWR | O_SYNC);
    if (fd < 0)
    {
        printf("open /dev/mtd0 failed\n");
        return -1;
    }
    lseek(fd, offset_addr, SEEK_SET); // go to the first block
    nwrite = write(fd, pdatabuf, len);
    if (nwrite <= 0)
    {
        close(fd);
        return -1;
    }
    close(fd);
}
void test_command()
{
    char ch = (char)getchar();
    int addr = 0;
    int value = 0;
    mx6300_i2c_ctrl i2c_ctrl = {0};
    uint8_t val8;
    int ret;
    uint32_t addr_ahb, addr_value;
    while (ch != 'q')
    {

        switch (ch)
        {
        case '0':
            printf("get  device ID\n");
            uint16_t devID;
            ret = Mx6300_get_device_id(&devID);
            if (ret < 0)
            {
                printf("get Device id failed\n");
            }
            else
            {
                printf("Device ID=0x%x\n", devID);
            }
            break;
        case '1':
            printf("get firmware version\n");
            char fw[9] = {0};
            ret = Mx6300_read_fw_version(fw);
            if (ret < 0)
            {
                printf("get firmware version failed\n");
            }
            else
            {
                printf("fw ver:%s\n", fw);
            }
            break;
        case '2':
            printf("get hardware version\n");
            uint8_t hw;
            ret = Mx6300_read_hw_version(&hw);
            if (ret < 0)
            {
                printf("get hardware version failed\n");
            }
            else
            {
                printf("Hw ver:%d\n", hw);
            }
            break;
        case '3':
            printf("get hardware version\n");
            uint8_t hw1;
            ret = Mx6300_read_hw_version(&hw1);
            if (ret < 0)
            {
                printf("get hardware version failed\n");
            }
            else
            {
                printf("Hw ver:%d\n", hw1);
            }
            break;
        case '4':
            printf("stream control\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);

            Stream_ctl_State s = value;
            ret = Mx6300_Stream_control(s);
            if (ret < 0)
            {
                printf("stream control failed\n");
            } /*else{
          if(value!=0){
          system("rm /mnt/data.raw");
            capture_cam_raw(1);
          }
      } */

            break;
        case '5':
            printf("laser status control\n");
            fflush(stdin);
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = Mx6300_laser_control(value);
            if (ret < 0)
            {
                printf("laser control  failed\n");
            }
            break;
        case '6':
            printf("get laser status\n");
            uint8_t laser;
            ret = Mx6300_get_laser_status(&laser);
            if (ret < 0)
            {
                printf("get laser status failed\n");
            }
            else
            {
                printf("laser status:%d\n", laser);
            }
            break;
        case '7':
            printf("set ir gain\n");
            fflush(stdin);
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ir_gain(value);
            if (ret < 0)
            {
                printf("set ir gain failed\n");
            }
            break;
        case '8':
            printf("get ir gain\n");
            uint32_t gain;
            ret = Mx6300_get_ir_gain(&gain);
            if (ret < 0)
            {
                printf("get ir gain failed\n");
            }
            else
            {
                printf("ir  gain:%d\n", gain);
            }
            break;
        case '9':
            printf("set ir exposure\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ir_exposure(value);
            if (ret < 0)
            {
                printf("set ir exposure failed\n");
            }
            break;
        case 'A':
            printf("get ir exposure\n");
            uint32_t exp;
            ret = Mx6300_get_ir_exposure(&exp);
            if (ret < 0)
            {
                printf("get ir exposure failed\n");
            }
            else
            {
                printf("ir exposure:%d\n", exp);
            }
            break;
        case 'B':
            printf("write ahb\n");
            fflush(stdin);
            printf("please input  addr and data\n");
            scanf("%x %x", &addr, &value);
            ret = Mx6300_write_ahb(addr, value);
            if (ret < 0)
            {
                printf("write adb failed\n");
            }
            break;
        case 'C':
            printf("read ahb\n");
            fflush(stdin);
            printf("please input  addr\n");
            scanf("%x", &addr);
            ret = Mx6300_read_ahb(addr, &value);
            if (ret < 0)
            {
                printf("read adb failed\n");
            }
            else
            {
                printf("data=0x%x(addr:0x%x)\n", value, addr);
            }
            break;
        case 'D':
            printf("write i2c\n");
            fflush(stdin);
            // mx6300_i2c_ctrl i2c_ctrl={0};
            printf("please input bus,slave_addr,reg,reg_len,data,data_len\n");
            scanf("%x %x %x %x %x %x", &i2c_ctrl.bus, &i2c_ctrl.slave_addr, &i2c_ctrl.reg,
                  &i2c_ctrl.reg_len, &i2c_ctrl.data, &i2c_ctrl.data_len);
            ret = Mx6300_write_i2c(&i2c_ctrl);
            if (ret < 0)
            {
                printf("write i2c failed\n");
            }
            break;
        case 'E':
            printf("read i2c\n");
            fflush(stdin);
            //mx6300_i2c_ctrl i2c_ctrl_read={0};
            printf("please input bus,slave_addr,reg,reg_len,data,data_len\n");
            scanf("%x %x %x %x %x %x", &i2c_ctrl.bus, &i2c_ctrl.slave_addr, &i2c_ctrl.reg,
                  &i2c_ctrl.reg_len, &i2c_ctrl.data, &i2c_ctrl.data_len);
            ret = Mx6300_read_i2c(&i2c_ctrl);
            if (ret < 0)
            {
                printf("read i2c failed\n");
            }
            else
            {
                printf("data=0x%x(reg_addr=0x%x)\n", i2c_ctrl.data, i2c_ctrl.reg);
            }
            break;
        case 'F':
            printf("ir resolution switch \n");
            fflush(stdin);
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ir_resolution((Resolution_State)value);
            if (ret < 0)
            {
                printf("ir resolution switch failed\n");
            }
            break;
        case 'G':
            printf("get ir resolution\n");
            uint8_t ir_res;
            ret = Mx6300_get_ir_resolution(&ir_res);
            if (ret < 0)
            {
                printf("get ir resolution failed\n");
            }
            else
            {
                printf("ir resolution :%d\n", ir_res);
            }
            break;
        case 'H':
            printf("depth resolution switch \n");
            fflush(stdin);
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = Mx6300_set_depth_resolution((Resolution_State)value);
            if (ret < 0)
            {
                printf("depth resolution switch failed\n");
            }
            break;
        case 'I':
            printf("get depth resolution\n");
            uint8_t depth_res;
            ret = Mx6300_get_depth_resolution(&depth_res);
            if (ret < 0)
            {
                printf("get depth resolution failed\n");
            }
            else
            {
                printf("depth resolution :%d\n", depth_res);
            }
            break;
        case 'J':
            printf("switch ir resolution\n");
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = switch_resolution(STREAM_IR_OPEN, value, 30);
            // ret = Mx6300_set_ir_resolution(value);
            if (ret < 0)
            {
                printf("switch ir resolution failed\n");
            }
            else
            {
                system("rm /mnt/data.raw");
                if (value == 1)
                {
                    gwidth = 1280;
                    gheight = 800;
                }
                else
                {
                    gwidth = 640;
                    gheight = 400;
                }
                capture_cam_raw(1);
            }
            break;
        case 'K':
            printf("switch depth/IR resolution\n");
            printf("please input  value");
            ret = scanf("%x", &value);
            ret = switch_resolution(STREAM_DEPTH_OPEN, value, 30);
            // ret = Mx6300_set_ir_resolution(value);
            if (ret < 0)
            {
                printf("switch depth resolution failed\n");
            }
            else
            {
                system("rm /mnt/data.raw");
                if (value == 1)
                {
                    gwidth = 1280;
                    gheight = 800;
                }
                else
                {
                    gwidth = 640;
                    gheight = 400;
                }
                capture_cam_raw(1);
            }
            break;
        case 'L':
            printf("auto switch ir resolution\n");
            value = 1;
            int loop_cnt;
            printf("please input  loop count\n");
            ret = scanf("%x", &loop_cnt);
            for (int i = 0; i < loop_cnt; i++)
            {
                printf("auto switch resolution loop=%d\n", i + 1);
                ret = switch_resolution(STREAM_DEPTH_OPEN, value, 30);
                if (ret < 0)
                {
                    printf("switch depth resolution failed\n");
                }
                else
                {
                    system("rm /mnt/data.raw");
                    if (value == 1)
                    {
                        gwidth = 1280;
                        gheight = 800;
                        value = 2;
                    }
                    else
                    {
                        gwidth = 640;
                        gheight = 400;
                        value = 1;
                    }
                    capture_cam_raw(1);
                }
            }
            break;
        case 'M':
            printf("write flash\n");
            printf("please input option(0->sn,1->distortion,2->erase flash,3->reference):\n");
            int option;
            ret = scanf("%x", &option);
            switch (option)
            {
            case 0:
                printf("please input sn\n");
                char sn[20] = {0};
                ret = scanf("%s", sn);
                // char *sn = "DO987654TUYOG";
                char sn_r[20] = {0};
                DeviceConfig config = {0};
                ret = obc_sl_read_flash(DEVICE_CONFIG_ADDR, &config, sizeof(DeviceConfig));
                if (ret < 0)
                {
                    printf("read config from flash failed\n");
                }
                memcpy(config.sn, sn, 12);
                ret = obc_sl_write_flash(DEVICE_CONFIG_ADDR, &config, sizeof(DeviceConfig));
                if (ret < 0)
                {
                    printf("write sn to flash failed\n");
                }
                else
                {
                    memset(&config,0,sizeof(config));
                    ret = obc_sl_read_flash(DEVICE_CONFIG_ADDR, &config, sizeof(DeviceConfig));
                    if (ret < 0)
                    {
                        printf("read config from flash failed\n");
                    }
                    else
                    {
                        memcpy(sn_r,config.sn,12);
                        printf("sn_write:%s\nsn_read:%s\n", sn, sn_r);
                    }
                }
                break;
            case 1:
            {
                Doraemon_Content_t doraemont_dis;
                FILE *fpdis = fopen("distortion_origin.bin", "rb");
                fread(&doraemont_dis, 1, sizeof(doraemont_dis), fpdis);
                ret = obc_sl_write_flash(DISTORTION_PARAMS_ADDR, &doraemont_dis, sizeof(doraemont_dis));
                if (ret < 0)
                {
                    printf("write distortion file to flash failed\n");
                }
                fclose(fpdis);
                memset(&doraemont_dis,0,sizeof(Doraemon_Content_t));
                  ret = obc_sl_read_flash(DISTORTION_PARAMS_ADDR, &doraemont_dis, sizeof(doraemont_dis));
                if (ret < 0)
                {
                    printf("write distortion file to flash failed\n");
                }
                fpdis = fopen("distortion_read.bin", "wb");

                fwrite(&doraemont_dis, 1, sizeof(doraemont_dis), fpdis);
                fclose(fpdis);
                break;
            }
            case 2:
            {
                printf("please input the start  addr  of flash and size\n");
                uint32_t start_addr,size;
                 ret = scanf("%x %x", &start_addr,&size);
                ret = obc_sl_erase_flash(start_addr, size);
                if (ret < 0)
                {
                    printf("erase  flash failed\n");
                }
                break;
            }
            case 3:
            {
                printf("please input the loop count\n");
                spi_control();
                ret = scanf("%d", &value);
                FILE *fpref = fopen("reference.bin", "rb");
                fseek(fpref, 0, SEEK_END);
                int nFileLen = ftell(fpref);
                fseek(fpref, 0, SEEK_SET);
                printf("reference file lenght=%d\n", nFileLen);
                uint8_t *rbuf = calloc(1, nFileLen + 4);
                //*((uint32_t *)rbuf) = nFileLen;
                memcpy(rbuf, &nFileLen, 4);
                int readcnt = fread(rbuf + 4, 1, nFileLen, fpref);
                nFileLen += 4;
                printf("readcnt=%d\n", readcnt);
                uint8_t *tbuf = calloc(1, nFileLen);
                int testSuccess = 0;
                for (int loop = 0; loop < value; loop++)
                {

#if 0
                int cnt = nFileLen / 4096;
                int left = nFileLen % 4096;
                uint32_t flash_addr;
                if (cnt > 0)
                {
                    for (int i = 0; i < cnt; i++)
                    {
                         flash_addr = REFERENCE_ADDR + i * 4096;
                        ret = obc_sl_write_flash(flash_addr, rbuf + i * 4096, 4096);
                        if (ret < 0)
                        {
                            printf("write reference to flash failed(index=%d,addr=0x%x)\n", i,flash_addr);
                        }
                        else
                        {
                            printf("write reference to flash completed(index=%d,addr=0x%x)\n", i,flash_addr);
                        }
                        usleep(5000);
                    }
                }
                
                if (left)
                {
                    flash_addr=REFERENCE_ADDR + cnt * 4096;
                    ret = obc_sl_write_flash(flash_addr, rbuf + cnt * 4096, left);
                    if (ret < 0)
                    {
                        printf("write reference to flash last failed\n");
                    }
                    else
                    {
                        printf("write reference to flash completed last(left=%d)\n",left);
                    }
                }
#else
                    /* ret = obc_erase_flash(REFERENCE_ADDR, nFileLen);
                    if (ret < 0)
                    {
                        printf("erase(addr=0x%x+0x%x) flash failed\n", REFERENCE_ADDR, nFileLen);
                    }
                    usleep(5000);
                    ret = obc_write_flash(REFERENCE_ADDR, rbuf, nFileLen);*/
                    ret = obc_sl_write_flash(REFERENCE_ADDR, rbuf, nFileLen);
                    if (ret < 0)
                    {
                        printf("write reference file to flash failed\n");
                    }
#endif
                    printf("write reference to flash completed\n");

                    uint32_t len[10];
                    usleep(5000);
#if 0
#define BLOCK_SIZE 4096
                     cnt = nFileLen / BLOCK_SIZE;
                     left = nFileLen % BLOCK_SIZE;
                    //uint32_t flash_addr;
                    if (cnt > 0)
                    {
                        for (int i = 0; i < cnt; i++)
                        {
                            flash_addr = REFERENCE_ADDR + i * BLOCK_SIZE;
                            //ret = obc_read_flash(flash_addr, tbuf + i * BLOCK_SIZE, BLOCK_SIZE);
                            ret = obc_sl_read_flash(flash_addr, tbuf + i * BLOCK_SIZE, BLOCK_SIZE);
                            if (ret < 0)
                            {
                                printf("read reference from flash failed(index=%d,addr=0x%x)\n", i, flash_addr);
                            }
                            else
                            {
                                printf("read reference from flash completed(index=%d,addr=0x%x)\n", i, flash_addr);
                            }
                            usleep(5000);
                        }
                    }

                    if (left)
                    {
                        flash_addr = REFERENCE_ADDR + cnt * BLOCK_SIZE;
                        //ret = obc_read_flash(flash_addr, tbuf + cnt * BLOCK_SIZE, left);
                        ret = obc_sl_read_flash(flash_addr, tbuf + cnt * BLOCK_SIZE, left);
                        if (ret < 0)
                        {
                            printf("read reference from flash last failed\n");
                        }
                        else
                        {
                            printf("read reference from flash completed last(left=%d)\n", left);
                        }
                    }

#else
                    // ret = obc_read_flash(REFERENCE_ADDR, tbuf, nFileLen);
                    ret = obc_sl_read_flash(REFERENCE_ADDR, tbuf, nFileLen);
                    if (ret < 0)
                    {
                        printf("read reference from flash failed\n");
                    }
                    else
#endif

                    {
                        // for(int i=0;i<10;i++)
                        //printf("len[%d]=0x%x\n",i, len[i]);
                        for (int i = 0; i < nFileLen; i++)
                        {
                            if (rbuf[i] != tbuf[i])
                            {
                                printf("the data is not identical(i=%d,rbuf=0x%x,tbuf=0x%x)\n", i, rbuf[i], tbuf[i]);
                                FILE *fw = fopen("reference_r.bin", "wb");
                                fwrite(tbuf, 1, nFileLen, fw);
                                fclose(fw);
                                testSuccess = -1;
                                break;
                            }
                        }
                        if (testSuccess == -1)
                        {
                            printf("compare(index=%d) between write and read failed\n", loop);
                            break;
                        }
                        else
                        {
                            printf("compare(index=%d) between write and read completed\n", loop);
                        }
                    }
                }
                fclose(fpref);
                free(rbuf);
                free(tbuf);
                printf("compare over\n");
                break;
            }
            default:
                break;
            }

            //flash_ops(REFERENCE_ADDR);
            break;
        case 'N':
            printf("stream control\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            for (int i = 0; i < value; i++)
            {
                printf("stream on/off loop count =%d\n", i);
                usleep(1000 * 1000);
                ret = Mx6300_Stream_control(STREAM_CLOSE);
                if (ret < 0)
                {
                    printf("stream control failed\n");
                }
                usleep(1000 * 1000);
                ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                if (ret < 0)
                {
                    printf("stream control failed\n");
                }
                else
                {
                    if (value != 0)
                    {
                        system("rm /mnt/data.raw");
                        capture_cam_raw(1);
                    }
                }
            }
            /*Stream_ctl_State s = value;
      ret=Mx6300_Stream_control(s);
      if(ret<0){
          printf("stream control failed\n");
      } else{
          if(value!=0){
          system("rm /mnt/data.raw");
            capture_cam_raw(1);
          }
      } */

            break;
        case 'O':
            printf("stream control\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            Stream_ctl_State sd = value;
            //ret=Mx6300_Stream_control(sd);
            if (value == 0)
            {
                ret = sl_stream_off();
            }
            else
            {
                ret = sl_stream_on(sd);
            }
            if (ret < 0)
            {
                printf("stream control failed\n");
            }
            else
            {
                if (value != 0)
                {
                    system("rm /mnt/data.raw");
                    usleep(20000);
                    capture_cam_raw(1);
                }
            }
            break;
        case 'P':
            printf("stream control\n");
            fflush(stdin);
            printf("please input  type of stream,0->depth,1->ir,2->interleave\n");
            int type;
            int turnFlag = 0;
            ret = scanf("%d", &type);
            printf("please input  loop count\n");
            ret = scanf("%x", &value);
            for (int i = 0; i < value; i++)
            {
                printf("stream on/off loop count =%d\n", i);
                usleep(1000 * 1000);
                printf("stream off start\n", i);
                ret = sl_stream_off();
                printf("stream off end\n", i);
                if (ret < 0)
                {
                    printf("stream off failed\n");
                }
                usleep(1000 * 1000);
                printf("stream on start\n");
                if (type == 0)
                {
                    ret = sl_stream_on(STREAM_DEPTH_OPEN);
                }
                else if (type == 1)
                {
                    ret = sl_stream_on(STREAM_IR_OPEN);
                }
                else
                {
                    if (turnFlag == 0)
                    {
                        ret = sl_stream_on(STREAM_DEPTH_OPEN);
                        turnFlag = 1;
                    }
                    else
                    {
                        ret = sl_stream_on(STREAM_IR_OPEN);
                        turnFlag = 0;
                    }
                }
                printf("stream on end\n", i);
                if (ret < 0)
                {
                    printf("stream control failed\n");
                }
                else
                {
                    if (value != 0)
                    {
                        system("rm data.raw");
                        capture_cam_raw(1);
                    }
                }
            }
            /*Stream_ctl_State s = value;
      ret=Mx6300_Stream_control(s);
      if(ret<0){
          printf("stream control failed\n");
      } else{
          if(value!=0){
          system("rm /mnt/data.raw");
            capture_cam_raw(1);
          }
      } */

            break;
        case 'Q':
            printf("mx6300 stream control\n");
            fflush(stdin);
            printf("please input  type of stream,0->depth,1->ir,2->interleave,3->depth interleave\n");
            int type1;
            int turnFlag1 = 0;
            ret = scanf("%d", &type1);
            printf("please input  loop count\n");
            ret = scanf("%x", &value);
            for (int i = 0; i < value; i++)
            {
                printf("mx6300 stream on/off loop count =%d\n", i);
                usleep(1000 * 1000);
                printf("mx6300 stream off start\n", i);
                ret = Mx6300_Stream_control(STREAM_CLOSE);
                printf("mx6300 stream off end\n", i);
                if (ret < 0)
                {
                    printf("mx6300 stream off failed\n");
                }
                usleep(1000 * 1000);
                printf("mx6300 stream on start\n");
                if (type1 == 0)
                {
                    ret = Mx6300_Stream_control(STREAM_DEPTH_OPEN);
                }
                else if (type1 == 1)
                {
                    ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                }
                else if (type1 == 2)
                {
                    if (turnFlag1 == 0)
                    {
                        //ret = Mx6300_Stream_control(STREAM_DEPTH_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_960_1280, 30);
                        turnFlag1 = 0;
                        gwidth = 960;
                        gheight = 1280;
                    }
                    else
                    {
                        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                        ret = switch_resolution(STREAM_IR_OPEN, RES_SXGA, 30);
                        turnFlag1 = 0;
                        gwidth = 1280;
                        gheight = 1024;
                    }
                }
                else
                {
                    if (turnFlag1 == 0)
                    {
                        //ret = Mx6300_Stream_control(STREAM_DEPTH_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_1024_1280, 30);
                        turnFlag1 = 1;
                        gwidth = 1024;
                        gheight = 1280;
                    }
                    else if (turnFlag1 == 1)
                    {
                        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_960_1280, 30);
                        turnFlag1 = 2;
                        gwidth = 960;
                        gheight = 1280;
                    }
                    else if (turnFlag1 == 2)
                    {
                        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_512_640, 30);
                        turnFlag1 = 3;
                        gwidth = 512;
                        gheight = 640;
                    }
                    else if (turnFlag1 == 3)
                    {
                        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
                        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_480_640, 30);
                        turnFlag1 = 0;
                        gwidth = 480;
                        gheight = 640;
                    }
                }
                printf("mx6300 stream on end\n", i);
                if (ret < 0)
                {
                    printf("mx6300 stream control failed\n");
                }
                else
                {
                    if (value != 0)
                    {
                        capture_cam_raw(1);
                    }
                }
            }
            break;
        case 'R':
            fflush(stdin);
            printf("write ahb operation \n");
            printf("please input addr and value:");
            ret = scanf("%x %x", &addr_ahb, &addr_value);
            ret = Mx6300_write_ahb(addr_ahb, addr_value);
            if (ret < 0)
            {
                printf("mx6300 write ahb failed\n");
            }
            break;
        case 'S':
            fflush(stdin);
            printf("read ahb operation \n");
            printf("please input addr :");
            ret = scanf("%x", &addr_ahb);
            ret = Mx6300_read_ahb(addr_ahb, &addr_value);
            if (ret < 0)
            {
                printf("mx6300 write ahb failed\n");
            }
            else
            {
                printf("the value is 0x%x(addr=0x%x)\n", addr_value, addr_ahb);
            }
            break;
        case 'T':
            fflush(stdin);
            uint32_t base_addr;
            printf("set base addr for mx6300 \n");
            printf("please input base addr :");
            ret = scanf("%x", &base_addr);
            obc_sl_setBaseAddr(base_addr);
            break;
        case 'U':
            printf("set laser current\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_laser_current(value);
            if (ret < 0)
            {
                printf("set laser current failed\n");
            }
            break;
        case 'V':
            printf("get laser current\n");
            uint32_t laser_current;
            ret = Mx6300_get_laser_current(&laser_current);
            if (ret < 0)
            {
                printf("get laser current failed\n");
            }
            else
            {
                printf("laser current:%d\n", laser_current);
            }
            break;
        case 'W':
            printf("set LDP enable status\n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ldp_enable(value);
            if (ret < 0)
            {
                printf("set LDP enable status failed\n");
            }
            break;
        case 'X':
            printf("get LDP enable status\n");
            uint8_t ldp_enable;
            ret = Mx6300_get_ldp_enable(&ldp_enable);
            if (ret < 0)
            {
                printf("get LDP enable status failed\n");
            }
            else
            {
                printf("LDP enable status:%d\n", ldp_enable);
            }
            break;
        case 'Y':
            printf("set LDP threshold \n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_ldp_scale(value);
            if (ret < 0)
            {
                printf("set LDP enable status failed\n");
            }
            break;
        case 'Z':
            printf("get LDP  threshold\n");
            uint32_t ldp_scale;
            ret = Mx6300_get_ldp_scale(&ldp_scale);
            if (ret < 0)
            {
                printf("get LDP threshold failed\n");
            }
            else
            {
                printf("LDP threshold:%d\n", ldp_scale);
            }
            break;
        case 'a':
            printf("get LDP  protected status\n");
            uint8_t ldp_protect;
            ret = Mx6300_get_ldp_protect_status(&ldp_protect);
            if (ret < 0)
            {
                printf("get LDP protected status failed\n");
            }
            else
            {
                printf("LDP protected status:%d\n", ldp_protect);
            }
            break;
        case 'b':
            printf("set depth mirror \n");
            fflush(stdin);
            printf("please input  value\n");
            ret = scanf("%x", &value);
            ret = Mx6300_set_depth_mirror(value);
            if (ret < 0)
            {
                printf("set depth mirror failed\n");
            }
            break;
        case 'c':
            printf("get depth mirror\n");
            uint32_t mirror;
            ret = Mx6300_get_depth_mirror(&mirror);
            if (ret < 0)
            {
                printf("get depth mirror failed\n");
            }
            else
            {
                printf("depth mirror:%d\n", mirror);
            }
            break;
        case 'd':
            printf("send rectify params\n");
            ret = obc_sl_send_rectify_params();
            if (ret < 0)
            {
                printf("send rectify params failed\n");
            }
            break;
        case 'e':
            printf("calibrate ldp\n");
            ret = Mx6300_set_ldp_calibrate(1);
            if (ret < 0)
            {
                printf("calibrate ldp failed\n");
            }
            break;
        case 'f':
            printf("write ldp calibrate data\n");
            uint8_t data[16];
            for (int i = 0; i < 16; i++)
            {
                data[i] = 0x10 + i;
            }
            ret = Mx6300_write_ldp_calibrate_data(data);
            if (ret < 0)
            {
                printf("write ldp calibrate data failed\n");
            }
            break;
        case 'g':
            printf("capture depth raw data\n");
            ret = switch_resolution(STREAM_DEPTH_OPEN, RES_1024_1280, 30);
            gwidth = 1024;
            gheight = 1280;
            if (ret < 0)
            {
                printf("switch resolution failed\n");
            }
            capture_cam_raw(5);
            break;
        case 'h':
            printf("please input loop count\n");
            scanf("%d", &value);
            for (int i = 0; i < value; i++)
            {
                if (sl_stream_off() < 0)
                {
                    printf("off stream failed!\n");
                }
                //2,switch res depth 960 1280
                if (switch_resolution(STREAM_DEPTH_OPEN, RES_960_1280, 30) < 0)
                {
                    printf("off stream failed!\n");
                }
                //3,start stream
                if (sl_stream_on(STREAM_DEPTH) < 0)
                {
                    printf("on stream failed!\n");
                }

                //4,get pictures
                capture_cam_raw(1);
            }

            break;
        case 'i':
            printf("get temperature of mx6300 component\n");
            Componet_temp temp;
            ret = Mx6300_get_componet_temp(&temp);
            if (ret < 0)
            {
                printf("get temperature of mx6300 failed\n");
                break;
            }
            printf("temperature(ldm=%f, ir=%f, rgb=%f)\n", temp.ldm_temp, temp.ir_temp, temp.rgb_temp);
            break;
        default:
            break;
        }
        ch = (char)getchar();
    }
}
static int find_pra_index_by_name(char *name, int argc, char *argv[])
{
    int i = 0;
    for (i = 0; i < argc; i++)
    {
        if (!strcmp(name, argv[i]))
        {
            log_always("find pra %s @ %d", name, i);
            return i;
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int ret = 0;
    /* download firmware to mx6300 */
    // int spifd =obc_sl_spi_open();
    /* 0。 cat usr config params */
    //cam_get_usr_cfg(argc, argv);
    sl_usr_cfg_ppl_t cfg_ppl = {0};
    /*g_dev.cam_pipeline_cfg.cam_id =0;
  g_dev.cam_pipeline_cfg.input_vidio_res.width =640;
  g_dev.cam_pipeline_cfg.input_vidio_res.height =400;
  g_dev.cam_pipeline_cfg.fps =30;
  g_dev.cam_pipeline_cfg.subsample_rate = 15;*/
    //flash_ops();
    // printf("flash ops over\n");
    //return 0;
    int pra_index = 0;
#if 0
     int init=0;
     pra_index = find_pra_index_by_name("--pipeline", argc, argv);
    if (pra_index > 0)
    {
        init = !strcmp(argv[pra_index + 1],"init");
        log_always("will pipeline  be inited(init=%d)",init);
    }
#endif
    int stream = -1;
    pra_index = find_pra_index_by_name("--stream", argc, argv);
    if (pra_index > 0)
    {
        if (strcmp(argv[pra_index + 1], "ir") == 0)
        {
            stream = 1;
        }
        else if (strcmp(argv[pra_index + 1], "depth") == 0)
        {
            stream = 2;
        }
        else if (strcmp(argv[pra_index + 1], "no") == 0)
        {
            stream = -2;
        }
        log_always("stream control operation(stream=%d)", stream);
    }

    //default action
    cfg_ppl.cam_id = 0;
    cfg_ppl.input_vidio_res.width = 1280;
    gwidth = 1280;
    cfg_ppl.input_vidio_res.height = 1024;
    gheight = 1024;
    cfg_ppl.fps = 30;
    cfg_ppl.subsample_rate = 15;
    cfg_ppl.stream_type = STREAM_IR;
    switch (stream)
    {
    case 1:
        cfg_ppl.input_vidio_res.width = 1280;
        gwidth = 1280;
        cfg_ppl.input_vidio_res.height = 1024;
        gheight = 1024;
        cfg_ppl.fps = 30;
        cfg_ppl.subsample_rate = 15;
        cfg_ppl.stream_type = STREAM_IR;
        break;
    case 2:
        cfg_ppl.input_vidio_res.width = 1024;
        gwidth = 1024;
        cfg_ppl.input_vidio_res.height = 1280;
        gheight = 1280;
        cfg_ppl.fps = 30;
        cfg_ppl.subsample_rate = 15;
        cfg_ppl.stream_type = STREAM_DEPTH;
        break;
    default:
        break;
    }

    /* 1. init tof cam_src pipeline */
    //ret |= init_sl_cam(&g_dev.cam_pipeline_cfg);
    if (stream != -2)
    {
        ret = init_sl_cam(&cfg_ppl);
    }

    /* 2. open tof cam_src pipeline to READY */
    //ret |= open_sl_cam(g_dev.sl_cam_id);.
#if 0
    usleep(40000);
    if(stream==1)
    {
        sl_stream_on(STREAM_IR_OPEN);
    }
    else if(stream==2)
    {
          sl_stream_on(STREAM_DEPTH_OPEN);
    }
#endif
    //capture_cam_raw(1);

#if 0
    {
        //ret = Mx6300_Stream_control(STREAM_DEPTH_OPEN);
        ret = switch_resolution(STREAM_DEPTH_OPEN, RES_1024_1280,30);
        gwidth = 1024;
        gheight = 1280;
        //capture_cam_raw(1);
    }
    {
        //ret = Mx6300_Stream_control(STREAM_IR_OPEN);
        ret = switch_resolution(STREAM_IR_OPEN, RES_SXGA,30);
        gwidth = 1280;
        gheight = 1024;
        //capture_cam_raw(1);
    }
#endif
    test_command();
    deinit_sl_cam(&cfg_ppl);
    // obc_sl_spi_close(spifd);
    //close_sl_cam(g_dev.sl_cam_id);
    //remove_cam();
}

#if 0
int main1 (int argc, char *argv[])
{
    int pra_index=0;
    cam_raw_config_t obj;
    uint32_t frame_count = 1;
    uint32_t exp_time = 0;
    ar_mm_handle_t cur_handle = NULL;
    int cam_fd;
    int camera_id = 0;
    int cam_status = 0;


    pra_index=find_pra_index_by_name("--help",argc,argv);
	if(pra_index>0)
	{
	    printf("--help: show this help info\n");
		printf("--size w h: set cam out w && h,default is 1280 962\n");
		printf("--cam_id id: set cam id,default is 0\n");
		printf("--count frame_count: set the dump frames,the default is 1\n");
		printf("--subsample_rate  [rate]: set vif view subsample \n");
        printf("--fps: fps of camera \n");
        printf("--open: open obc_camera \n");
        printf("--close: close obc_camera \n");
        printf("--on: stream on \n");
        printf("--off: stream off \n");
        printf("--save: capture raw stream \n");
        printf("--init: init cam_src pipeline \n");
        printf("--remove: remove cam_src pipeline \n");
        printf("--test1: test all API in one thread n");
		return 0;
	}
    pra_index = find_pra_index_by_name("--count", argc, argv);
    if(pra_index > 0){
        frame_count = atoi(argv[pra_index + 1]);
        printf("frame count: %d\n", frame_count);
    }

    /* camera_src init test */
    pra_index = find_pra_index_by_name("--init", argc, argv);
    if(pra_index > 0){
        cam_get_usr_cfg(argc, argv);
        if(init_sl_cam(&g_dev.cam_pipeline_cfg) < 0){
            printf("init camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera open test */
    pra_index = find_pra_index_by_name("--open", argc, argv);
    if(pra_index > 0){
        if(open_sl_cam(g_dev.sl_cam_id) < 0){
            printf("Open camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera close test */
    pra_index = find_pra_index_by_name("--close", argc, argv);
    if(pra_index > 0){
        if(close_sl_cam(g_dev.sl_cam_id) < 0){
            printf("Close camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera stream on test */
    pra_index = find_pra_index_by_name("--on", argc, argv);
    if(pra_index > 0){
        if(sl_cam_stream_on() < 0){
            printf("on stream failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera stream off test */
    pra_index = find_pra_index_by_name("--off", argc, argv);
    if(pra_index > 0){
        if(sl_cam_stream_off() < 0){
            printf("off stream failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera_src remove test */
    pra_index = find_pra_index_by_name("--remove", argc, argv);
    if(pra_index > 0){
        if(remove_cam() < 0){
            printf("remove camera failed!\n");
            // return -1;
        }
        // return 0;
    }

    /* camera_src test all API */
    pra_index = find_pra_index_by_name("--test1", argc, argv);
    if(pra_index > 0){
        if(one_thread_test(argc,argv) < 0){
            printf("one_thread_test failed!\n");
        }
    }

    /* camera capture picture test */
    pra_index = find_pra_index_by_name("--save", argc, argv);
    if(pra_index > 0){

        capture_cam_raw(frame_count);
 
    }
    return 0;
}
#endif