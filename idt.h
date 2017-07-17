#ifndef __idt_h__
#define __idt_h__

#include "types.h"

struct idt_entry
{
    word offset_lo;
    word cs_selector;
    byte reserved;
    byte type_attr;
    word offset_hi;
} __attribute__((packed));

extern struct idt_entry _idt[256];
extern void load_idt();

void set_idt_entry(size_t index, dword isr, word cs_selector, byte type_attr);

void init_idt();

struct regs
{
    dword gs, fs, es, ds;
    dword edi, esi, ebp, esp, ebx, edx, ecx, eax;
    dword int_no, err_code;
    dword eip, cs, eflags, useresp, ss;
} __attribute__((packed));;

extern void _isr_0();
extern void _isr_1();
extern void _isr_2();
extern void _isr_3();
extern void _isr_4();
extern void _isr_5();
extern void _isr_6();
extern void _isr_7();
extern void _isr_8();
extern void _isr_9();
extern void _isr_10();
extern void _isr_11();
extern void _isr_12();
extern void _isr_13();
extern void _isr_14();
extern void _isr_15();
extern void _isr_16();
extern void _isr_17();
extern void _isr_18();
extern void _isr_19();
extern void _isr_20();
extern void _isr_21();
extern void _isr_22();
extern void _isr_23();
extern void _isr_24();
extern void _isr_25();
extern void _isr_26();
extern void _isr_27();
extern void _isr_28();
extern void _isr_29();
extern void _isr_30();
extern void _isr_31();

__attribute__((used,regparm(0)))  void fault_handler(struct regs *r);

#endif