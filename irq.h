#ifndef __irq_h__
#define __irq_h__

#include "types.h"

extern void _irq_0();
extern void _irq_1();
extern void _irq_2();
extern void _irq_3();
extern void _irq_4();
extern void _irq_5();
extern void _irq_6();
extern void _irq_7();
extern void _irq_8();
extern void _irq_9();
extern void _irq_10();
extern void _irq_11();
extern void _irq_12();
extern void _irq_13();
extern void _irq_14();
extern void _irq_15();

asmlinkage void irq_main_handler(struct regs *r);

void set_irq_handler(byte irq, void (*handler)(struct regs *r));

void irq_remap();
void init_irq();

#endif
