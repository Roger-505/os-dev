// SPDX-License-Identifier: GPL-3.0-or-later
/*
* Copyright (C) 2026 Roger Piovet
* 
* Kernel's main function.
*/

#include <stdio.h>
#include <kernel/tty.h>
#include <stdint.h> 
#include <ansi.h> 
#include <cpuid.h> 

/* TODO: Move this into it's own module, and fix the broken code. */
uint64_t readTSC(void)
{
  uint32_t low, high;
  asm volatile("rdtsc" : "=a"(low), "=d"(high));
  return ((uint64_t)high << 32) | (low);
}

/* https://en.wikipedia.org/wiki/CPUID */
int readCPUID(void)
{
    unsigned int regs[12];
    char str[sizeof(regs)+1];

    __cpuid(0x80000000, regs[0], regs[1], regs[2], regs[3]);

    if (regs[0] < 0x80000004)
        return 1;

    __cpuid(0x80000002, regs[0], regs[1], regs[2], regs[3]);
    __cpuid(0x80000003, regs[4], regs[5], regs[6], regs[7]);
    __cpuid(0x80000004, regs[8], regs[9], regs[10], regs[11]);

    memcpy(str, regs, sizeof(regs));
    str[sizeof(regs)] = '\0';
    printf("%s\n", str);
}

void kernel_main(void) {
	terminal_initialize();
  /* gdt_init(); */
  char buffer[16];
  while (1)
  {
    /*
    uitos(readTSC(), buffer);
	  terminal_writestring("Hello, kernel World! Current timestamp: ");
    terminal_writestring(buffer);
    terminal_writestring("\n");
    for (uint64_t i = 0; i < 10000000000; i++)
      asm volatile("nop");
    */
    uitos(readTSC(), buffer);
	  terminal_writestring("Hello, kernel World! Current timestamp: ");
    terminal_writestring(buffer);
    terminal_writestring("\n");
    for (uint64_t i = 0; i < 100000000; i++)
      asm volatile("nop");
    readCPUID();
    //terminal_initialize();
  }
}
