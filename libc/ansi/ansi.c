// SPDX-License-Identifier: GPL-3.0-or-later
/*
* Copyright (C) 2026 Roger Piovet
* 
* Define functions related to ANSI C compliance.
*/

#include <ansi.h>

int memcmp(const void* aptr, const void* bptr, size_t size) {
	const unsigned char* a = (const unsigned char*) aptr;
	const unsigned char* b = (const unsigned char*) bptr;
	for (size_t i = 0; i < size; i++) {
		if (a[i] < b[i])
			return -1;
		else if (b[i] < a[i])
			return 1;
	}
	return 0;
}

void* memcpy(void* restrict dstptr, const void* restrict srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	for (size_t i = 0; i < size; i++)
		dst[i] = src[i];
	return dstptr;
}


void* memmove(void* dstptr, const void* srcptr, size_t size) {
	unsigned char* dst = (unsigned char*) dstptr;
	const unsigned char* src = (const unsigned char*) srcptr;
	if (dst < src) {
		for (size_t i = 0; i < size; i++)
			dst[i] = src[i];
	} else {
		for (size_t i = size; i != 0; i--)
			dst[i-1] = src[i-1];
	}
	return dstptr;
}

void* memset(void* bufptr, int value, size_t size) {
	unsigned char* buf = (unsigned char*) bufptr;
	for (size_t i = 0; i < size; i++)
		buf[i] = (unsigned char) value;
	return bufptr;
}

size_t strlen(const char* str) {
	size_t len = 0;
	while (str[len])
		len++;
	return len;
}


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
