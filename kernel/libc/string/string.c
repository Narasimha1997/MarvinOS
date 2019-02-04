#include<stdint.h>
#include "string.h"

void * memcopy(void *dest, void *source, uint8_t size) {
    uint8_t iter__ = 0;

    char *source_char = (char *)source;
    char *dest_char = (char *)dest;

    while(iter__ != size) {
        dest_char[iter__] = source_char[iter__];
        iter__ ++;
    }

    return dest_char;
}

void *memset(void *dst, int c, size_t count){
	char *p = (char *)dst;

	for (; count != 0; --count)
		*p++ = c;

    return dst;
}


void * memmove(void * dst, void * src, uint8_t size) {
    char * dst_c = (char *)dst;
    char * src_c = (char *)src;

    uint8_t iter__ = 0;

    while(iter__ != size) {
        dst_c[iter__] = src_c[iter__];
        src_c[iter__] = '\0';

        iter__ ++;
    }

    return dst_c;
}


uint8_t strlen(char *src) {
    uint8_t iter__ = 0;

    while(*src != '\0') {
        iter__ ++;
        src ++;
    }

    return iter__;
}

uint8_t strcmp(char *src, char *dst) {


    if(strlen(src) != strlen(dst)) return +1;

    while(*src != '\0') {
        if(*src != *dst) return +1;
        src ++; dst ++;
    }
    
    return 0;
}

void strncpy(char *source, char *dest, uint8_t n) {
    source += strlen(source);
    memcopy(source, dest, n);
}
