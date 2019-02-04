/*
 * irq.c
 *
 * This file is a part of Exylus.
 */

#include "irq.h"

#include "idt.h"

#include <stddef.h>

void *irq_routines[16] = { NULL };

void irq_install_handler(int32_t irq, void (*handler)(registers_t *r))
{
	irq_routines[irq] = handler;
}

void irq_uninstall_handler(int32_t irq)
{
	irq_routines[irq] = 0;
}

static void irq_remap(void)
{
	outb(0x20, 0x11);
	outb(0xA0, 0x11);
	outb(0x21, 0x20);
	outb(0xA1, 0x28);
	outb(0x21, 0x04);
	outb(0xA1, 0x02);
	outb(0x21, 0x01);
	outb(0xA1, 0x01);
	outb(0x21, 0x0);
	outb(0xA1, 0x0);
}

void init_irq()
{
	irq_remap();

	idt_set_gate(32, (uint32_t)irq0, 0x08, 0x8E);
	idt_set_gate(33, (uint32_t)irq1, 0x08, 0x8E);
	idt_set_gate(34, (uint32_t)irq2, 0x08, 0x8E);
	idt_set_gate(35, (uint32_t)irq3, 0x08, 0x8E);
	idt_set_gate(36, (uint32_t)irq4, 0x08, 0x8E);
	idt_set_gate(37, (uint32_t)irq5, 0x08, 0x8E);
	idt_set_gate(38, (uint32_t)irq6, 0x08, 0x8E);
	idt_set_gate(39, (uint32_t)irq7, 0x08, 0x8E);
	idt_set_gate(40, (uint32_t)irq8, 0x08, 0x8E);
	idt_set_gate(41, (uint32_t)irq9, 0x08, 0x8E);
	idt_set_gate(42, (uint32_t)irq10, 0x08, 0x8E);
	idt_set_gate(43, (uint32_t)irq11, 0x08, 0x8E);
	idt_set_gate(44, (uint32_t)irq12, 0x08, 0x8E);
	idt_set_gate(45, (uint32_t)irq13, 0x08, 0x8E);
	idt_set_gate(46, (uint32_t)irq14, 0x08, 0x8E);
	idt_set_gate(47, (uint32_t)irq15, 0x08, 0x8E);

	asm volatile ("sti");
}

void irq_handler(registers_t *regs){

	void (*handler)(registers_t *regs);

	handler = irq_routines[regs->int_no - 32];
	if (handler) {
		handler(regs);
	}

	if (regs->int_no >= 40) {
		outb(0xA0, 0x20);
	}

	outb(0x20, 0x20);
}
