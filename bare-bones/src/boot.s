/*
* boot.s
*
* Copyright (C) 2025 Roger Piovet
* All rights reserved.
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 3
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*/

/* Declare constants for the multiboot header */ 
.set ALIGN, 	1<<0		/* Bit mask for page boundary aligned loaded modules */ 
.set MEMINFO, 	1<<1		/* Bit mask for providing a memory map */
.set FLAGS,	ALIGN | MEMINFO	/* Multiboot's 'flag' field */
.set MAGIC, 	0x1badb002	/* Multiboot's 'magic number' */
.set CHECKSUM, 	-(MAGIC+FLAGS)	/* Checksum of above fields */

/* Declare multiboot header */
.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM

/* Declare constants to provide a 16KiB stack */
.section .bss
.align 16
stack_bottom: 
.skip 16384	# 16KiB
stack_top:

/* Entry point */
.section .text
.global _start
.type _start, @function
_start:
	/* Provide a stack */
	mov $stack_top, %esp
	
	/* Jump to the kernel */
	call kernel_main

	/* Infinite loop */
	cli
1:	hlt
	jmp 1b

/* Set size of _start symbol */
.size _start, . - _start
