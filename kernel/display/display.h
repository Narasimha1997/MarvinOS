#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <stddef.h>
#include <stdint.h>


#define VGA_COLOR_BLACK 0
#define VGA_COLOR_BLUE 1
#define VGA_COLOR_GREEN 2
#define VGA_COLOR_CYAN 3
#define VGA_COLOR_RED 4
#define VGA_COLOR_MAGENTA 5
#define VGA_COLOR_BROWN 6
#define VGA_COLOR_LIGHT_GREY 7
#define VGA_COLOR_DARK_GREY 8
#define VGA_COLOR_LIGHT_BLUE 9
#define VGA_COLOR_LIGHT_GREEN 10
#define VGA_COLOR_LIGHT_CYAN 11
#define VGA_COLOR_LIGHT_RED 12
#define VGA_COLOR_LIGHT_MAGENTA 13
#define VGA_COLOR_LIGHT_BROWN 14
#define VGA_COLOR_WHITE 15


#ifdef __cplusplus
extern "C"
{
#endif
    /*  
       Public Display Kernel API 
     */
    void init();
    uint8_t form_color(uint8_t background, uint8_t foreground);
    void putchar(char ch);
    void set_color(uint8_t bg, uint8_t fg);
    void write(char *string);
    void write_to_position(char *string, uint8_t row, uint8_t col);
    void write_to_position_reset(char *string, uint8_t row, uint8_t col);

#ifdef __cplusplus
}
#endif
// namespace Display

#endif
