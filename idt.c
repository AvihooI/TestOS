#include "idt.h"
#include "terminal.h"

void set_idt_entry(size_t index, dword isr, word cs_selector, byte type_attr)
{
    _idt[index].reserved = 0;
    _idt[index].cs_selector = cs_selector;
    _idt[index].type_attr = type_attr;
    _idt[index].offset_lo = (word)((isr) & 0xffff);
    _idt[index].offset_hi = (word)((isr) >> (2*8));
}

char * exception_messages[] =
{
    "Division by zero",
    "Debug",
    "NMI",
    "Breakpoint",
    "Overflow",
    "Bound Range Exceeded",
    "Invalid Opcode",
    "Device Not Available",
    "Double Fault",
    "Coprocessor Segment Overrun",
    "Invalid TSS",
    "Segment not Present",
    "Stack-Segment Fault",
    "General Protection",
    "Page Fault",
    "Reserved",
    "Math Fault",
    "Alignment Check",
    "Machine Check",
    "SIMD Floating Point",
    "Virtualization",
    "Reserved", //21
    "Reserved", //22
    "Reserved", //23
    "Reserved", //24
    "Reserved", //25
    "Reserved", //26
    "Reserved", //27
    "Reserved", //28
    "Reserved", //29
    "Reserved", //30
    "Reserved", //31
};

void init_idt()
{
    //present, dpl = ring 0, the rest is 01110
    set_idt_entry(0, (dword)_isr_0, 0x08, 0x8E);
    set_idt_entry(1, (dword)_isr_1, 0x08, 0x8E);
    set_idt_entry(2, (dword)_isr_2, 0x08, 0x8E);
    set_idt_entry(3, (dword)_isr_3, 0x08, 0x8E);
    set_idt_entry(4, (dword)_isr_4, 0x08, 0x8E);
    set_idt_entry(5, (dword)_isr_5, 0x08, 0x8E);
    set_idt_entry(6, (dword)_isr_6, 0x08, 0x8E);
    set_idt_entry(7, (dword)_isr_7, 0x08, 0x8E);
    set_idt_entry(8, (dword)_isr_8, 0x08, 0x8E);
    set_idt_entry(9, (dword)_isr_9, 0x08, 0x8E);
    set_idt_entry(10, (dword)_isr_10, 0x08, 0x8E);
    set_idt_entry(11, (dword)_isr_11, 0x08, 0x8E);
    set_idt_entry(12, (dword)_isr_12, 0x08, 0x8E);
    set_idt_entry(13, (dword)_isr_13, 0x08, 0x8E);
    set_idt_entry(14, (dword)_isr_14, 0x08, 0x8E);
    set_idt_entry(15, (dword)_isr_15, 0x08, 0x8E);
    set_idt_entry(16, (dword)_isr_16, 0x08, 0x8E);
    set_idt_entry(17, (dword)_isr_17, 0x08, 0x8E);
    set_idt_entry(18, (dword)_isr_18, 0x08, 0x8E);
    set_idt_entry(19, (dword)_isr_19, 0x08, 0x8E);
    set_idt_entry(20, (dword)_isr_20, 0x08, 0x8E);
    set_idt_entry(21, (dword)_isr_21, 0x08, 0x8E);
    set_idt_entry(22, (dword)_isr_22, 0x08, 0x8E);
    set_idt_entry(23, (dword)_isr_23, 0x08, 0x8E);
    set_idt_entry(24, (dword)_isr_24, 0x08, 0x8E);
    set_idt_entry(25, (dword)_isr_25, 0x08, 0x8E);
    set_idt_entry(26, (dword)_isr_26, 0x08, 0x8E);
    set_idt_entry(27, (dword)_isr_27, 0x08, 0x8E);    
    set_idt_entry(28, (dword)_isr_28, 0x08, 0x8E);
    set_idt_entry(29, (dword)_isr_29, 0x08, 0x8E);
    set_idt_entry(30, (dword)_isr_30, 0x08, 0x8E);
    set_idt_entry(31, (dword)_isr_31, 0x08, 0x8E);

    load_idt();
}

 __attribute__((used,regparm(0)))  void fault_handler(struct regs *r)
{
    if (r->int_no < 32)
    {
        terminal_write_str(exception_messages[r->int_no]);
        terminal_write_str(" Exception. System Halted!");
        for (;;);
    }
}