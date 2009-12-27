// base.h -- Defines typedefs and some global functions.

#ifndef BASE_H
#define BASE_H

// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

#define NULL 0

// Write a byte out to the specified port.
void outb(u16int port, u8int value);

// Read (8bit) from the specified port
u8int inb(u16int port);

// Read (16bit) from the specified port
u16int inw(u16int port);

// Cause Delay of n millisec
void delay(u16int n);

#endif // BASE_H
