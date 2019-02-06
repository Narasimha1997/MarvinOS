#include "init.h"
#include "idt.h"
#include "gdt.h"
#include "irq.h"
#include "display.h"
#include "timer.h"
#include "memory/kmemory.h"
#include "stderr.h"
#include "keyboard.h"


void init_all() {

    // initialise Kernel's custom GDT, provides segmentation layout of kernel space
    init_gdt();

    //init interrupts
    init_idt();

    init_irq();

    //register an error handler
    link_stderr();

    init_timer();

    //init VGA display with default colors, (BLACK background and White text)
    //set colors before init display
    set_color(VGA_COLOR_BLACK, VGA_COLOR_GREEN);
    init_display();

     k_heap_init();

    keyboard_init();

    //any program can call set_color() and init_display again to change screen color 

}


void init_without_gdt() {

    // this is a experimental function, can be dangerous if running directly on hardware, so avoid
    init_idt();

    //init VGA display with default colors, (BLACK background and White text)
    //set colors before init display
    set_color(VGA_COLOR_BLACK, VGA_COLOR_WHITE);
    init_display();
    
}