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
    printf("\n----------Round 1 : ---------------\n");
    printf("Kernel heap space before : %d\n", k_free_size());
    printf("Allocating 1024 bytes of kernel memory (+ 16 bytes control block) \n");

    char * pointer = (char *)k_malloc(1024);
    printf("Available heap after allocation : %d\n", k_free_size());

    printf("\n------------Round 2 : ---------------\n");

    printf("Allocationg 2048 bytes of memory (+ 16 bytes control block)\n");


    char *pointer2 = (char *)k_malloc(2 * 1024);

    printf("Available heap after allocation : %d\n", k_free_size());

    printf("\n-------------------------------\n");

    printf("Calling k_free(void *ptr) on block 1 and 2\n");

    k_free(pointer);

    k_free(pointer2);

    printf("Kernel heap size after k_free(void *ptr) : %d\n", k_free_size());


}

void kernel_main(void) {
    init_all();

    sample_program();

    for(;;);

    fprint(STDOUT, "Kernel Exit\n");
}


