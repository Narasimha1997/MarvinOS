#include "generic/allocator.h"
#include "generic/list.h"
#include "string.h"

static unsigned int block_size = 0;

static struct generic_list_t * ROOT = 0;

static int length = 0;

//method to create a node
struct generic_list_t  *create_node(void * data) {
    void * raw_data = (void *)generic_malloc();
    memcopy(raw_data, data, block_size);

    struct generic_list_t * node = (struct generic_list_t *)generic_variable_memalloc(sizeof(struct generic_list_t));

    node->next_node = 0;
    node->data = raw_data;

    return node;
}

void create_list(void * root_data) {
    ROOT = create_node(root_data);
    length ++;
}

void generic_list_add(void * data) {
    struct generic_list_t * node = ROOT;

    while(node->next_node) node = node->next_node;

    //create a new node : 
    struct generic_list_t * temp = create_node(data);

    node->next_node = temp;

    length ++;
}

void * generic_list_get_last() {
    struct generic_list_t * node = ROOT;

    while(node->next_node) node = node->next_node;

    return node->data;
}


