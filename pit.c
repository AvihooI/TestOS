
#include "pit.h"
#include "terminal.h"
#include "irq.h"

volatile dword timer_ticks = 0; //volatile extremely important since those values change via interrupts
volatile dword timer_seconds = 0;
volatile byte waiting;

void pit_set_timer_phase(word hz)
{
    word divisor = 1193180 / hz;

    outb(0x43, 0x36);
    outb(0x40, divisor & 0xff);
    outb(0x40, divisor >> 8);
}

void timer_handler(struct regs *r)
{
    timer_ticks++;

    if (timer_ticks % 18 == 0 && waiting)
    {
        terminal_write_str("One second has passed!\n");
        timer_seconds++;
    }
}

void init_pit()
{
    set_irq_handler(0, timer_handler);
}

void timer_wait(dword seconds)
{
    waiting = 1;
    timer_seconds = 0;

    while (timer_seconds < seconds)
    {
        asm("nop"); //making sure the loop actually runs :)
    }

    waiting = 0;
}