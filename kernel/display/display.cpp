#include "vga.c"

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

namespace Display
{

uint8_t display_color = 0x0f;

extern void init()
{
    tty_setcolor(display_color);
    vga_init();
}

extern uint8_t form_color(uint8_t background, uint8_t foreground)
{
    uint8_t bg = background << 4;
    return (bg | foreground);
}

extern void putchar(char ch)
{
    vga_putchar(ch);
}

extern void set_color(uint8_t bg, uint8_t fg)
{
    display_color = form_color(bg, fg);
}

extern void write(char *string)
{
    terminal_putstring(string);
}

extern void write_to_position(char *string, uint8_t row, uint8_t col) {
    terminal_write_string_at(string, row, col);
}

extern void write_to_position_reset(char *string, uint8_t row, uint8_t col) {
    terminal_write_string_at_and_reset(string, row, col);
}
}; // namespace Display


