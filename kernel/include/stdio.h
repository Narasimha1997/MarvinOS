
#ifndef __STDIO_H
#define __STDIO_H

#define STDOUT 0
#define STDIN 1
#define STDERR 2

#include<stdint.h>


/*
   These are the public methods providing higher levels of abstraction for I/O (read-write) operations
   Use of these APIs are suggestable instead of write() and putchar() which are kernel level routines
*/

void fprint(uint8_t fd, char *string);

void fread(uint8_t fd, char *string);

void printf(char *string, ...);

void scanf(char *string, ...);

void print_int(int number);

void i_to_a(int number, char *buffer);

int a_to_i(char *buffer);

#endif