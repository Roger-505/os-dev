/*
******************************************************************************* 
* File name: ansi.c
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

#include <ansi.h> 

void itos(int n, char* str)
{
    int sign = n;
    int i = 0;

    // Get the positive number, if n is negative
    if (n < 0)
    {
        n = -n;
    }

    // Extract digits and convert them to char in str
    while (n > 0)
    {
        str[i++] = n % 10 + '0';
        n /= 10;
    }

    // Add minus sign
    if (sign < 0)
    {
        str[i++] = '-';
    }

    // Null termination
    str[i] = '\0';

    // Reverse the string
    char temp;

    for (int j = 0, k = i - 1; j < k; j++, k--)
    {
        temp = str[j];
        str[j] = str[k];
        str[k] = temp;
    }
}

void*
memset(void* d, int c, size_t n)
{
    uint8_t* dest = (uint8_t*)d;

    do { *dest++ = (uint8_t)c; } while(--n);

    return d;
}

void*
memcpy(void* d, void* s, size_t n)
{
    uint8_t* dest = (uint8_t*)d;
    uint8_t* src  = (uint8_t*)s;

    do { *dest++ = *src++; } while (--n);
    
    return d;
}

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
