#include<stdbool.h>
#include<stdint.h>
#include "string.h"
#include "serial.h"

#define VGA_MEMORY_LOCATION 0xB8000

#define VGA_ROWS 25

#define VGA_COLS 80

// exports

extern void vga_init(void);
extern void terminal_putstring(char *string);
extern void tty_setcolor(uint8_t color);
extern void vga_putchar(unsigned char ch);
extern void terminal_write_string_at(char *string, uint8_t row, uint8_t col);
extern void terminal_write_string_at_and_reset(char *string, uint8_t row, uint8_t col);


volatile uint16_t *vga_buffer_pointer;

uint8_t tty_row = 0;
uint8_t tty_col = 0;

uint8_t color = 0x0F; //black screen and white text


/* cursor methods */

void enable_cursor(uint8_t cursor_start, uint8_t cursor_end) {
	outb(0x3D4, 0x0A);
	outb(0x3D5, (inb(0x3D5) & 0xC0) | cursor_start);
 
	outb(0x3D4, 0x0B);
	outb(0x3D5, (inb(0x3E0) & 0xE0) | cursor_end);
}

void disable_cursor() {
	outb(0x3D4, 0x0A);
	outb(0x3D5, 0x20);
}

void update_cursor(int x, int y)
{
	uint16_t pos = y * VGA_COLS + x;
 
	outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t) (pos & 0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t) ((pos >> 8) & 0xFF));
}

//scroll by one row
void vga_scroll(uint8_t rows) {
    uint8_t index = VGA_COLS * rows;

    uint8_t iter_i = 0;
    uint8_t iter_j = 0;

    uint8_t row_i = 0;
    uint8_t col_i = 0;

    for(iter_i = rows; iter_i < VGA_ROWS; iter_i++) {
        for(iter_j = 0; iter_j < VGA_COLS; iter_j++) {
            uint16_t buffer_index = (VGA_COLS * row_i) + col_i;
            uint16_t scroll_index = (VGA_COLS * iter_i) + iter_j;

            vga_buffer_pointer[buffer_index] = vga_buffer_pointer[scroll_index];

            col_i++;
        }
        row_i++;
    }

    //clear 

}

void vga_init(void) {

    // Initialise the VGA variables and clear the screen : :
    vga_buffer_pointer = (uint16_t *)  VGA_MEMORY_LOCATION;

    tty_row = 0;
    tty_col = 0;

    //start clear using 2 pass loop : 
    uint8_t iter_i = 0;
    uint8_t iter_j = 0;

    for(iter_i = 0; iter_i < VGA_ROWS; iter_i ++) {

        for(iter_j = 0; iter_j < VGA_COLS; iter_j++) {
            uint16_t index  = (VGA_COLS *  iter_i) + iter_j;

            vga_buffer_pointer[index] = ((uint16_t)color << 8) | ' ';
        }
    }

    enable_cursor(14,15);
} 

void vga_putchar(unsigned char ch) {

    uint16_t index = 0;

    switch(ch) {
        case '\n' : tty_row +=1; tty_col = 0; break;
        case '\t' : tty_col +=2; break;

        default : 
          
          index = (VGA_COLS * tty_row) + tty_col;

          vga_buffer_pointer[index] = ((uint16_t) color << 8) | ch;
          
          tty_col ++;

          if(tty_col == VGA_COLS) 
              vga_putchar('\n');
          if(tty_row == VGA_ROWS){ 
             vga_init();
          }

          //TODO : Here implement scrolling support later, as of now, entire screen is re-initialized

        break;
    }
    update_cursor(tty_col, tty_row);
}

void terminal_putstring(char *string) {
    while(*string != '\0') {
        vga_putchar((unsigned char)*string);
        string +=1;
    }
}

void terminal_write_string_at(char *str, uint8_t row, uint8_t col) {
    tty_row = row;
    tty_col = col;

    terminal_putstring(str);
}

void terminal_write_string_at_and_reset(char *str, uint8_t row, uint8_t col) {
    uint8_t tty_row_temp = tty_row;
    uint8_t tty_col_temp = tty_col;
    terminal_write_string_at(str, row, col);
    tty_row = tty_row_temp;
    tty_col = tty_col_temp;
}


void tty_setcolor(uint8_t color_code) {
    color = color_code;
}


