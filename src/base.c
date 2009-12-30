// base.c -- Defines some global functions.

#include "base.h"


void outb(uint16_t port, uint8_t value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

uint8_t inb(uint16_t port)
{
   uint8_t ret;
   asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

uint16_t inw(uint16_t port)
{
   uint16_t ret;
   asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

unsigned char* memset (unsigned char *dest, unsigned char val,int count)
{
  int i;
  for(i=0; i<count; i++) 
        dest[i]=val;
  return dest;
}

