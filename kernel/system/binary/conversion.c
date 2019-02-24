#include "binary/conversion.h"
#include<stdint.h>
#include "string.h"
#include "display.h"

char buffer[17] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f', '-'};


void integer_to_string(int number, char *reverse_buffer) {
    int num  = number;
    char number_s[MAX_BUFFER_SIZE];
    uint8_t buffer_index = 0;

    if(num < 0) {
        num = - num;
        number_s[buffer_index] = '-';
        buffer_index ++;
    }

    while(num != 0) {
        
        number_s[buffer_index] = '0' + (num % 10);
        num = (int) (num / 10);
        buffer_index ++;
    }

    reverse_copy(reverse_buffer, number_s);
}

void float_to_string(float number, char *buffer) {
    //max length of BUFFFER is 20
    //we stroe both fraction as well as mantessa, so double buffers are used

    //yet to be implemented
}

int string_to_integer(char *string) {
    //discard sign until compeltion
    if(string[0] == '-') string ++;
    int number = 0;
    while(*string) {
        number = number * 10 +  (*string) - '0';
        string ++;
    }

    if (string[0] == '-') number = -(number);

    return number;
}

float string_to_float(char *string) {
    // to be implemented
    return 0.0;
}

unsigned char convert_endian_ubyte(unsigned char data) {
    return (((data & 0x0f) << 4) | ((data & 0xf0) >> 4));
}

unsigned int convert_endian_word(unsigned int data) {
    return ((data & 0x000f) << 24) | ((data & 0x00f0) << 8) | ((data & 0x0f00) >> 8) | ((data & 0xf00) >> 24);  
}


 


