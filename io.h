#ifndef __io_h__
#define __io_h__

#include "types.h"

extern asmlinkage void outb(byte data, word port);
extern asmlinkage byte inb(word port);

#endif