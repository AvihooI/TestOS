ENTRY(start)

SECTIONS 
{
    . = 1M;

    .boot :
    {
        *(.multiboot_header)
    }

    .data BLOCK(8k) : ALIGN(4k)
    {
        *(.data)
    }

    .rodata BLOCK(8k) : ALIGN(4k)
    {
        *(.rodata)
    }

    .text BLOCK(8k) : ALIGN(4k)
    {
        *(.text)
    }
    
    .bss BLOCK(8k) : ALIGN(4k)
    {
        *(.bss)
    }
}