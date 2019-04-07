#ifndef __HTABLE_H
#define __HTABLE_H

struct generic_hash_entry_t {
    int key;
    void * data;
};

int generic_htable_insert(void * data);
int generic_htable_retrive(int key);

void generic_htable_delete(int key);

#endif