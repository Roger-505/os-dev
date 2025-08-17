/*
******************************************************************************* 
* File name: kernel.h
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
*
******************************************************************************* 
*/

#ifndef KERNEL_H
#define KERNEL_H

#include <common.h> 
#include <vga.h> 
#include <utils.h> 

/* Check if the compiler is targeting the wrong OS or target */
#if defined(__unix__)   || defined(_WIN32) || \
    defined(__APPLE__)  || !defined(__i386__)
#error You must use a ix86-elf cross-compiler!
#endif

/*
******************************************************************************* 
*
* Function name: kernel_main
*
* Purpose: Kernel entry point.
*
******************************************************************************* 
*/
void
kernel_main(void);

#endif // KERNEL_H
