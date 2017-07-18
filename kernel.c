#include "terminal.h"
#include "idt.h"
#include "irq.h"
#include "pit.h"

void kernel_main()
{
    terminal_clear(vga_entry(' ', vga_entry_color(VGA_COLOR_GRAY, VGA_COLOR_BLUE)));

    terminal_write_str("Setting up IDT...\n");
    init_idt();

    terminal_write_str("Setting up IRQ...\n");
    init_irq();

    terminal_write_str("Setting up PIT...\n");
    init_pit();

    terminal_write_str("Allowing interrupts and waiting 4 seconds...\n");
    //alow interrupts
    asm("sti");

    timer_wait(4);

    terminal_write_str("Alright if we got all the way here!\n");

    return;
}
