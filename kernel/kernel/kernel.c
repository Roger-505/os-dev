// SPDX-License-Identifier: GPL-3.0-or-later
/*
* Copyright (C) 2026 Roger Piovet
* 
* Kernel's main function.
*/

#include <stdio.h>
#include <kernel/tty.h>

void kernel_main(void) {
	terminal_initialize();
	printf("Hello, kernel World!\n");
    printf("Hello from the kernel, second line!\n");
}
