// screen.h -- Defines the interface for displaying text on screen

#ifndef SCREEN_H
#define SCREEN_H

#include "base.h"

// Write a single character out to the screen.
void put(char c);

// Clear the screen to all black.
void clear();

// Output a null-terminated ASCII string to the screen.
void puts(char *c);

// Set text color
void set_color(uint8_t color_f, uint8_t color_b);

// Goto (x,y)
void gotoxy(uint16_t x ,uint16_t y);

// Print text at (x,y)
void putsxy(char *c,uint16_t x ,uint16_t y);

// Format a string and print it on the screen
void printf (const char *format, ...);

#endif // SCREEN_H

