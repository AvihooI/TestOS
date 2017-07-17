#include "terminal.h"
#include "idt.h"

void kernel_main()
{
    init_idt();

    terminal_clear(vga_entry(' ', vga_entry_color(VGA_COLOR_GRAY, VGA_COLOR_BLUE)));

    terminal_write_str("Deliberately dividing by zero\n");

    asm volatile("xorl %eax,%eax; divl %eax, %eax");

    terminal_write_str("Alright if we got all the way here\n");

    return;
}