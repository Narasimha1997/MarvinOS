#include<stdint.h>

void * memcopy(void * dst, void * src, uint8_t size) {
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