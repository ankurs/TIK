// base.h -- Defines typedefs and some global functions.

#ifndef BASE_H
#define BASE_H

// Some nice typedefs, to standardise sizes across platforms.
// These typedefs are written for 32-bit X86.
typedef unsigned int   uint32_t;
typedef          int   sint32_t;
typedef unsigned short uint16_t;
typedef          short sint16_t;
typedef unsigned char  uint8_t;
typedef          char  sint8_t;

#define NULL 0

// Write a byte out to the specified port.
void outb(uint16_t port, uint8_t value);

// Read (8bit) from the specified port
uint8_t inb(uint16_t port);

// Read (16bit) from the specified port
uint16_t inw(uint16_t port);

#endif // BASE_H
