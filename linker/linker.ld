/*
*
*     This the memory layout of a Kernel we are creating, 
*     kernel memory contains a text block, (code), data blocks (read only) and (fixed array block) and an expandable heap block
*/
heap_size = 0x100000;

ENTRY(_start)

SECTIONS
{
	. = 1M;
	phys = .;

	.text BLOCK(4K) : ALIGN(4K)
	{
		code = .;
		*(.multiboot)
		*(.text)
	}

	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K)
	{
		*(.data)
	}

	.heap ALIGN (4K) :  
        {
            heap_bottom = .;
            . = . + heap_size;
            heap_top = .;
        }

	.bss BLOCK(4K) : ALIGN(4K)
	{
		*(COMMON)
		*(.bss)
	}
	kernel_end = .;

	/DISCARD/ :
	{
		*(.comment)
		*(.note.gnu.build-id)
	}
}
