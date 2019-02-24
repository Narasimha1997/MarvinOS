#ifndef __TYPES_H
#define __TYPES_H

//Machine architecture type
#define ARCH_WORD_SIZE 32
#define ARCH_PLATFORM "intel-i386"
#define ARCH_FPU_ENABLED 1
#define ARCH_ENDIAN "little_endian" 


//basic data-types for Marvin.OS, derived from C basic types

//int types
typedef unsigned int ui32;
typedef unsigned short ui8;
typedef unsigned long ui64;


//pointer types
typedef void * i32_pointer;
typedef char * string;

//raw byte types:
typedef unsigned char byte;

//boolean type:
typedef signed short boolean;

#define TRUE 0x01
#define FALSE 0x00

#endif