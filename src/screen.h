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
void set_color(u8int color_f, u8int color_b);
#endif // SCREEN_H
