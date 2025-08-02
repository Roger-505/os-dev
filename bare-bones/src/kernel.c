/*
******************************************************************************* 
* File name: kernel.c
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

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

/* Check if the compiler is targeting the wrong OS or target */
#if defined(__unix__)   || defined(_WIN32) || \
    defined(__APPLE__)  || !defined(__i386__)
#error You must use a ix86-elf cross-compiler!
#endif

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

#define VGA_WIDTH   80  
#define VGA_HEIGHT  25
#define VGA_MEMORY  0xb8000 /* Text mode base address */

#define CHAR_ADDR(x,y) (y*VGA_WIDTH + x)

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer = (uint16_t*)VGA_MEMORY;

/*
******************************************************************************* 
*
* Function name: vga_entry_color
*
* Purpose: TBD
*
******************************************************************************* 
*/
static inline uint8_t 
vga_entry_color(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}

/*
******************************************************************************* 
*
* Function name: vga_entry
*
* Purpose: TBD
*
******************************************************************************* 
*/
static inline uint16_t 
vga_entry(unsigned char uc, uint8_t color)
{
    return (uint16_t)uc | (uint16_t)color << 8; 
}

/*
******************************************************************************* 
*
* Function name: strlen
*
* Purpose: TBD
*
******************************************************************************* 
*/
size_t 
strlen(const char* str)
{
    size_t len = 0;
    while (str[len])
    {
        len++;
    }
    return len; 
}

/*
******************************************************************************* 
*
* Function name: terminal_initialize
*
* Purpose: TBD
*
******************************************************************************* 
*/
void
terminal_initialize(void)
{
    terminal_row = 0;
    terminal_column = 0;
    terminal_color = vga_entry(VGA_COLOR_RED, VGA_COLOR_BLACK);

    size_t x, y, index;
    for (y = 0; y < VGA_HEIGHT; y++)
    {
        for (x = 0; x < VGA_WIDTH; x++)
        {
            index = CHAR_ADDR(x,y);
            terminal_buffer[index] = vga_entry(' ', terminal_color);
        }
    }

}

/*
******************************************************************************* 
*
* Function name: terminal_setcolor
*
* Purpose: TBD
*
******************************************************************************* 
*/
void
terminal_setcolor(uint8_t color)
{
    terminal_color = color;
}

/*
******************************************************************************* 
*
* Function name: terminal_putentryat
*
* Purpose: TBD
*
******************************************************************************* 
*/
void 
terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
    size_t index;

    index = CHAR_ADDR(x,y);
    terminal_buffer[index] = vga_entry(c, color);
}

/*
******************************************************************************* 
*
* Function name: terminal_putchar
*
* Purpose: TBD
*
******************************************************************************* 
*/
void
terminal_putchar(char c)
{
    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);
    if (++terminal_column == VGA_WIDTH)
    {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT)
        {
            terminal_row = 0;
        }
    }
}

/*
******************************************************************************* 
*
* Function name: terminal_write
*
* Purpose: TBD
*
******************************************************************************* 
*/
void
terminal_write(const char* data, size_t size)
{
    size_t i;

    for (i = 0; i < size; i++)
    {
        terminal_putchar(data[i]);
    }
}

/*
******************************************************************************* 
*
* Function name: terminal_puts
*
* Purpose: TBD
*
******************************************************************************* 
*/
void
terminal_puts(const char* str)
{
    terminal_write(str, strlen(str));
}

/*
******************************************************************************* 
*
* Function name: kernel_main
*
* Purpose: TBD
*
******************************************************************************* 
*/
void
kernel_main(void)
{
    /* Terminal init */
    terminal_initialize();

    terminal_puts("Hola mundo!\n");
}
