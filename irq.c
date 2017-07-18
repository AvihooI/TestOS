
#include "irq.h"
#include "idt.h"
#include "io.h"

void *irq_handlers[16] = 
{
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};

void irq_remap()
{
    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);
}

void init_irq()
{
    irq_remap();

    set_idt_entry(32, (dword) _irq_0, 0x08, 0x8E);
    set_idt_entry(33, (dword) _irq_1, 0x08, 0x8E);
    set_idt_entry(34, (dword) _irq_2, 0x08, 0x8E);
    set_idt_entry(35, (dword) _irq_3, 0x08, 0x8E);
    set_idt_entry(36, (dword) _irq_4, 0x08, 0x8E);
    set_idt_entry(37, (dword) _irq_5, 0x08, 0x8E);
    set_idt_entry(38, (dword) _irq_6, 0x08, 0x8E);
    set_idt_entry(39, (dword) _irq_7, 0x08, 0x8E);
    set_idt_entry(40, (dword) _irq_8, 0x08, 0x8E);
    set_idt_entry(41, (dword) _irq_9, 0x08, 0x8E);
    set_idt_entry(42, (dword) _irq_10, 0x08, 0x8E);
    set_idt_entry(43, (dword) _irq_11, 0x08, 0x8E);
    set_idt_entry(44, (dword) _irq_12, 0x08, 0x8E);
    set_idt_entry(45, (dword) _irq_13, 0x08, 0x8E);
    set_idt_entry(46, (dword) _irq_14, 0x08, 0x8E);
    set_idt_entry(47, (dword) _irq_15, 0x08, 0x8E);
}

void set_irq_handler(byte irq, void (*handler)(struct regs *r))
{
    irq_handlers[irq] = handler;
}

asmlinkage void irq_main_handler(struct regs *r)
{
    void (*handler)(struct regs *r);

    handler = irq_handlers[r->int_no - 32];

    if (handler)
    {
        handler(r);
    }

    if (r->int_no >= 40)
    {
        outb(0x40, 0x20);
    }

    outb(0x20, 0x20);
}