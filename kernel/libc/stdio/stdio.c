#include<stdint.h>

#include "stdio.h"
#include "display.h"
#include "stderr.h"
#include "isr.h"
#include "serial.h"
#include "binary/conversion.h"

void invalid_descriptor_error(registers_t *regs) {
    write("Invalid descriptor passed to fwrite\n");
}


void common_system_error_handler() {
    call_stderr();
}

void i_to_a(int number, char *buffer) {
    integer_to_string(number, buffer);
}

int a_to_i(char *number) {
    return string_to_integer(number);
}

void fprint(uint8_t descr, char *output) {

    switch(descr) {
        case STDOUT : write(output); break;
        case STDERR : common_system_error_handler(); break;

        default : 
          set_custom_error_handler(invalid_descriptor_error);
          call_stderr();
          break;
    }
}

void printf(char * string, ...) {
    write("Call to be implemented\n");
    return;
}


void scanf(char * string, ...) {
    write("This needs to be implemented");
    return;
}