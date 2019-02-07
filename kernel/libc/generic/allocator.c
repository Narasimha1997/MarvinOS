#include "memory/kmemory.h"

#include "generic/allocator.h"
#include "string.h"

//This is a platform specific allocator
//modify this code, to call platform specific dynamic memory allocaor allocator


static unsigned int block_size = 0;


//these are the functions used for allocation and free
void * (*allocator)(unsigned int size);
void (*free)(void *pointer);

void set_allocator_method(void * (*allocator_) (unsigned int size)) {
    allocator = allocator_;
}

void set_free_method(void (*free_)(void *pointer)) {
    free = free_;
}

void * generic_variable_memalloc(unsigned int size) {
    //creates a memory of any block , apart from block_size
    return (void *)allocator(size);
}

//these are the generic memory allocation methods used by generic library

void *  generic_malloc() {
    //allocates memory as a block specified by block_size
    return (void *) allocator(block_size);
}

void generic_mdealloc(void * pointer) {
    memset(pointer, 0, block_size);
    free(pointer);
}

unsigned int get_block_size() {
    return block_size;
}
//this is the main method, that initializes a generic library

void generic_init(
    void * (*malloc_)(unsigned int size), 
    void (*free_) (void * pointer),
    unsigned int block_size_
    ) {

        set_allocator_method(malloc_);
        set_free_method(free_);
        block_size = block_size_;
}


