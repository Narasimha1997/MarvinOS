#include "generic/allocator.h"
#include "generic/btree.h"

static int nb_nodes = 0;

static struct generic_btree_t * ROOT = 0;


void create_btree(void * data, int key) {
    //creates a root node
    struct generic_btree_t * node = (struct generic_btree_t *)generic_malloc();
    node->key = key;
    node->data = data;
    node->lnode = node->rnode = 0;
    ROOT = node;
}

//recursive traversal functions : 

void ___recursive_insert(struct generic_btree_t * start, void * data, int key) {

    if(start == 0) {
        //create and insert a node here
        struct generic_btree_t * node = (struct generic_btree_t *)generic_malloc();
        node->data = data;
        node->lnode = node->rnode = 0;

        start = node;

        return;
    }

    if(start->key > key) ___recursive_insert(start->lnode, data, key);

    else if(start->key < key)  ___recursive_insert(start->rnode, data, key);
}

struct generic_btree_t * ___recursive_search(struct generic_btree_t * start, int key) {

    if(start == 0) return 0;

    //traverse : 
    if(start->key < key) start = ___recursive_search(start->rnode, key);
    else if(start->key > key) start = ___recursive_search(start->lnode, key);
    else return start;
}


void generic_btree_add_node(void * data, int key) {
    
    struct generic_btree_t * start = ROOT;

    ___recursive_insert(start, data, key);

    nb_nodes++;
}

void * generic_btree_get_node_by_key(int key) {
    struct generic_btree_t * start = ROOT;
    return ___recursive_search(start , key)->data;
}

void * generic_btree_min_leaf() {
    struct generic_btree_t * start = ROOT;

    while(start->lnode) start = start->lnode;

    return start->data;
}

void * generic_btree_max_leaf() {
    struct generic_btree_t * start = ROOT;

    while(start->rnode) start = start->rnode;

    return start->data;
}

