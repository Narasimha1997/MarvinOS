#include "syscall/interface.h"
#include "stderr.h"
#include "serial.h"
#include "display.h"

void * SYSCALL [256];

static int index = 0;

void syscall_error_handler(registers_t * regs) {
    write("Invalid syscall id passed, so called default handler\n");
}

void stderr_init() {
    set_custom_error_handler(syscall_error_handler);
    link_stderr();
}

void stderr_remove() {
    unlink_stderr();
}

void stderr_call() {
    stderr_init();
    
    asm __volatile__("int $0");
    
    stderr_remove();
}


void add_handler(uint8_t id ,void * (*handle)(void *)) {
    SYSCALL[id] = handle;
}

void remove_handler(uint8_t id) {
    SYSCALL[id] = 0;
}

void invoke_handler(uint8_t id, struct syscall_input_t * data) {
   
}