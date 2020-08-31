#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <unistd.h>
#include <getopt.h>
#include <errno.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <linux/fb.h>
#include <linux/ar_framebuffer_def.h>
#include <getopt.h>
// #include <time.h>



#define TEST_CURSOR_LOCATION  ("/mnt/1.ico")

struct fb_config
{
  int fd;

  int width;
  int height;

  int height_virtual;

  int draw_x_offset;
  int draw_y_offset;
  int draw_width;
  int draw_height;

  int bpp;
  int stride;

  int red_offset;
  int red_length;

  int green_offset;
  int green_length;

  int blue_offset;
  int blue_length;

  int transp_offset;
  int transp_length;

  int buffer_num;

  char cursor_icon[256];
  arfb_cursor_pos_t cursor_pos;

  char *data;
  char *base;
};

void dump_vscreeninfo(struct fb_var_screeninfo *fvsi)
{
  printf("======= FB VAR SCREENINFO =======\n");
  printf("xres: %d\n", fvsi->xres);
  printf("yres: %d\n", fvsi->yres);
  printf("yres_virtual: %d\n", fvsi->yres_virtual);
  printf("buffer number: %d\n", fvsi->yres_virtual / fvsi->yres);
  printf("bpp : %d\n", fvsi->bits_per_pixel);
  printf("red bits    :\n");
  printf("    offset   : %d\n", fvsi->red.offset);
  printf("    length   : %d\n", fvsi->red.length);
  printf("    msb_right: %d\n", fvsi->red.msb_right);
  printf("green bits  :\n");
  printf("    offset   : %d\n", fvsi->green.offset);
  printf("    length   : %d\n", fvsi->green.length);
  printf("    msb_right: %d\n", fvsi->green.msb_right);
  printf("blue bits   :\n");
  printf("    offset   : %d\n", fvsi->blue.offset);
  printf("    length   : %d\n", fvsi->blue.length);
  printf("    msb_right: %d\n", fvsi->blue.msb_right);
  printf("transp bits :\n");
  printf("    offset   : %d\n", fvsi->transp.offset);
  printf("    length   : %d\n", fvsi->transp.length);
  printf("    msb_right: %d\n", fvsi->transp.msb_right);

  printf("=================================\n");
}

void dump_fscreeninfo(struct fb_fix_screeninfo *ffsi)
{
  printf("======= FB FIX SCREENINFO =======\n");
  printf("id          : %s\n", ffsi->id);
  printf("smem_start  : 0x%08lX\n", ffsi->smem_start);
  printf("smem_len    : %u\n", ffsi->smem_len);
  printf("line_length : %u\n", ffsi->line_length);
  printf("=================================\n");
}

void plot_pixel(struct fb_config *fb, int x, int y, int r, int g, int b, int a)
{
  int offset = (y * fb->stride) + (x * (fb->bpp >> 3));
  int r_o = fb->red_offset/fb->red_length;
  int g_o = fb->green_offset/fb->green_length;
  int b_o = fb->blue_offset/fb->blue_length;
  *(fb->data + offset + r_o) = r;
  *(fb->data + offset + g_o) = g;
  *(fb->data + offset + b_o) = b;
  if (fb->transp_length != 0)
    *(fb->data + offset + fb->transp_offset/fb->transp_length) = a;
}

void draw_rect(struct fb_config *fb, int x, int y, int w, int h, int r, int g, int b, int a)
{
  int dx, dy;

  for (dy = 0; dy < h; dy++) {
    for (dx = 0; dx < w; dx++) {
      plot_pixel(fb, x + dx, y + dy, r, g, b, a);
    }
  }
}

int red_offset, red_length;
int green_offset, green_length;
int blue_offset, blue_length;
int transp_length, transp_offset;
int y_stride, bpp;

void clear_screen(struct fb_config *fb, int r, int g, int b, int a)
{
  draw_rect(fb, fb->draw_x_offset, fb->draw_y_offset, fb->draw_width, fb->draw_height, r, g, b, a);
}

