#ifndef __TYPES_H
#define __TYPES_H


/* 
    Here, we aim to create basic abstractions for CPU types
    These are used to treat everything as raw bytes.
    making it easy for us to manipulate
*/



#ifdef __cplusplus
extern "C" {
#endif

    typedef unsigned short u16;
    typedef short s16;
    typedef unsigned char u8;
    typedef signed char s8;
    typedef unsigned int u32;
    typedef signed int s32;
    typedef long long u64;
    #define lower_offset(address) (u16)((address) & 0xFFFF)
    #define higher_offset(address) (u16)(((address) >> 16) & 0xFFFF)

 
#ifdef __cplusplus
}
#endif


#endif