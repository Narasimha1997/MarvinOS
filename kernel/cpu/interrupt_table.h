#ifndef __INTERRUPT_TABLE_H
#define __INTERRUPT_TABLE_H

#include "types.h"

#define KERNEL_CS 0x08
#define IDT_SIZE 256

typedef struct {
    u16 lower_address;
    u16 selector;
    u8 zero;
    u8 flags;
    u16 higher_address;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    u16 limit;
    u32 base;
} __attribute__((packed)) idt_register_t;

//create

idt_entry_t INTERRUPT_TABLE[256];
idt_register_t INTERRUPT_REG;

//public functions in kernel space to register interrupts:
void set_idt_entry(int n, u32 handler);

void set_idt();


#endif