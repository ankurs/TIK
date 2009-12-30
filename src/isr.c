//
// isr.c -- High level interrupt service routines and interrupt request handlers.
//

#include "base.h"
#include "isr.h"
#include "screen.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers_t regs)
{
   printf("recieved interrupt: %i\n",regs.int_no);
} 
