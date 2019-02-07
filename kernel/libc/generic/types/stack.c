#include "generic/allocator.h"
#include "generic/stack.h"
#include "string.h"
#include "stdio.h"

//this will contain the memory for stack
void * memory_pool = 0;

//we are using this approch only for stack and queue because, these Data Structures needs to be fixed length

//here, we are trying to simulate a linear array on dynamic memory heap

static unsigned int block_length = 0;

static int MAX_STACK_LENGTH = 0;

static int TOP = -1;

void create_stack(unsigned int length) {
    block_length = get_block_size();
    MAX_STACK_LENGTH = length;
    memory_pool = (void *)generic_variable_memalloc(length * block_length);
}


void push(void * structure) {
    //structure can be of any type
    if(TOP < MAX_STACK_LENGTH) {
        int index =  block_length;
        memory_pool = memory_pool + index;
        memcopy(memory_pool, structure, block_length);
        ++TOP;
    }
}

void *  pop() {
    if(TOP > -1) {
        unsigned int index =  block_length;
        void * data = memory_pool;
        TOP --;
        memory_pool = memory_pool - index;
        //free(data); don't call free() because, user has to manually free the structure memory , once *data is processed
        return data;
    }
}
