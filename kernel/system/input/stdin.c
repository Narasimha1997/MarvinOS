#include "input/stdin.h"
#include "stdio.h"
#include "keyboard.h"
#include "stdlib.h"
#include "string.h"


char key_buffer[MAX_BUFFER_SIZE];

static int buffer_index = 0;

static int EOL_FLAG = 0;


void __incr_buffer_index() {
    buffer_index  = (buffer_index + 1) % MAX_BUFFER_SIZE;

    //this is how it works, 
    // A buffer in memory is created, input characters are loaded into the buffer
    //this is a rounded buffer, if buffer size > 256 , 0th index is wrote back
    //because of this buffer limitation, you can read not more than 256 chars at a time
}

void read_handler(unsigned char key) {
    //we read only pressed characters
    if(key) {
        key_buffer[buffer_index] = key;
        __incr_buffer_index();
    }
}

void read_line_handler(unsigned char key) {
    if(key && EOL_FLAG == 0) {
        if(key == '\n'){
            EOL_FLAG = 1;
        }

        printf("%c", key);

        key_buffer[buffer_index] = key;

        __incr_buffer_index();
    } 
}

void kb_read(char * buffer, uint8_t size) {
    //read characters:

    //register key handler : 

    register_keyboard_handler(read_handler);
    
    while(buffer_index <= size) sleep(1);

    unregister_keyboard_handler();
    

    //copy and reset buffer:
    memmove(buffer, key_buffer, size);
    memset(key_buffer, 0, MAX_BUFFER_SIZE);

    buffer_index  = 0;
}

void kb_read_line(char * buffer) {

    //bouned wait for EOL : 
    
    register_keyboard_handler(read_line_handler);

    while(EOL_FLAG == 0) sleep(1);

    //reset:
    unregister_keyboard_handler();
    EOL_FLAG = 0;

    //fast copy : 
    memcopy(buffer, key_buffer, buffer_index);

    buffer_index = 0;

    memset(key_buffer, 0, MAX_BUFFER_SIZE);
}

