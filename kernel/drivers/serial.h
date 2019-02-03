#ifndef __SERIAL_H
#define __SERIAL_H


// byte I/O
void outb(unsigned short port, unsigned char data);
unsigned char  inb(unsigned short port);

// word I/O

void outw(unsigned short port, unsigned short data);
unsigned short inw(unsigned short port);

#endif

