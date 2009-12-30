// defines methods for descriptor table
#ifndef DESCRIPTOR_TABLE_H
#define DESCRIPTOR_TABLE_H

// see http://wiki.osdev.org/Global_Descriptor_Table
// and http://wiki.osdev.org/Interrupts_Descriptor_Table

// GDT
// This structure contains the value of one GDT entry.
// We use the attribute 'packed' to tell GCC not to change
// any of the alignment in the structure.
// this is the structures as defined in Intel Reference docs
//
// access bit info-> 
// 7   6  5   4   3 2 1 0
// P:1 DPL:2 DT:1 Type:4
// P -> segment present (Valid bit)
// DPL -> Ring level (0->kernel, 3-> user)
// DT -> Descriptor Type
// Type -> type of entry
//
// Granuality bit info ->
// 7 6 5 4  3 2 1 0
// G D 0 A    Len
// G -> Garnuality (0=1byte,1=4kilo kyte)
// D -> Operand Size (0=16bit,1=32bit)
// 0 -> always 0
// A -> Avaliable for System (always 0)
struct gdt_entry_struct
{
    uint16_t limit_low;           // The lower 16 bits of the limit.
    uint16_t base_low;            // The lower 16 bits of the base.
    uint8_t  base_middle;         // The next 8 bits of the base.
    uint8_t  access;              // Access flags, determine what ring this segment can be used in.
    uint8_t  granularity;
    uint8_t  base_high;           // The last 8 bits of the base.
} __attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t; 

// holds individual value of an GDT entry
// We use the attribute 'packed' to tell GCC not to change
// any of the alignment in the structure.
struct gdt_ptr_struct
{
    uint16_t limit; // gdt limit value
    uint32_t base; // gdt base value
} __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

// init descriptor table
void init_descriptor_tables();


// IDT
// Intel Ref 3a 5.10, 5.11

// A struct describing an interrupt gate
// We use the attribute 'packed' to tell GCC not to change
// any of the alignment in the structure.
struct idt_entry_struct
{
   uint16_t base_lo;             // The lower 16 bits of the address to jump to when this interrupt fires.
   uint16_t sel;                 // Kernel segment selector.
   uint8_t  always0;             // This must always be zero.
   uint8_t  flags;               // More flags. See documentation.
   uint16_t base_hi;             // The upper 16 bits of the address to jump to.
} __attribute__((packed));
typedef struct idt_entry_struct idt_entry_t;

// A struct describing a pointer to an array of interrupt handlers.
// This is in a format suitable for giving to 'lidt'.
// We use the attribute 'packed' to tell GCC not to change
// any of the alignment in the structure.
struct idt_ptr_struct
{
   uint16_t limit;
   uint32_t base;                // The address of the first element in our idt_entry_t array.
} __attribute__((packed));
typedef struct idt_ptr_struct idt_ptr_t;

// These extern directives let us access the addresses of our ASM ISR handlers.
extern void isr0 ();
extern void isr1 ();
extern void isr2 ();
extern void isr3 ();
extern void isr4 ();
extern void isr5 ();
extern void isr6 ();
extern void isr7 ();
extern void isr8 ();
extern void isr9 ();
extern void isr10 ();
extern void isr11 ();
extern void isr12 ();
extern void isr13 ();
extern void isr14 ();
extern void isr15 ();
extern void isr16 ();
extern void isr17 ();
extern void isr18 ();
extern void isr19 ();
extern void isr20 ();
extern void isr21 ();
extern void isr22 ();
extern void isr23 ();
extern void isr24 ();
extern void isr25 ();
extern void isr26 ();
extern void isr27 ();
extern void isr28 ();
extern void isr29 ();
extern void isr30 ();
extern void isr31 ();

#endif
