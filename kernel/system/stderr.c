#include "stderr.h"
#include "stdio.h"
#include "isr.h"


static void (*handler) (registers_t  *registers) = 0;

void  error_handler(registers_t *r) {

    if(handler) {
        handler(r);
        return;
    }

    //no handler registered, perform default handle
    fprint(STDOUT, "An unregistered error occured\n");
    return;
}


void link_stderr() {
    isr_install_handler(15, error_handler);
}

void unlink_stderr() {
    isr_uninstall_handler(15);
}

void call_stderr() {
    __asm__ __volatile__("int $0xf");
}

void set_custom_error_handler(void (*handler_) (registers_t *reg)) {
    handler = handler_;
}