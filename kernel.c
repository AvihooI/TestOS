#include "terminal.h"

void kernel_main()
{
    terminal_clear(vga_entry(' ', vga_entry_color(VGA_COLOR_GRAY, VGA_COLOR_BLUE)));

    terminal_write_str("Test\n");

    return;
}