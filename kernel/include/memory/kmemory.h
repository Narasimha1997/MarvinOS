#ifndef __KMEMORY_H
#define __KMEMORY_H

void * k_malloc(unsigned int size);

void k_free(void *pointer);

void k_heap_init();

int k_free_size();

void * k_calloc(unsigned int size);

#endif