#include<stdint.h>

extern uint8_t strlen(char *src) {
    uint8_t iter__ = 0;

    while(*src != '\0') {
        iter__ ++;
        src ++;
    }

    return iter__;
}

extern uint8_t strcmp(char *src, char *dst) {


    if(strlen(src) != strlen(dst)) return +1;

    while(*src != '\0') {
        if(*src != *dst) return +1;
        src ++; dst ++;
    }
    
    return 0;
}

extern void strncpy(char *source, char *dest, uint8_t n) {
    source += strlen(source);
    memcopy(source, dest, n);
}