void cmp_test_plot_pixel(char *buf, int x, int y, int r, int g, int b, int a)
{
  int offset = (y * y_stride) + (x * (bpp >> 3));
  int r_o = red_offset/red_length;
  int g_o = green_offset/green_length;
  int b_o = blue_offset/blue_length;
  *(buf + offset + r_o) = r;
  *(buf + offset + g_o) = g;
  *(buf + offset + b_o) = b;
  if (transp_length != 0)
    *(buf + offset + transp_offset/transp_length) = a;
}

void cmp_test_draw_rect(char *buf, int x, int y, int w, int h, int r, int g, int b, int a)
{
  int dx, dy;

  for (dy = 0; dy < h; dy++) {
    for (dx = 0; dx < w; dx++) {
      cmp_test_plot_pixel(buf, x + dx, y + dy, r, g, b, a);
    }
  }
}

void cmp_test_clear_screen(char *buf, int x, int y, int w, int h, int r, int g, int b, int a)
{
  cmp_test_draw_rect(buf, x, y, w, h, r, g, b, a);
}

void usage(const char *argv_0)
{
  printf("\nUsage %s: [-r<red>] [-g<green>] [-b<blue>] [-B<border>] [-i<buffer index>]\n", argv_0);
  printf("-f [file_name]: read a bin file to show\n");
  printf("  All colors default to 0xff\n");
  printf("  The border color applies to all rgb and is 10 pixels wide\n");
  printf("  If border is not provided, none is drawn.\n");
  printf("  The index defaults to 0, if your FB has more than 1 buffers, you can set it.\n");
  printf("  If set the index to -1, we will use all buffers for 20 times.\n");
  exit(1);
}

void print_times(clock_t real, struct tms *start, struct tms *end)
{
  static long clktck = 0;
  if( (clktck = sysconf(_SC_CLK_TCK)) < 0 )
  {
    printf("sysconf err\n");
    return;
  }

  printf("real %f\n", real/(double)clktck);
  printf("usr cpu %f\n", (end->tms_utime - start->tms_utime)/(double)clktck);
  printf("sys cpu %f\n", (end->tms_stime - start->tms_stime)/(double)clktck);
  printf("c usr cpu %f\n", (end->tms_cutime - start->tms_cutime)/(double)clktck);
  printf("c sys cpu %f\n", (end->tms_cstime - start->tms_cstime)/(double)clktck);
}

