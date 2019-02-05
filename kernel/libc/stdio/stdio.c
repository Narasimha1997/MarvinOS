#include <stdint.h>

#include "stdio.h"
#include "display.h"
#include "stderr.h"
#include "isr.h"
#include "serial.h"
#include "binary/conversion.h"
#include <stdarg.h>

void invalid_descriptor_error(registers_t *regs)
{
    write("Invalid descriptor passed to fwrite\n");
}

void common_system_error_handler()
{
    call_stderr();
}

void i_to_a(int number, char *buffer)
{
    integer_to_string(number, buffer);
}

int a_to_i(char *number)
{
    return string_to_integer(number);
}

void fprint(uint8_t descr, char *output)
{

    switch (descr)
    {
    case STDOUT:
        write(output);
        break;
    case STDERR:
        common_system_error_handler();
        break;

    default:
        set_custom_error_handler(invalid_descriptor_error);
        call_stderr();
        break;
    }
}

void printf(char *string, ...)
{
    va_list arg_pointer;

    //iter through input string to find format specifiers
    va_start(arg_pointer, string);

    char lval_c;
    int lval_int;
    char *lval_s;

    while (*string)
    {

        if (*string == '%')
        {
            string++;

            if (*string == '%')
                putchar(*string);
            else
            {
                switch (*string)
                {

                case 'd': //print integer
                    lval_int = va_arg(arg_pointer, int);
                    print_int(lval_int);
                    break;

                case 'c':
                    lval_c = va_arg(arg_pointer, int);
                    putchar(lval_c);
                    break;
                case 's' :
                    lval_s = va_arg(arg_pointer, int);
                    fprint(STDOUT, lval_s);
                    break;
                default :
                    fprint(STDOUT, "This format specifier not implemented");
                }
            }
        }
        else putchar(*string);

        string ++;
    }
    va_end(arg_pointer);
}

void scanf(char *string, ...)
{
    printf("Not yet implemented , your format is %s\n", string);
}

void print_int(int number)
{
    char buffer[15];
    i_to_a(number, buffer);
    fprint(STDOUT, buffer);
}