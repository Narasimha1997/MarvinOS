
.extern kernel_main
 

.global _start

//this segment contains all headers and flags required for GRUB bootloader, I found this on OSDev documentation 

.set MB_MAGIC, 0x1BADB002          
.set MB_FLAGS, (1 << 0) | (1 << 1) 
.set MB_CHECKSUM, (0 - (MB_MAGIC + MB_FLAGS))
 

.section .multiboot
	.align 4 
	
	.long MB_MAGIC
	.long MB_FLAGS
	.long MB_CHECKSUM
 
.section .bss

	.align 16
	stack_bottom:
		.skip 4096 // Reserve a 4096-byte (4K) stack
	stack_top:
 
// This section contains our actual assembly code to be run when our kernel loads
.section .text
	// _start symbol where control is given first. 
	_start:
		mov $stack_top, %esp // Set the stack pointer to the top of the stack
 
		call kernel_main
 
		hang:
			cli      // Disable CPU interrupts
			hlt      // Halt the CPU
			jmp hang // If that didn't work, loop around and try again.
