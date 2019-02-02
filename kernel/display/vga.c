#include<stdbool.h>
#include<stdint.h>

#define VGA_MEMORY_LOCATION 0xB8000

#define VGA_ROWS 25

#define VGA_COLS 80

// exports

extern void vga_init(void);
extern void terminal_putstring(char *string);
extern void tty_setcolor(uint8_t color);
extern void vga_putchar(char ch);
extern void terminal_write_string_at(char *string, uint8_t row, uint8_t col);
extern void terminal_write_string_at_and_reset(char *string, uint8_t row, uint8_t col);


volatile uint16_t *vga_buffer_pointer;

uint8_t tty_row = 0;
uint8_t tty_col = 0;

uint8_t color = 0x0F; //black screen and white text

void vga_init(void) {

    // Initialise the VGA variables and clear the screen : :
    vga_buffer_pointer = (uint16_t *)  VGA_MEMORY_LOCATION;

    //start clear using 2 pass loop : 
    uint8_t iter_i = 0;
    uint8_t iter_j = 0;

    for(iter_i = 0; iter_i < VGA_ROWS; iter_i ++) {

        for(iter_j = 0; iter_j < VGA_COLS; iter_j++) {
            uint8_t index  = (VGA_COLS *  iter_i) + iter_j;

            vga_buffer_pointer[index] = ((uint16_t)color << 8) | ' ';
        }
    }
} 

void vga_putchar(char ch) {

    uint8_t index = 0;

    switch(ch) {
        case '\n' : tty_row +=1; tty_col = 0; break;
        case '\t' : tty_col +=2; break;

        default : 
          
          index = (VGA_COLS * tty_row) + tty_col;

          vga_buffer_pointer[index] = ((uint16_t) color << 8) | ch;
          
          tty_col ++;

          if(tty_col == VGA_COLS) 
              vga_putchar('\n');
        break;
    }
}

void terminal_putstring(char *string) {
    while(*string != '\0') {
        vga_putchar(*string);
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


