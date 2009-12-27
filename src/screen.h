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
void set_color(u8int color_info);

// Goto (x,y)
void gotoxy(u16int x ,u16int y);

// Print text at (x,y)
void putsxy(char *c,u16int x ,u16int y);

// Format a string and print it on the screen
void printf (const char *format, ...);

#endif // SCREEN_H

