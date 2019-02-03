#include "./display/display.h"
#include "libc/string.h"

using namespace Display;

extern "C" void kernel_main(void);


void sample_program() {
    for(int i = 0; i < 25; i++) Display::write("Hello, world!\n");

    for(int i = 0; i < 5; i++) Display::write("New text\n");
}

void kernel_main(void) {

    Display::set_color(VGA_COLOR_RED, VGA_COLOR_WHITE);

    Display::init();
    sample_program();
}


