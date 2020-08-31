#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <math.h>

#include <linux/fb.h>
#include <linux/ar_framebuffer_def.h>

#define EVENT_PATH 		"/dev/input/event0"
#define FB_PATH			"/dev/fb0"
#define TEST_CURSOR_LOCATION	"/local/usr/bin/1.ico"

#define MAX_X			(1920 - 1)
#define MAX_Y			(1080 - 1)

volatile int 	abs_x = 0;
volatile int 	abs_y = 0;


int 		fb_fd = -1;

int set_cursor_location(int x, int y)
{
	arfb_cursor_pos_t cursor_pos;
	cursor_pos.x = x;
	cursor_pos.y = y;

	ioctl(fb_fd, AR_FRAMEBUFFER_IO_CMD_CURSOR_SET_POS, &cursor_pos);

	return 0;
}

int rel_2_abs_x(int value)
{
	abs_x += value;
	if(abs_x < 0)
		abs_x = 0;

	if(abs_x > MAX_X)
		abs_x = MAX_X;

	set_cursor_location(abs_x, abs_y);

	return abs_x;
}

int rel_2_abs_y(int value)
{
	abs_y += value;
	if(abs_y < 0)
                abs_y = 0;

        if(abs_y > MAX_Y)
                abs_y = MAX_Y;

	set_cursor_location(abs_x, abs_y);

        return abs_y;
}

int detect_event(struct input_event mouse_event)
{
	int ret = -1;
	//printf("time: %lld(s) %lld(us)\n", mouse_event.time.tv_sec, mouse_event.time.tv_usec);
	//printf("type: %08x code: %08x value: %d\n", mouse_event.type, mouse_event.code, mouse_event.value);

	switch(mouse_event.type)
	{
		case EV_SYN:
			break;// do nothing

		case EV_KEY:
			switch(mouse_event.code)
			{
				case BTN_LEFT:
					printf("mouse left button %s\n", mouse_event.value ? "on" : "off");
					break;
				case BTN_RIGHT:
					printf("mouse right button %s\n", mouse_event.value ? "on" : "off");
					break;
				case BTN_MIDDLE:
					printf("mouse middle button %s\n", mouse_event.value ? "on" : "off");
                                        break;

				default:
					printf("unsupport!\n");
                        		break;
			}
			break;

		case EV_REL:
			switch(mouse_event.code)
                        {
				case REL_X:
					rel_2_abs_x(mouse_event.value);
					//printf("mouse x move %s %d unit(abs:%d)\n", 
					//	mouse_event.value > 0 ? "right" : "left", abs(mouse_event.value), 
					//	rel_2_abs_x(mouse_event.value));
                                        break;

				case REL_Y:
					rel_2_abs_y(mouse_event.value);
                                        //printf("mouse y move %s %d unit(abs:%d)\n", 
					//	mouse_event.value > 0 ? "down" : "up", abs(mouse_event.value), 
					//	rel_2_abs_y(mouse_event.value));
                                        break;

				case ABS_WHEEL:
					printf("mouse wheel move %s %d unit\n", mouse_event.value > 0 ? "up" : "down", abs(mouse_event.value));
                                        break;

				default:
                                        printf("unsupport!\n");
                                        break;
			}
			break;

		case EV_MSC:
			//switch(mouse_event.code)
			break;// do nothing

		case EV_ABS:
		case EV_SW:
		case EV_LED:
		case EV_SND:
		case EV_REP:
		case EV_FF:
		case EV_PWR:
		case EV_FF_STATUS:
			printf("unsupport!\n");
			break;

		default:
			printf("unknown type!\n");
			break;
	}

	return 0;	
}

int main()
{
	int mouse_event_fd = -1;
	int ret, bytes;
	struct input_event mouse_event;
	unsigned char data[10];

	mouse_event_fd = open(EVENT_PATH, O_RDWR);
	if(mouse_event_fd < 0)
        {
                printf("mouse_event_fd open failed!\n");
                return -1;
        }

	printf("mouse_event_fd: %d\n", mouse_event_fd);

	
	if ((fb_fd = open(FB_PATH, O_RDWR)) < 0) 
	{
		printf("fb_fd open failed!\n");;
		return -1;
	}

	ioctl(fb_fd, AR_FRAMEBUFFER_IO_CURSOR_SET_ICON, TEST_CURSOR_LOCATION);

	ioctl(fb_fd, AR_FRAMEBUFFER_IO_CURSOR_DISPLAY_ENABLE, 1);

	while(bytes = read(mouse_event_fd, &mouse_event, sizeof(mouse_event)))
	{
		detect_event(mouse_event);
		/*int i;
                printf("input bytes: %d, data: ", bytes);
                for(i = 0; i < bytes; ++i)
                {
                        printf("0x%02x, ", data[i]);
                }
                printf("\n");*/
	}

	close(mouse_event_fd);

	return 0;	
}
