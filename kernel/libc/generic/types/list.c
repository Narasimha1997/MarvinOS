#include "generic/allocator.h"
#include "generic/list.h"
#include "string.h"

static unsigned int block_size = 0;

static struct generic_list_t * ROOT = 0;

static int length = 0;

//method to create a node
struct generic_list_t  *create_node(void * data) {
    struct generic_list_t * node = (struct generic_list_t *)generic_variable_memalloc(sizeof(struct generic_list_t));

    node->next_node = 0;
    node->data = data;

    node->previous_node = 0;

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
    temp->previous_node = node;

    length ++;
}

void * generic_list_get_last() {
    struct generic_list_t * node = ROOT;

    while(node->next_node) node = node->next_node;

    return node->data;
}

void  generic_list_remove_last() {
    struct generic_list_t * node = ROOT;

    while(node->next_node) node = node->next_node;

    struct generic_list_t * temp = node->previous_node;

    temp->next_node = 0;
    //deletes the last node
    generic_mdealloc(node->data);
    generic_mdealloc(node);

    length --;
}

void generic_list_add_node_n(unsigned int n,void * data) {
    struct generic_list_t * node = ROOT;

    unsigned int traversed = 1;

    if(n == 1) return;  //you cannot change the root node

    //early return if actual length of node is less than the gievn n
    if(n > length + 1) return;

    while(traversed < n - 1) {
        node = node->next_node;
        traversed ++;
        
    };

    struct generic_list_t * new_node = create_node(data);

    struct generic_list_t * next_node = node->next_node;

    new_node->next_node = next_node;
    new_node->previous_node = node;

    node->next_node = new_node;

    next_node->previous_node = new_node;

    length++;
}

void generic_list_remove_node_n(unsigned int n) {
    struct generic_list_t * node = ROOT;

    if(n == 1) return;

    if(n > length) return;

    unsigned int traversed = 1;

    do {
        node = node->next_node;
        traversed ++;
    } while(traversed != n);

    struct generic_list_t * previous = node->previous_node;
    struct generic_list_t * next = node->next_node;

    if(next == 0) return;

    previous->next_node = next;
    next->previous_node = previous;

    //deallocate now :

    generic_mdealloc(node->data);
    generic_mdealloc(node);


    length --;
}

int generic_list_number_of_nodes() {
    return length;
}

void * generic_list_get_node_n(unsigned int n) {

    if(n == 1) return ROOT->data;

    if(n > length) return 0;

    struct generic_list_t * node = ROOT;

    unsigned int traversed = 1;

    do {
        node = node->next_node;
        traversed ++;
    } while(traversed != n);

    return node->data;
}

