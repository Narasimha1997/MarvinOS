#include<stdint.h>

extern void * memcopy(void *dest, void * source, uint8_t size);


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

