#include "serial.h"


void outb(unsigned short port, unsigned char data) {
    /*
      Outputs data through port 
    */
    __asm__("out %%al, %%dx" : : "a" (data), "d" (port));
}

unsigned char inb(unsigned short port) {
    unsigned char data;

    /*
       Obtain data through port
    */

    __asm__("in %%dx, %%al" :  "=a" (data) : "d" (port));

    return data;
}

void outw(unsigned short port, unsigned short data) {
    /*
      Outputs a 32-bit word using port
    */
    __asm__("out %%ax, %%dx" : : "a" (data), "d" (port));
}

unsigned short inw(unsigned short port) {

    unsigned short data;
    /*
      inputs a 32-bit word using port
    */
    __asm__("in %%dx, %%ax" :  "=a" (data) : "d" (port));

    return data;
}


