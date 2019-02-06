#include "memory/kheap.h"


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