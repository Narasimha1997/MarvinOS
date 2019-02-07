#ifndef __ALLOCATOR_H
#define __ALLOCATOR_H


void generic_init(
    void * (*malloc)(unsigned int size),
    void (*free) (void *pointer),
    unsigned int size
);


void * generic_variable_memalloc(unsigned int size);

void  * generic_malloc();

void generic_mdealloc(void * pointer);


unsigned int get_block_size();

#endif