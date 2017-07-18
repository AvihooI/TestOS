#ifndef __pit_h__
#define __pit_h__

#include "io.h"

void pit_set_timer_phase(word hz);

void init_pit();

void timer_wait(dword ticks);

#endif