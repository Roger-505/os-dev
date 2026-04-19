// SPDX-License-Identifier: GPL-3.0-or-later
/*
* Copyright (C) 2026 Roger Piovet
* 
* Declare functions related to ANSI C compliance.
*/


#ifndef _STRING_H
#define _STRING_H

#include <sys/cdefs.h>

#include <stddef.h>
#include <stdint.h> 

#ifdef __cplusplus
extern "C" {
#endif

int memcmp(const void*, const void*, size_t);
void* memcpy(void* __restrict, const void* __restrict, size_t);
void* memmove(void*, const void*, size_t);
void* memset(void*, int, size_t);
size_t strlen(const char*);
void itos(int, char*);
void uitos(uint64_t, char*);

#ifdef __cplusplus
}
#endif

#endif
