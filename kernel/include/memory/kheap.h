#ifndef __HEAP_H
#define __HEAP_H
#include<stdint.h>


//defines structures for memory basic heap memory management
#define HEAP_FREE 0xff
#define HEAP_ALLOCATED 0x00
#define HEAP_HEAD 0x0f

typedef unsigned char * HEAP_ADDR;

typedef uint32_t heap_size_t;

struct heap_control_t {
    uint8_t magic;
    uint8_t is_head;
    uint32_t size;
    struct heap_control_t * heap_next;
    struct heap_control_t * heap_previous;
};


int get_heap_size();

void release_heap(void *pointer);

void * allocate_heap_memory(unsigned int size);

void init_heap();

int get_free_kheap_size();

#endif