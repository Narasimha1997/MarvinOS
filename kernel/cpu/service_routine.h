#ifndef __SERVICE_ROUTINE_H
#define __SERVICE_ROUTINE_H


#include "types.h"


 void isr0();
 void isr1();
 void isr2();
 void isr3();
 void isr4();
 void isr5();
 void isr6();
 void isr7();
 void isr8();
 void isr9();
 void isr10();
 void isr11();
 void isr12();
 void isr13();
 void isr14();
 void isr15();
 void isr16();
 void isr17();
 void isr18();
 void isr19();
 void isr20();
 void isr21();
 void isr22();
 void isr23();
 void isr24();
 void isr25();
 void isr26();
 void isr27();
 void isr28();
 void isr29();
 void isr30();
 void isr31();



typedef struct {
   u32 ds; /* Data segment selector */
   u32 edi, esi, ebp, esp, ebx, edx, ecx, eax; /* Pushed by pusha. */
   u32 int_no, err_code; /* Interrupt number and error code (if applicable) */
   u32 eip, cs, eflags, useresp, ss; /* Pushed by the processor automatically */
} registers_t;


/* 
    ISR public routines, call this at init time
*/


void init_interrupts();


extern void isr_handler(registers_t *registers);



#endif