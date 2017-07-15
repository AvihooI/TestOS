#include "terminal.h"
#include "gdt.h"

void kernel_main()
{
    terminal_clear(vga_entry(' ', vga_entry_color(VGA_COLOR_GRAY, VGA_COLOR_BLUE)));
    terminal_write_str("TestOS V 0.0000001\n");
    gdt_init();

    return;
}

void* do_nothing(void* ptr)
{
    return ptr + 1;
}
