#ifndef __INTERFACE_H
#define __INTERFACE_H
#include<stdint.h>

struct syscall_input_t {
    void * id;
};

#define SYSCALL_TABLE_SIZE 256

#define DFAULT_SYS_HANDLER 0
#define DEFAULT_ERROR_HANDLER 1

void add_handler(uint8_t s_id, void * (* handler)(void *));
void remove_handler(uint8_t s_id);

void * invoke_handle(uint8_t s_id, struct syscall_input_t * input);

//this implementation is provided in arch/i386/cpu_switch.c
void switch_mode(uint8_t mode_id);


#endif