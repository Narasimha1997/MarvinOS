#include "init.h"
#include "display.h"
#include "stdio.h"
#include "serial.h"
#include "keyboard.h"
#include "stdlib.h"
#include "binary/encryption.h"
#include "timer.h"

void kernel_main(void);


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

    //test conversion functions : 
    char *string = "Narasimha";

    uint16_t parity = generate_parity_32(string);

    if(verify_parity_32("Narasimha", parity) == 1) fprint(STDOUT, "Parity matched\n");
    else fprint(STDOUT, "Parity did not match here also!\n");

    string = "Narasmmha";

    if(verify_parity_32(string, parity) == 1) fprint(STDOUT, "Parity matched again\n");
    else fprint(STDOUT, "Parity did not match this time\n"); 

}

void kernel_main(void) {
    init_all();

    sample_program();

    for(;;);

    fprint(STDOUT, "Kernel Exit\n");
}


