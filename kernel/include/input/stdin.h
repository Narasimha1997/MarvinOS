#ifndef __STDIN_H
#define __STDIN_H

#include<stdint.h>

#define MAX_BUFFER_SIZE 256

#define RELEASE_LIMIT 0x80

//for this OS, you can store only 256 bytes

void kb_read(char * buffer, uint8_t size);

void kb_read_line(char * buffer);

#endif