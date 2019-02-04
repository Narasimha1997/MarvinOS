#ifndef __SERIAL_H
#define __SERIAL_H

#include<stdint.h>

#define UNUSED(x) (void)(x)
#define CLOCK_FREQUENCY 100


typedef struct registers
{
	uint32_t gs, fs, es, ds;
	uint32_t edi, esi, ebp, esp, ebx, edx, ecx, eax;
	uint32_t int_no, err_code;
	uint32_t eip, cs, eflags, useresp, ss;
} registers_t;


// byte I/O
void outb(unsigned short port, unsigned char data);
unsigned char  inb(unsigned short port);

// word I/O

void outw(unsigned short port, unsigned short data);
unsigned short inw(unsigned short port);

#endif

