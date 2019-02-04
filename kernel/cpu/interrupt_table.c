#include "interrupt_table.h"
#include "types.h"
#include "../display/display.h"


void set_idt_entry(int n, u32 handler) {

    INTERRUPT_TABLE[n].lower_address = lower_offset(handler);
    INTERRUPT_TABLE[n].higher_address = higher_offset(handler);

    INTERRUPT_TABLE[n].flags = 0x8E;

    INTERRUPT_TABLE[n].selector = KERNEL_CS;

    INTERRUPT_TABLE[n].zero = 0;
}

extern uint32_t idt_flush(idt_register_t *reg);


void set_idt() {

    INTERRUPT_REG.base = (u32)&INTERRUPT_TABLE;
    INTERRUPT_REG.limit = (IDT_SIZE*sizeof(idt_entry_t)) - 1;

    //load IDT Register address using lidt

    idt_flush(&INTERRUPT_REG);
}