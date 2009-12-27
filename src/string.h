// string.h -- String handling functions

#ifndef STRING_H
#define STRING_H

#include "base.h"

// To count charachters in the string
int strlen(char *c);

// To copy from string a to string b for given length stating from start, for l=0  complete string is copied
void strcpy(char *a,char*b,int ,int);

// Simple function to copy contents of 2 memory locations.
unsigned char* memcpy (unsigned char *dest, const unsigned char * src, int count);

// Simple function to set the value at a memory location.
unsigned char* memset (unsigned char *dest, unsigned char val,int count);

#endif // STRING_H

