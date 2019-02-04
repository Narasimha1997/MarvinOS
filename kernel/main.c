#include "./display/display.h"
#include "libc/string.h"
#include "cpu/service_routine.h"


void kernel_main(void);


void sample_program() {

    //test interrpts
    write("Hello,world\n");
}

void kernel_main(void) {

    set_color(VGA_COLOR_RED, VGA_COLOR_WHITE);

    init();

    sample_program();

    init_interrupts();
}


