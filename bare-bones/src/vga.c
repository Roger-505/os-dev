/*
******************************************************************************* 
* File name: vga.c
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

#include <vga.h>

size_t terminal_row;
size_t terminal_column;
uint8_t terminal_color;
uint16_t* terminal_buffer  = (uint16_t*)VGA_MEMORY;

uint8_t 
vga_entry_color(enum vga_color fg, enum vga_color bg)
{
    return fg | bg << 4;
}

uint16_t 
vga_entry(unsigned char uc, uint8_t color)
{
    return (uint16_t)uc | (uint16_t)color << 8; 
}

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

void
terminal_setcolor(uint8_t color)
{
    terminal_color = color;
}

void 
terminal_putentryat(char c, uint8_t color, size_t x, size_t y)
{
    size_t index;

    index = CHAR_ADDR(x,y);
    terminal_buffer[index] = vga_entry(c, color);
}

uint16_t
terminal_getentryat(size_t x, size_t y)
{
    size_t index;

    index = CHAR_ADDR(x,y);
    return terminal_buffer[index];
}

void
terminal_putchar(char c)
{
    bool is_logical_entity;

    // Handle logical entities
    is_logical_entity = false;

    // TODO: Handle edge cases 
    // For example: Handle new line char at the final line.
    switch (c)
    {
        case '\n':
            terminal_row++;
            terminal_column = 0;
            is_logical_entity = true;
            break;
        case '\r':
            terminal_column = 0;
            is_logical_entity = true;
            break;
        case '\t':
            // 4 space tab
            terminal_column += 4;
            is_logical_entity = true;
            break;
        case '\0':
            // Do nothing
            is_logical_entity = true;
            break;
        case '\a':
            // TODO: Generate a beep!
            is_logical_entity = true;
            break;
        default:
            // Case for printable ASCII chars
            break;
    }

    if (is_logical_entity)
    {
        // Do not print as ASCII char
        return;
    }

    terminal_putentryat(c, terminal_color, terminal_column, terminal_row);

    if (++terminal_column == VGA_WIDTH)
    {
        terminal_column = 0;
        if (++terminal_row == VGA_HEIGHT)
        {
            // Scroll the terminal
            terminal_row = VGA_HEIGHT-1;
            for(size_t row = 0; row < VGA_HEIGHT; row++)   
            {
                for (size_t column = 0; column < VGA_WIDTH; column++)
                {
                    terminal_buffer[CHAR_ADDR(column, row)] =
                        (row != VGA_HEIGHT - 1)
                            ? terminal_getentryat(column, row + 1)
                            : vga_entry(' ', terminal_color);
                }
            }
        }
    }
}

void
terminal_puts(const char* data)
{
    size_t i, size;

    size = strlen(data);
    for (i = 0; i < size; i++)
    {
        terminal_putchar(data[i]);
    }
}
