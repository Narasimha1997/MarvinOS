#ifndef __STDERR_H
#define __STDERR_H

#include "serial.h"


//call for error
//this will raise BIOS interrut 9
void call_stderr();

//This is the common error handler routine, this uses unknown routine
//whenever a unknown interrupt occurs, this is called immeditely

//pass 0 or NULL to error_handler for default behaviour, otherwise, the callback will be called

void  error_handler(registers_t *registers);
void set_custom_error_handler(void (*handler)(registers_t *reg));
//register error listener
void link_stderr();

void unlink_stderr();

#endif