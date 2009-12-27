#include "base.h"
#include "descriptor_table.h"

// see http://wiki.osdev.org/Global_Descriptor_Table
// and http://wiki.osdev.org/Interrupts_Descriptor_Table

// initialize the GDT and IDT
// set the default interrupt handlers

// gdt_flush defined in asm file for loading the GDT pointer
extern void gdt_flush(u32int);

// some more function prototype
static void init_gdt();
static void gdt_set_gate(s32int,u32int,u32int,u8int,u8int);

// define entries and pointers for GDT and IDT
gdt_entry_t gdt_entries[5];
gdt_ptr_t gdt_ptr;
idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

// blanks all the descriptor table entries
void init_descriptor_tables()
{
    init_gdt();
}

static void init_gdt()
{
    gdt_ptr.limit = (sizeof(
}
