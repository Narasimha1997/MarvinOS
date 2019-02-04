#include "timer.h"

#include "irq.h"

uint32_t timer_ticks = 0;
uint32_t timer_seconds = 0;

static void timer_phase(int32_t hz)
{
	int32_t divisor = 1193180 / hz;
	outb(0x43, 0x36);
	outb(0x40, divisor & 0xFF);
	outb(0x40, divisor >> 8);
}

void timer_handler(registers_t *reg)
{
	UNUSED(reg);

	timer_ticks++;

	if (timer_ticks % CLOCK_FREQUENCY == 0) {
		timer_seconds++;
	}
}

void init_timer()
{
	timer_phase(CLOCK_FREQUENCY);
	irq_install_handler(0, timer_handler);
}

void timer_wait(uint32_t seconds)
{
	uint32_t end = seconds + timer_seconds;

	while (timer_seconds < end) {
		asm volatile ("" : : : "memory");
	}
}
