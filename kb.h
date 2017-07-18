#ifndef __kb_h_
#define __kb_h_

#include "io.h"
#include "types.h"

void init_kb();

void keyboard_handler(struct regs *r);

#endif