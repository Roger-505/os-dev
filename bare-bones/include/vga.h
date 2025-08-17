/*
******************************************************************************* 
* File name: vga.h
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

#ifndef VGA_H
#define VGA_H

#include <common.h> 
#include <ansi.h> 

/* Hardware text mode color constants */ 
enum vga_color 
{
	VGA_COLOR_BLACK = 0,
	VGA_COLOR_BLUE = 1,
	VGA_COLOR_GREEN = 2,
	VGA_COLOR_CYAN = 3,
	VGA_COLOR_RED = 4,
	VGA_COLOR_MAGENTA = 5,
	VGA_COLOR_BROWN = 6,
	VGA_COLOR_LIGHT_GREY = 7,
	VGA_COLOR_DARK_GREY = 8,
	VGA_COLOR_LIGHT_BLUE = 9,
	VGA_COLOR_LIGHT_GREEN = 10,
	VGA_COLOR_LIGHT_CYAN = 11,
	VGA_COLOR_LIGHT_RED = 12,
	VGA_COLOR_LIGHT_MAGENTA = 13,
	VGA_COLOR_LIGHT_BROWN = 14,
    VGA_COLOR_WHITE = 15,
};

#define VGA_WIDTH       80  
#define VGA_HEIGHT      25
#define VGA_MEM_SIZE    VGA_WIDTH*VGA_HEIGHT
#define VGA_MEMORY      0xb8000 /* Text mode base address */

#define CHAR_ADDR(x,y)  (y*VGA_WIDTH + x)
#define VGA_ADDR(x,y)   (CHAR_ADDR(x,y) + (void*)VGA_MEMORY)

extern size_t terminal_row;
extern size_t terminal_column;
extern uint8_t terminal_color;
extern uint16_t* terminal_buffer; // = (uint16_t*)VGA_MEMORY;

/*
******************************************************************************* 
*
* Function name: vga_entry_color
*
* Purpose: Set the color for a particular VGA character entry.
*
******************************************************************************* 
*/
uint8_t 
vga_entry_color(enum vga_color fg, enum vga_color bg);

/*
******************************************************************************* 
*
* Function name: vga_entry
*
* Purpose: Create a VGA character entry of a particular color.
*
******************************************************************************* 
*/
uint16_t 
vga_entry(unsigned char uc, uint8_t color);

/*
******************************************************************************* 
*
* Function name: terminal_initialize
*
* Purpose: Initialize a VGA text mode terminal.
*
******************************************************************************* 
*/
void
terminal_initialize(void);

/*
******************************************************************************* 
*
* Function name: terminal_setcolor
*
* Purpose: Set the color for an already initialized VGA text mode terminal.
*
******************************************************************************* 
*/
void
terminal_setcolor(uint8_t color);

/*
******************************************************************************* 
*
* Function name: terminal_putentryat
*
* Purpose: Put a VGA character entry at coordinates ('x','y') in the screen.
*
******************************************************************************* 
*/
void 
terminal_putentryat(char c, uint8_t color, size_t x, size_t y);

/*
******************************************************************************* 
*
* Function name: terminal_getentryat
*
* Purpose: Get a VGA character entry at coordinates ('x','y') in the screen.
*
******************************************************************************* 
*/
uint16_t
terminal_getentryat(size_t x, size_t y);

/*
******************************************************************************* 
*
* Function name: terminal_putchar
*
* Purpose: Put the next character in an already initialized VGA terminal.
*
******************************************************************************* 
*/
void
terminal_putchar(char c);

/*
******************************************************************************* 
*
* Function name: terminal_write
*
* Purpose: Write a string to an already initialized VGA terminal.
*
******************************************************************************* 
*/
void
terminal_puts(const char* data);

#endif // VGA_H
