#ifndef __CONVERSION_H
#define __CONVERSION_H

#define MAX_BUFFER_SIZE 20
/*

    public conversion methods
   
*/

void integer_to_string(int number, char * buffer);
void float_to_string(float number, char *buffer);


int string_to_integer(char *string);
float string_to_float(char *string);

#endif