#include "init.h"
#include "display.h"
#include "stdio.h"
#include "serial.h"
#include "keyboard.h"
#include "stdlib.h"
#include "binary/encryption.h"
#include "timer.h"
#include "string.h"
#include "input/stdin.h"
#include "generic/list.h"
#include "memory/kmemory.h"
#include "generic/btree.h"
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

    char buffer[256];
    
    kb_read_line(buffer);

    printf("Read : %s\n", buffer);

}

void kernel_main(void) {
    init_all();

    sample_program();

    for(;;);

    fprint(STDOUT, "Kernel Exit\n");
}


