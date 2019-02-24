#include "stdio.h"
#include "input/stdin.h"
#include "display.h"
#include "cshell/cshell.h"
#include "stdlib.h"
#include "string.h"
#include "memory/kmemory.h"

//we made command parser completely dynamic in nature
//so it can use heap memory to store its values
//and not data segment

void echo(char * string) {
    //a simple echo tool with 4 steps
    while(*string != ' ') string ++;

    printf("%s", string);
}

void wcnt(char * string) {
    while(*string != ' ') string ++;
    string++;
    printf("%d \n", (int)(strlen(string) - 1));
}

void cowsay(char * string) {
    while(*string != ' ') string ++;
    string ++;

    printf("\t^--------^\n");
    printf("\t \\ o  o /\n");
    printf("\t  \\    /\n");
    printf("\t   \\__/\n");
    printf("\t   |  |\n");
    printf("\t   |  |\n");
    printf("\t %s\n", string);
}

void avail_heap() {
    int size = k_free_size();
    printf("Available size of heap : %d\n", size);
}

void clear() {
    set_color(VGA_COLOR_BLUE, VGA_COLOR_WHITE);
    init_display();
}



void command_parser(char * buffer) {
    
    char * command = (char *)k_malloc(20);

    char * buffer_ptr = buffer;

    char *command_ptr = command;

    while((* buffer_ptr != '\n') && (* buffer_ptr != ' ')) {
         * command_ptr = *buffer_ptr;
         command_ptr ++;
         buffer_ptr ++; 
    }

    //invoke respective commands :
    *command_ptr = '\0'; 

    if(strcmp("echo", command) == 0) {
        echo(buffer);
    }else if(strcmp("wcnt", command) == 0) {
        wcnt(buffer);
    }else if(strcmp("clear", command) == 0) {
        clear();
    }else if(strcmp("cowsay", command) == 0) {
        cowsay(buffer);
    }else if(strcmp("avail-heap", command) == 0) {
        avail_heap();
    }else {
        printf("Invalid commnad \n");
    }

    memset(buffer, 0, 256);
    k_free(command); 

}

void init()
{

    set_color(VGA_COLOR_BLUE, VGA_COLOR_WHITE);
    init_display();
    write_to_position("Welcome to C-Shell\n", 12, 30);
    sleep(3);
    init_display();

    while (1){
        printf("> ");

        char * input = k_malloc(256); 

        kb_read_line(input);

        //copy first 4 words to a buffer and check for basic commands

        if (strcmp(input, "exit\n") == 0) {
            set_color(VGA_COLOR_BLACK, VGA_COLOR_GREEN);
            init_display();
            return;
        };

        command_parser(input);

        k_free(input);
    }
}