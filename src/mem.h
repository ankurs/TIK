// mem.h  Define Memory Related Functions

# ifndef MEM_H
# define MEM_H

# include "base.h"

// Simple function to copy contents of 2 memory locations.
unsigned char* memcpy (unsigned char *dest, const unsigned char * src, int count);

// Simple function to set the value at a memory location.
unsigned char* memset (unsigned char *dest, unsigned char val,int count);

#endif //MEM_H
