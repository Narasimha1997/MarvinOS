#include "init.h"
#include "display.h"
#include "stdio.h"
#include "serial.h"
#include "keyboard.h"
#include "stdlib.h"
#include "binary/encryption.h"
#include "timer.h"
#include "string.h"
#include "generic/list.h"
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

    struct  data {
        int id;
        char * name;
    };

    generic_init(k_malloc, k_free, sizeof(struct data));

    struct data  Data ;
    Data.id = 10;
    Data.name = "Prasanna";

    create_list(&Data);

    struct data Data2;
    Data2.id = 11;
    Data2.name = "Narasimha";

    generic_list_add(&Data2);

    struct data Data3;

    Data3.id = 13;
    Data3.name = "Nikil";

    generic_list_add_node_n(2, &Data3);


    struct data * Obtained = (struct data *)generic_list_get_node_n(3);

    printf("ID : %d\n Data : %s\n", Obtained->id, Obtained->name);

    generic_list_add_node_n(3, &Data);

    generic_list_remove_node_n(3);

    Obtained = (struct data *)generic_list_get_node_n(3);

    printf("ID : %d\n Data : %s\n", Obtained->id, Obtained->name);
}

void kernel_main(void) {
    init_all();

    sample_program();

    for(;;);

    fprint(STDOUT, "Kernel Exit\n");
}


