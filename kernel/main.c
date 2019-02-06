#include "init.h"
#include "display.h"
#include "stdio.h"
#include "serial.h"
#include "keyboard.h"
#include "stdlib.h"
#include "binary/encryption.h"
#include "timer.h"
#include "stderr.h"

void kernel_main(void);

void key_handler_(unsigned char key) {
    putchar(key);
}

void error_handler_t(registers_t * reg) {
    reg = 0;
    printf("Negative number detected\n");
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
    set_custom_error_handler(error_handler_t);

    int a = 10;
    int b = - 20;

    int c ;

    if(b < 0) {
        call_stderr();
        c = -b + a;
    }else c = a + b;

    printf("Result : %d\n", c);

    printf("Now you can type anything : \n");

    register_keyboard_handler(key_handler_);

}

void kernel_main(void) {
    init_all();

    sample_program();

    for(;;);

    fprint(STDOUT, "Kernel Exit\n");
}


