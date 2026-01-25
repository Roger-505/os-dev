// SPDX-License-Identifier: GPL-3.0-or-later
/*
* Copyright (C) 2026 Roger Piovet
* 
* This header file declares functions to access a terminal over
* VGA on i386 machines.
*/

#ifndef _KERNEL_TTY_H
#define _KERNEL_TTY_H

#include <stddef.h>

void terminal_initialize(void);
void terminal_putchar(char c);
void terminal_write(const char* data, size_t size);
void terminal_writestring(const char* data);

#endif
