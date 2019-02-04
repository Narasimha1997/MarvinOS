#ifndef __STRING_H
#define __STRING_H

#include<stddef.h>
#include<stdint.h>


#ifdef __cplusplus
extern "C" {
#endif


    /*
       Public API for string.c
    */

    void * memcopy(void *dest, void *source, uint8_t size);
    void * memmove(void * dst, void * src, uint8_t size);
    uint8_t strlen(char *src);
    uint8_t strcmp(char *src, char *dst);
    void strncpy(char *source, char *dest, uint8_t n);
    void test_display_in_string();
    void *memset(void *dst, int c, size_t count);

#ifdef __cplusplus
}
#endif

#endif

