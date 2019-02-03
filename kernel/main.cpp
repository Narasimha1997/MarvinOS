#include "./display/display.h"
#include "./libc/string/string.h"

using namespace Display;

extern "C" void kernel_main(void);


void sample_program() {

    test_display_in_string();
}

void kernel_main(void) {

    Display::init();

    sample_program();
 }


