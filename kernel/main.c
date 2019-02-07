#include "init.h"
#include "display.h"
#include "stdio.h"
#include "serial.h"
#include "keyboard.h"
#include "stdlib.h"
#include "binary/encryption.h"
#include "timer.h"
#include "string.h"
#include "memory/kmemory.h"
#include "stderr.h"

#include "generic/allocator.h"
#include "generic/stack.h"

void kernel_main(void);

void key_handler_(unsigned char key) {
    putchar(key);
}


void sample_program() {

    //sample program to test keyboard
    sleep(2);

    write("\t Now I can handle, Basic Input and Output operations\n");

    write(" \t___________\n");
    write("\t|           |\n");
    write("\t| O       O |\n");
    write("\t|    | |    |\n");
    write("\t|           |\n");
    write("\t|   =====   |\n");
    write("\t|___________|\n");

    //sample program with all we have done till now

    generic_init(k_malloc, k_free, 30);

    //creating a stack of 2 units
    create_stack(2);

    generic_stack_push("Prasanna");
    generic_stack_push("Narasimha");

    //these 2 entries will not be pushed because of overflow

    generic_stack_push("Hello,world");
    generic_stack_push("Sourav");

    char *data = (char *)generic_stack_pop();
    printf("Poped : %s\n", data);

    data = (char *)generic_stack_pop();
    printf("Poped : %s\n", data);

    //this should be NULL :
    data = (char *)generic_stack_pop();
    if(data == NULL) printf("Stack empty\n");

}

void kernel_main(void) {
    init_all();

    sample_program();

    for(;;);

    fprint(STDOUT, "Kernel Exit\n");
}


