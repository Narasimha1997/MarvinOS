#include "vga.cpp"
#include "display.h"

namespace Display
{

uint8_t display_color = 0x0f;

void init()
{
    tty_setcolor(display_color);
    vga_init();
}

uint8_t form_color(uint8_t background, uint8_t foreground)
{
    uint8_t bg = background << 4;
    return (bg | foreground);
}

void putchar(char ch)
{
    vga_putchar(ch);
}

void set_color(uint8_t bg, uint8_t fg)
{
    display_color = form_color(bg, fg);
}

void write(char *string)
{
    terminal_putstring(string);
}

void write_to_position(char *string, uint8_t row, uint8_t col) {
    terminal_write_string_at(string, row, col);
}

void write_to_position_reset(char *string, uint8_t row, uint8_t col) {
    terminal_write_string_at_and_reset(string, row, col);
}
}; // namespace Display


