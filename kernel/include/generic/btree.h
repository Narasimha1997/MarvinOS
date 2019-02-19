#ifndef __BTREE_H
#define __BTREE_H

struct generic_btree_t {
    void * data;
    struct generic_btree_t * lnode;
    struct generic_btree_t * rnode;
    int key;
};

void create_btree(void * data, int key);

void generic_btree_add_node(void * data, int key);

void * generic_btree_min_leaf();

void * generic_btree_max_leaf();

void * generic_btree_get_node_by_key(int key);

#endif