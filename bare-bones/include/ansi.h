/*
******************************************************************************* 
* File name: ansi.h
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

#ifndef ANSI_H
#define ANSI_H

#include <common.h>

/*
******************************************************************************* 
*
* Function name: itos
*
* Purpose: Convert a integer to a string.
*
******************************************************************************* 
*/
void itos(int n, char* str);

/*
******************************************************************************* 
*
* Function name: memset
*
* Purpose: Set 'n' bytes to the value 'c' starting at the address 'd'.
*
******************************************************************************* 
*/
void*
memset(void* d, int c, size_t n);

/*
******************************************************************************* 
*
* Function name: memcpy
*
* Purpose: Copy 'n' bytes starting from address 's' to the destination address
*          staring at 'd'.
*
******************************************************************************* 
*/
void*
memcpy(void* d, void* s, size_t n);

/*
******************************************************************************* 
*
* Function name: strlen
*
* Purpose: Get the size of a null-terminated string.
*
******************************************************************************* 
*/
size_t 
strlen(const char* str);

#endif // ANSI_H
