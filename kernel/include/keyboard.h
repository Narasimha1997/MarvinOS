#ifndef __KEYBOARD_H
#define __KEYBOARD_H

#include<stdint.h>

#define KEYBOARD_SERIAL_PORT 0x60

typedef uint8_t SCAN_CODE_t;


void keyboard_init();


//every function that uses keyboard has to register a keyboard_handler
void register_keyboard_handler(void (*handler)(unsigned char ch));

void unregister_keyboard_handler();


#endif