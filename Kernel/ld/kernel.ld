ENTRY(start)

SECTIONS
{
    /* Kernel load address */
	. = 1M;

    /* Load address */
	kernel_start = .;

	.text BLOCK(4K) : ALIGN(4K)
	{
		kernel_text_start = .;
		*(.multiboot)
		*(.text)
        kernel_text_end = .;
	}

	.rodata BLOCK(4K) : ALIGN(4K)
	{
		*(.rodata)
	}

	.data BLOCK(4K) : ALIGN(4K)
	{
		kernel_data = .;
		*(.data)
		*(.symbols)
		PROVIDE(kernel_symbols_start = .);
		PROVIDE(kernel_symbols_end = .);
	}

	.bss BLOCK(4K) : ALIGN(4K)
	{
		kernel_bss = .;
		*(COMMON)
		*(.bss)
		*(.stack)
	}

	kernel_end = .;
}
