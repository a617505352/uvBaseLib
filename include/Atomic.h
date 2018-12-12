#ifndef _UV_LIB_ATOMIC_H_
#define _UV_LIB_ATOMIC_H_

#include <stdio.h>

long atomic_inc_long(volatile long *val);
long atomic_dec_long(volatile long *val);
long atomic_set_long(volatile long *ptr, long val);
long atomic_load_long(const volatile long *ptr);
bool atomic_compare_swap_long(volatile long *val, long old_val, long new_val);
bool atomic_set_bool(volatile bool *ptr, bool val);
bool atomic_load_bool(const volatile bool *ptr);

#endif
