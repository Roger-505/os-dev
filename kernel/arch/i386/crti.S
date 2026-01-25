// SPDX-License-Identifier: GPL-3.0-or-later
/*
* Copyright (C) 2026 Roger Piovet
* 
* This file contains global constructors and destructors for C Runtime initialization.
*/
.section .init
.global _init
.type _init, @function
_init:
	push %ebp
	movl %esp, %ebp
	/* gcc will nicely put the contents of crtbegin.o's .init section here. */

.section .fini
.global _fini
.type _fini, @function
_fini:
	push %ebp
	movl %esp, %ebp
	/* gcc will nicely put the contents of crtbegin.o's .fini section here. */
