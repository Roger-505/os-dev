/*
******************************************************************************* 
* File name: utils.c
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

#include <utils.h>

void
sleep(void)
{
    // Do nothing for a while
    for (volatile int i = 0; i < 10000000; i++)
    {
        asm volatile("nop");
    }
}

