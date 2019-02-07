#ifndef __STACK_H
#define __STACK_H

//this stack creates a dynamic memory of size block_size * length
//creates a stack out of it, by implementing push and pop


//individual item in the stack cannot be freed, as the stack itself is placed on a single block of memory


void create_stack(unsigned int length);


void generic_stack_push(void * structure);
void * generic_stack_pop();

#endif