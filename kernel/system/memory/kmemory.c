#include "memory/kheap.h"
#include "string.h"

void *k_malloc(unsigned int size) {
    return allocate_heap_memory(size);
}


void k_free(void *pointer) {
    release_heap(pointer);
}

void k_heap_init() {
    init_heap();
}

int k_free_size() {
    return get_free_kheap_size();
}

void * k_calloc(unsigned int n_blocks, unsigned int size) {
    unsigned int final_size = n_blocks * size;

    if(final_size > k_free_size()) return 0;

    //If available memory , allocate it as blocks and initlaize it to zero

    void * memory = k_malloc(final_size);

    void * iter_p = memory;

    unsigned int i;

    for(i = 0x0; i <= final_size; i++) {
        * iter_p = 0;
        iter_p ++;
    }

    return memory;
}