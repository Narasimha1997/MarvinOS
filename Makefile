AS=../i686-elf-as
CC=../i686-elf-gcc

CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra

KERNEL_CC_LIST:=\
kernel/arch/i386/gdt.o \
kernel/arch/i386/idt.o \
kernel/arch/i386/irq.o \
kernel/arch/i386/isr.o \
kernel/display/display.o\
kernel/libc/stdio/stdio.o \
kernel/main.o \
kernel/drivers/serial.o \
kernel/drivers/keyboard.o \
kernel/drivers/timer.o \
kernel/system/binary/conversion.o \
kernel/libc/stdlib/stdlib.o \
kernel/system/init.o \
kernel/system/stderr.o \
kernel/libc/string/string.o

KERNEL_AS_LIST:=\
kernel/boot.o

KERNEL_INCLUDE_DIR=kernel/include

all: kernel

.PHONY: kernel
kernel: $(KERNEL_CC_LIST) $(KERNEL_AS_LIST)
	$(CC) -T linker/linker.ld -o Marvin.bin -ffreestanding -O2 -nostdlib $^ -lgcc -I$(KERNEL_INCLUDE_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(KERNEL_INCLUDE_DIR)

%.o: %.s
	$(AS) $< -o $@

run:
	qemu-system-i386 -kernel Marvin.bin

.PHONY: iso
iso: kernel
	cp Marvin.iso .bin iso/boot/Marvin.bin
	grub-mkrescue -o Marvin.iso iso/

run-iso: iso
	qemu-system-i386 -cdrom Marvin.iso \

clean:
	find -type f \( -name "*.o" -o -name "*.bin" -o -name "*.iso" \) -delete
