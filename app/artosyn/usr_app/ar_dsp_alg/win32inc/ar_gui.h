/** \addtogroup gui
 *  @{
 */

/**
 * @file
 * @example <app/artosyn/usr_test/test_ar_gui_random/test_ar_gui_random.c>
 * @example <app/artosyn/usr_test/test_ar_gui/test_ar_gui.c>
 */
#ifndef __AR_GUI_H__
#define __AR_GUI_H__

#ifdef __cplusplus
extern "C" {
#endif
///////////////////////////////////////////////

/**
 * @brief      The max canvas munber of a single gui device.
 *
 * @note  The user shouldn't change this value.
 */
#define AR_GUI_MAX_CANVAS_NUM (6)

/**
 * @brief      The max line munber of a single canvas.
 *
 * @note  The user shouldn't change this value.
 */
#define AR_GUI_CANVAS_MAX_LINE_NUM (100)

/**
 * @brief      The max multi points munber of a single canvas.
 *
 * @note  The user shouldn't change this value.
 */
#define AR_GUI_CANVAS_MAX_MULTI_POINT_NUM (100)

/**
 * @brief      The max polygon munber of a single canvas.
 *
 * @note  The user shouldn't change this value.
 */
#define AR_GUI_CANVAS_MAX_POLYGON_NUM (100)

/**
 * @brief      The max BMP image munber of a single gui device.
 *
 * @note  The user shouldn't change this value.
 */
#define AR_GUI_CANVAS_MAX_BMP_NUM (10)

/**
 * @brief      The max dot matrix munber of a single canvas.
 *
 * @note  The user shouldn't change this value.
 */
#define AR_GUI_CANVAS_MAX_DOTMTX_AND_ASCII_SUM_NUM (100)

/**
 * @brief      The max english string munber of a single canvas.
 *
 * @note  The user shouldn't change this value.
 */
#define AR_GUI_CANVAS_MAX_ASCII_STRING_LEN (32)

/**
 * @brief      The max circle munber of a single canvas.
 *
 * @note  The user shouldn't change this value.
 */
#define AR_GUI_CANVAS_MAX_CIRCLE_NUM (100)

///////////////////////////////////////////////

/**
 * @brief This is the pre-defined color
 */
typedef enum {
    BLACK = 1,  /**< color BLACK Y=0, U=128, V=128 */
    WHITE,  /**< color WHITE Y=255, U=128, V=128 */
    RED,  /**< color RED Y=76, U=84, V=255 */
    GREEN,  /**< color GREEN Y=149, U=43, V=21 */
    PURPLE,  /**< color PURPLE Y=18, U=208, V=114 */
    GRAY,  /**< color GRAY Y=127, U=128, V=128 */
    ORANGE,  /**< color ORANGE Y=151, U=42, V=201 */
    YELLOW,  /**< color YELLOW Y=225, U=0, V=148 */
    BLUE,  /**< color BLUE Y=29, U=255, V=107 */
    LIGHTPINK,  /**< color LIGHTPINK Y=0, U=128, V=128 */
    PINK,  /**< color PINK Y=196, U=81, V=170 */
    CRIMSON,  /**< color CRIMSON Y=212, U=122, V=158 */
    LAVENDERBLUSH,  /**< Reserved */
    PALEVIOLERED,  /**< Reserved */
    HOTPINK,  /**< Reserved */
    DEEPPINK,  /**< Reserved */
    ORCHID,  /**< Reserved */
    THISTLE,  /**< Reserved */
    PLUM,  /**< Reserved */
    VIOLET,  /**< Reserved */
    SLIPPER,  /**< Reserved */
    WIRE,  /**< Reserved */
    SOCK,  /**< Reserved */
    CUSTOMIZE   /**< Reserved */
} ar_gui_predefined_color_en;

///////////////////////////////////////////////

/**
 * @brief This structure is used to store the resolution value
 */
typedef struct
{
    int width;  /**< the width of image in pixels */
    int height;  /**< the height of image in pixels */
} ar_gui_res_t;

/**
 * @brief This structure is the debug configure structure.
 */
typedef struct
{
    int log_enable;  /**< to enable/disable log output */
    int gui_enable;  /**< to enable/disable gui draw function */
} ar_gui_config_state_t;

/**
 * @brief This structure is used to store coordinates. The origin of coordinates is the top-left point.
 */
typedef struct
{
    int x;  /**< the value of x axis in pixels */
    int y;  /**< the value of y axis in pixels */
} ar_gui_point;

/**
 * @brief This structure is used to store the YUV space color
 */
typedef struct
{
    unsigned char m_Y;  /**< the Y value of YUV space color */
    unsigned char m_U;  /**< the U value of YUV space color */
    unsigned char m_V;  /**< the V value of YUV space color */
} ar_gui_color_space_yuv;

///////////////////////////////////////////////

/**
 * @brief      This function is used to open ar_gui device
 *
 * @param  name  The name is the ar_gui device name string which is something like "/dev/user_compositor-0".
 *
 * @retval     0         fail
 * @retval     others    success to open and the returned value is the device handle
 *
 * @note       The returned handle is thread-safe.
 *
 */
unsigned int ar_gui_open(const char *name);

/**
 * @brief      This function is used to close the device opened by the function \ref ar_gui_open "ar_gui_open".
 *
 * @param  fd    The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 *
 */
int ar_gui_close(unsigned int fd);

/**
 * @brief      This funciton is used to get resolution information.
 *
 * @param      fd     The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param      param  refer to \ref ar_gui_res_t "ar_gui_res_t" for details
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 *
 */
int ar_gui_get_res(unsigned int fd, ar_gui_res_t *param);

/**
 * @brief      This function is used to debug.
 *
 * @param      fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param      param           ref to \ref ar_gui_res_t  "ar_gui_config_state_t"  for details
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 */
int ar_gui_config_state(unsigned int fd, ar_gui_config_state_t *param);

/**
 * @brief      This funciton is used to debug.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  cache_enable    to enable/disable cache control
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 */
int ar_gui_config_cache(unsigned int fd, int cache_enable);

/**
 * @brief      This funcitno is used to create new canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 *
 * @retval     0         fail
 * @retval     others    success to open and the returned value is the created canvas ID
 *
 * @note The canvas ID is thread-safe.
 */
unsigned int ar_gui_create_new_canvas(unsigned int fd);

/**
 * @brief      This functon is used to release the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 */
int ar_gui_release_canvas(unsigned int fd, unsigned int id_canvas);

/**
 * @brief      This function is used to empty the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note This function only affect the specific canvas. The output images won't be affected.
 */
int ar_gui_empty_canvas(unsigned int fd, unsigned int id_canvas);

/**
 * @brief      This function is used to draw the contents of the specific canvas to the output images.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 */
int ar_gui_display_canvas(unsigned int fd, unsigned int id_canvas);

/**
 * @brief      This funciton is used to empty both the specific canvas and the output images.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note This function will affect both the specific canvas and the output images.
 */
int ar_gui_canvas_empty_and_display_clear(unsigned int fd, unsigned int id_canvas);

/**
 * @brief      This function is used to append the specific canvas content to the output images.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 */
int ar_gui_display_canvas_append(unsigned int fd, unsigned int id_canvas);

/**
 * @brief      This function is used to draw a line on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  start_point      The start point of the line(\ref ar_gui_point "ar_gui_point")
 * @param  end_point        The end point of the line(\ref ar_gui_point "ar_gui_point")
 * @param  color_space_yuv  The color of the line(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 * @param  line_width       The line width in pixels
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note This funciton only affect the specific canvas buffer. It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *
 */
unsigned int ar_gui_canvas_draw_line(unsigned int fd\
    , unsigned int id_canvas\
    , ar_gui_point start_point\
    , ar_gui_point end_point\
    , ar_gui_color_space_yuv color_space_yuv\
    , int line_width);

/**
 * @brief      This function is used to draw multi points on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  point_num        The point number in p_points_buff
 * @param  p_points_buff    The points to draw(\ref ar_gui_point "ar_gui_point")
 * @param  color_space_yuv  The color of the points(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note This funciton only affect the specific canvas buffer. It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *
 */
unsigned int ar_gui_canvas_draw_multi_points(unsigned int fd\
    , unsigned int id_canvas\
    , int point_num\
    , ar_gui_point *p_points_buff\
    , ar_gui_color_space_yuv color_space_yuv);

/**
 * @brief      This function is used to draw polygon on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  point_num        The endpoint number in p_points_buff
 * @param  p_points_buff    The endpoints of the polygon(\ref ar_gui_point "ar_gui_point")
 * @param  color_space_yuv  The color of the polygon(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 * @param  closed_shape     1- it will connect the first point with the last point  0- it won't connect the first point with the last point
 * @param  line_width       The line width in pixels
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note This funciton only affect the specific canvas buffer. It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *
 */
unsigned int ar_gui_canvas_draw_polygon(unsigned int fd\
    , unsigned int id_canvas\
    , int point_num \
    , ar_gui_point *p_points_buff \
    , ar_gui_color_space_yuv color_space_yuv \
    , int closed_shape \
    , int line_width);

/**
 * @brief      This function is used to draw a BMP image on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  file_path_len   The length of the BMP image path string
 * @param  p_path_buff     The BMP image path string
 * @param  left_top_point  The left top position of the image\ref ar_gui_point "ar_gui_point")
 * @param  weight          The display weight of the BMP file([0,100])
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note
 *  This funciton only affect the specific canvas buffer.
 *  It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *  This funciton is only support RGB888 format BMP.
 *
 */
unsigned int ar_gui_canvas_draw_BMP(unsigned int fd\
    , unsigned int id_canvas\
    , int file_path_len \
    , char *p_path_buff
    , ar_gui_point left_top_point \
    , int weight);

/**
 * @brief      This function is used to draw dot matrix on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  len_charactor     The length charactor
 * @param  dot_ch_width      The dot char width in pixel
 * @param  dot_ch_height     The dot char height in pixel
 * @param  p_buf_dot_matrix  The buffer of the dot matrix
 * @param  left_top_point    The left top position of the dot matrix
 * @param  dot_color         The color of the dot matrix(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note
 *  This funciton only affect the specific canvas buffer.
 *  It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *  The dot matrix is big endian and aligned to MSB.
 *
 */
unsigned int ar_gui_canvas_draw_dot_matrix(unsigned int fd\
    , unsigned int id_canvas\
    , int len_charactor\
    , int dot_ch_width\
    , int dot_ch_height\
    , unsigned char *p_buf_dot_matrix\
    , ar_gui_point left_top_point\
    , ar_gui_color_space_yuv dot_color);

/**
 * @brief      This function is used to draw dot matrix with background on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  len_charactor     The length charactor
 * @param  dot_ch_width      The dot char width in pixel
 * @param  dot_ch_height     The dot char height in pixel
 * @param  p_buf_dot_matrix  The buffer of the dot matrix
 * @param  left_top_point    The left top position of the dot matrix
 * @param  dot_color         The color of the dot matrix(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 * @param  color_background   The color of the background(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 * @param  weight_background  The weight of the background([0,100])
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note
 *  This funciton only affect the specific canvas buffer.
 *  It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *  The dot matrix is big endian and aligned to MSB.
 *
 */
unsigned int ar_gui_canvas_draw_dot_matrix_with_background(unsigned int fd\
    , unsigned int id_canvas\
    , int len_charactor\
    , int dot_ch_width\
    , int dot_ch_height\
    , unsigned char *p_buf_dot_matrix\
    , ar_gui_point left_top_point\
    , ar_gui_color_space_yuv dot_color\
    , ar_gui_color_space_yuv color_background\
    , int weight_background);

/**
 * @brief      This function is used to draw english string on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  p_string        The buffer of the string
 * @param  left_top_point  The left top position of the string
 * @param  color_str       The color of the string(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note
 *  This funciton only affect the specific canvas buffer.
 *  It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *
 */
unsigned int ar_gui_canvas_draw_string(unsigned int fd\
    , unsigned int id_canvas\
    , char *p_string\
    , ar_gui_point left_top_point\
    , ar_gui_color_space_yuv color_str);

/**
 * @brief      This function is used to draw english string with background on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  p_string        The buffer of the string
 * @param  left_top_point  The left top position of the string
 * @param  color_str       The color of the string(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 * @param  color_background   The color of the background(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 * @param  weight_background  The weight of the background([0,100])
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note
 *  This funciton only affect the specific canvas buffer.
 *  It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *
 */
unsigned int ar_gui_canvas_draw_string_with_background(unsigned int fd\
    , unsigned int id_canvas\
    , char *p_string\
    , ar_gui_point left_top_point\
    , ar_gui_color_space_yuv color_str\
    , ar_gui_color_space_yuv color_background\
    , int weight_background);

/**
 * @brief      This function is used to draw circle on the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  center_point     The center point position of the circle(\ref ar_gui_point "ar_gui_point")
 * @param  radius           The radius of the circle in pixels
 * @param  color_space_yuv  The color o fthe circle(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 * @param  line_width       The line width
 * @param  to_fill          1- to fill the circle, 0- draw a loop.
 *
 * @retval     0 fail
 * @retval    others success
 *
 * @note
 *  This funciton only affect the specific canvas buffer.
 *  It won't afftect the output images. You can use the funciton \ref ar_gui_display_canvas "ar_gui_display_canvas" or \ref ar_gui_display_canvas_append "ar_gui_display_canvas_append" to draw.
 *
 */
unsigned int ar_gui_canvas_draw_circle(unsigned int fd\
    , unsigned int id_canvas\
    , ar_gui_point center_point\
    , int radius\
    , ar_gui_color_space_yuv color_space_yuv\
    , int line_width
    , int to_fill);

/**
 * @brief      This function is used to get the pre-defined color.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  p_YUV           The returned YUV values(\ref ar_gui_color_space_yuv "ar_gui_color_space_yuv")
 * @param  color           The pre-defined color(\ref ar_gui_predefined_color_en "ar_gui_predefined_color_en")
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 */
int ar_gui_canvas_get_color(unsigned int fd\
    , ar_gui_color_space_yuv *p_YUV\
    , ar_gui_predefined_color_en color);

/**
 * @brief      This function is used to set the font of the specific canvas.
 *
 * @param  fd              The ar_gui device handle returned by the function \ref ar_gui_open "ar_gui_open"
 * @param  id_canvas       The canvas id returned by the function \ref ar_gui_create_new_canvas "ar_gui_create_new_canvas"
 * @param  ont_location     The font location string
 * @param  font_bit_width    The font bit width in pixels
 * @param  font_bit_height   The font bit height in pixles
 * @param  font_start_value  The first char value of the specific font
 * @param  font_end_value    The last char value of the specific font
 *
 * @retval     0 success
 * @retval    <0 fail
 *
 * @note
 *  The font will affect the display effect of the function \ref ar_gui_canvas_draw_string "ar_gui_canvas_draw_string"
 *  If the font_location is NULL, it will use default font which is 8x16.
 *  The pre-define font is located in /local/factory/font/
 *  The font file is big endian and aligned to MSB.
 *
 */
int ar_gui_set_canvas_font(unsigned int fd\
    , unsigned int id_canvas\
    , char *font_location\
    , int font_bit_width, int font_bit_height\
    , unsigned int font_start_value, unsigned int font_end_value);

///////////////////////////////////////////////
#ifdef __cplusplus
}
#endif

#endif //__AR_GUI_H__
/** @}*/
