#include "./display/display.cpp"
#include "./libc/string/string.c"

extern "C" void kernel_main(void);


void sample_program() {

    Display::write("First program using string function : \n");

    char buffer[50] = "Hello";

    char *cpy = " Prasanna";

    strncpy(buffer, cpy, 9);

    Display::write(buffer);

    Display::write("\nEnd of Program, more to be developed yet\n");

}

void kernel_main(void) {

    Display::init();

    sample_program();
 }