int main(int argc, char **argv)
{
  int fd;
  unsigned long offset;
  struct fb_var_screeninfo fvsi;
  struct fb_fix_screeninfo ffsi;
  struct fb_config fb;
  int red = 0xff;
  int green = 0xff;
  int blue = 0xff;
  int alpha = 0xff;
  int border = -1;
  int opt;
  int index = 0;
  int loop = 0;

  int draw_x_offset = 0;
  int draw_y_offset = 0;
  int draw_width = 0;
  int draw_height = 0;
  char *file=NULL;

  while ((opt = getopt(argc, argv, "x:y:W:H:r:g:b:a:B:i:h:f")) != -1) {
    switch (opt) {

    case 'x':
      draw_x_offset= 0x00 | strtol(optarg, NULL, 0);
      break;
    case 'y':
      draw_y_offset= 0x00 | strtol(optarg, NULL, 0);
      break;
    case 'W':
      draw_width= 0x00 | strtol(optarg, NULL, 0);
      break;
    case 'H':
      draw_height= 0x00 | strtol(optarg, NULL, 0);
      break;

    case 'r':
      red = 0xff & strtol(optarg, NULL, 0);
     break;
    case 'g':
      green = 0xff & strtol(optarg, NULL, 0);
      break;
    case 'b':
      blue = 0xff & strtol(optarg, NULL, 0);
      break;
    case 'a':
      alpha = 0xff & strtol(optarg, NULL, 0);
      break;

    case 'B':
      border = 0xff & strtol(optarg, NULL, 0);
      break;
    case 'i':
      index = strtol(optarg, NULL, 0);
      break;
	case 'f':
		file = argv[2];
     break;
    default:
      usage(argv[0]);
      break;
    }
  }

  printf("param draw %d-%d-%d-%d\n", draw_x_offset, draw_y_offset, draw_width, draw_height);
  printf("param bgr@ %d-%d-%d-%d\n", blue, green, red, 255);
  printf("param index %d - border %d\n", index, border);

  memset(&fb, 0, sizeof(fb));

  if ((fd = open("/dev/fb0", O_RDWR)) < 0) {
    perror("open");
    exit(1);
  }

  if (ioctl(fd, FBIOGET_VSCREENINFO, &fvsi) < 0) {
    perror("ioctl(FBIOGET_VSCREENINFO)");
    close(fd);
    exit(1);
  }

  dump_vscreeninfo(&fvsi);

  if (ioctl(fd, FBIOGET_FSCREENINFO, &ffsi) < 0) {
    perror("ioctl(FBIOGET_FSCREENINFO)");
    close(fd);
    exit(1);
  }

  dump_fscreeninfo(&ffsi);

  fb.fd = fd;
  fb.width = fvsi.xres;
  fb.height = fvsi.yres;
  fb.height_virtual = fvsi.yres_virtual;
  fb.bpp = fvsi.bits_per_pixel;
  fb.stride = ffsi.line_length;
  fb.red_offset = fvsi.red.offset;
  fb.red_length = fvsi.red.length;
  fb.green_offset = fvsi.green.offset;
  fb.green_length = fvsi.green.length;
  fb.blue_offset = fvsi.blue.offset;
  fb.blue_length = fvsi.blue.length;
  fb.transp_offset = fvsi.transp.offset;
  fb.transp_length = fvsi.transp.length;
  fb.buffer_num = fb.height_virtual / fb.height;

  if(draw_x_offset<0)
  {
    fb.draw_x_offset = 0;
  }
  else
  {
    fb.draw_x_offset = draw_x_offset;
  }
  if(draw_y_offset<0)
  {
    fb.draw_y_offset = 0;
  }
  else
  {
    fb.draw_y_offset = draw_y_offset;
  }
  if(draw_width<=0)
  {
    fb.draw_width = fb.width;
  }
  else
  {
    fb.draw_width = draw_width;
  }
  if(draw_height<=0)
  {
    fb.draw_height = fb.height;
  }
  else
  {
    fb.draw_height = draw_height;
  }

  printf("param draw %d-%d-%d-%d\n", fb.draw_x_offset, fb.draw_y_offset, fb.draw_width, fb.draw_height);

  if (index == -1) {
    index = 0;
    loop = 20;
  }
  if (index > fb.buffer_num - 1 || index < 0) {
    printf("Invalid index.\n");
    exit(1);
  }

  printf("mmap len 0x%x, prot 0x%x flags 0x%x\n", ffsi.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED);
  fb.base = (char *)mmap((caddr_t) NULL, ffsi.smem_len, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

  if (fb.base == (char *)-1) {
    perror("mmap");
    close(fd);
    exit(1);
  }

  printf("mmap base 0x%x\n", fb.base);

  printf("[%d] ",__LINE__);

  clock_t start, finish;
  clock_t tmp_start[20], tmp_finish[20];
  struct tms tms_start[20];
  struct tms tms_end[20];


  int test_len = 640*480*4;
  char *test_buf = malloc(test_len);
  if(file){
  	//read a file to show
    int fd=open(file,O_RDONLY);
  	printf("file =%s, fd=%d",file,fd);
	if(fd<0)
	{
	  printf("can not open file");
	  return 0;
	}
    read(fd,fb.base,fb.width*fb.height*fb.bpp/8);
	close(fd);

  }else if(test_buf)
  {
    red_offset = fb.red_offset;
    red_length = fb.red_length;
    green_offset = fb.green_offset;
    green_length = fb.green_length;
    blue_offset = fb.blue_offset;
    blue_length = fb.blue_length;
    transp_length = fb.transp_length;
    transp_offset = fb.transp_offset;
    y_stride = 640*4; //fb.stride;
    bpp = fb.bpp;

    start = clock();
    // memset(test_buf, 0x8A, test_len);
    if (border == -1) {
      cmp_test_clear_screen(test_buf, 0, 0, 640, 480, red, green, blue, alpha);
    }
    else {
      cmp_test_clear_screen(test_buf, 0, 0, 640, 480, border, border, border, 255);
      cmp_test_draw_rect(test_buf, 10, 10, 640- 20, 480 - 20, red, green, blue, alpha);
    }
    finish = clock();
    // double test_time = (double)(finish-start)/CLOCKS_PER_SEC;
    // printf("malloc %f secondes\n",test_time);

  }

  strncpy(fb.cursor_icon, TEST_CURSOR_LOCATION, 256);
  printf("set cursor icon %s at 0x%x\n", fb.cursor_icon, fb.cursor_icon);
  ioctl(fb.fd, AR_FRAMEBUFFER_IO_CURSOR_SET_ICON, fb.cursor_icon);

  printf("set cursor display\n");
  ioctl(fb.fd, AR_FRAMEBUFFER_IO_CURSOR_DISPLAY_ENABLE, 1);

  fb.cursor_pos.x = fb.draw_x_offset + fb.draw_width/2;
  fb.cursor_pos.y = fb.draw_y_offset + fb.draw_height/2;

  printf("set cursor pos %d, %d\n", fb.cursor_pos.x, fb.cursor_pos.x);
  ioctl(fb.fd, AR_FRAMEBUFFER_IO_CMD_CURSOR_SET_POS, &fb.cursor_pos);

  offset = (unsigned long) ffsi.smem_start % (unsigned long) getpagesize();

  printf("offset %d\n", offset);

  start = clock();

  while(loop&&!file)
  {
    tmp_start[loop-1]=times(&tms_start[loop-1]);

    fb.data = fb.base + offset + (fb.stride * fb.height) * index;
    if (border == -1) {
      clear_screen(&fb, red, green, blue, alpha);
    }
    else {
      clear_screen(&fb, border, border, border, 255);

      // draw a rect 10 pixels in from each border in the color chosen
      // draw_rect(&fb, 10, 10, fb.width - 20, fb.height - 20, red, green, blue, alpha);
    }

    tmp_finish[loop-1]=times(&tms_end[loop-1]);

    fvsi.yoffset =  offset + index * fvsi.yres;
    // printf("%d data addr = %p, yoffset = %d\n", index, fb.data, fvsi.yoffset);
    ioctl(fb.fd, FBIOPAN_DISPLAY, &fvsi);
    if (fb.buffer_num > 1)
      index = (index + 1) % fb.buffer_num;
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;

    fb.cursor_pos.x = fb.draw_x_offset+ (fb.cursor_pos.x-fb.draw_x_offset + (fb.draw_width/20) )%fb.draw_width;
    fb.cursor_pos.y = fb.draw_y_offset+ (fb.cursor_pos.y-fb.draw_y_offset + (fb.draw_height/20) )%fb.draw_height;
    // printf("pos %d, %d\n",  fb.cursor_pos.x, fb.cursor_pos.y);
    if(fb.cursor_pos.x < fb.draw_x_offset+ (fb.draw_width/2) )
    {
      // printf("disable display\n");
      ioctl(fb.fd, AR_FRAMEBUFFER_IO_CURSOR_DISPLAY_ENABLE, 0);
    }
    else
    {
      // printf("enable display\n");
      ioctl(fb.fd, AR_FRAMEBUFFER_IO_CURSOR_DISPLAY_ENABLE, 1);
      ioctl(fb.fd, AR_FRAMEBUFFER_IO_CMD_CURSOR_SET_POS, &fb.cursor_pos);
    }


    // tmp_finish[loop-1]=times(&tms_end[loop-1]);

    // if(loop>0)
    {
      loop--;
    }
  }

  finish = clock();

  for(int each=19;each>=0;each--)
  {
    print_times(tmp_finish[each] - tmp_start[each], &tms_start[each], &tms_end[each]);
  }

  double duration = (double)(finish-start)/CLOCKS_PER_SEC;
  printf("20 frame %f secondes\n", duration);

SKIP_DRAW:

  close(fd);

  return 0;
}

