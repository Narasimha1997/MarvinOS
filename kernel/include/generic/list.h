#ifndef __LIST_H
#define __LIST_H


//this is the generic linked list node
struct generic_list_t {
    void * data;
    struct generic_list_t * next_node;
};


//use create list, when you are creating the root node
void create_list(void *root_node_data);

void generic_list_add(void * node_data);

void * generic_list_get_node_n(unsigned int n);

void generic_list_remove_node_n(unsigned int n);

void generic_list_add_node_n(unsigned int n, void * node_data);

void * generic_list_get_last();

void generic_list_remove_last();

#endif