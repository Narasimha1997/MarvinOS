#include "init.h"
#include "display.h"
#include "stdio.h"
#include "stdlib.h"
#include "startup.h"
#include "cshell/interpreter.h"
#include "binary/conversion.h"
#include "arch/types.h"

void kernel_main(void);

void key_handler_(unsigned char key) {
    putchar(key);
}


void first_program() {

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
    //delegate_to_console();
    delegate_to_console();
    
}

void kernel_main(void) {
    init_all();

    first_program();

    for(;;);

    printf("Kernel halt");
}


