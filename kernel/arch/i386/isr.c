#include "isr.h"

#include "display.h"

void *isr_routines[32] = { NULL };

char *exception_messsage[] = {
	"Division By Zero Exception",
	"Debug Exception",
	"Non Maskable Interrupt Exception",
	"Breakpoint Exception",
	"Into Detected Overflow Exception",
	"Out of Bounds Exception",
	"Invalid Opcode Exception",
	"No Coprocessor Exception",
	"Double Fault Exception",
	"Coprocessor Segment Overrun Exception",
	"Bad TSS Exception",
	"Segment Not Present Exception",
	"Stack Fault Exception",
	"General Protection Fault Exception",
	"Page Fault Exception",
	"Unknown Interrupt Exception",
	"Coprocessor Fault Exception",
	"Alignment Check Exception",
	"Machine Check Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception",
	"Reserved Exception"
};

void isr_handler(registers_t *regs)
{
	if (regs->int_no < 32) {
		void (*handler)(registers_t *regs);

		handler = isr_routines[regs->int_no];
		if (handler) {
			handler(regs);
		} else {
			write("Error\n");
			write(exception_messsage[regs->int_no]);
			write(" Cought\n");
		}
	}
}

void isr_install_handler(int32_t isr, void (*handler)(registers_t *r))
{
	isr_routines[isr] = handler;
}

void isr_uninstall_handler(int32_t isr)
{
	isr_routines[isr] = 0;
}
