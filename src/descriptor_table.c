#include "base.h"
#include "descriptor_table.h"
//remove this
#include "screen.h"

// see http://wiki.osdev.org/Global_Descriptor_Table
// and http://wiki.osdev.org/Interrupts_Descriptor_Table

// For GDT

// initialize the GDT
// gdt_flush defined in asm file for loading the GDT pointer
extern void gdt_flush(uint32_t);

// some more function prototype
static void init_gdt();
static void gdt_set_gate(uint32_t,uint32_t,uint32_t,uint8_t,uint8_t);

// define entries and pointers for GDT and IDT
gdt_entry_t gdt_entries[5];
gdt_ptr_t gdt_ptr;
idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

static void init_gdt()
{
    gdt_ptr.limit = (sizeof(gdt_entry_t)*5)-1; // we have 5 entries
    gdt_ptr.base = (uint32_t)&gdt_entries;
    gdt_set_gate(0,0,0,0,0); // NULL segment
    gdt_set_gate(1,0,0xFFFFFFFF,0x9A,0xCF); // Kernel Code segment
    gdt_set_gate(2,0,0xFFFFFFFF,0x92,0xCF); // Kernel Data segment
    gdt_set_gate(1,0,0xFFFFFFFF,0xFA,0xCF); // User mode code segment
    gdt_set_gate(1,0,0xFFFFFFFF,0xF2,0xCF); // User mode data segment  

    gdt_flush((uint32_t)&gdt_ptr);
}

// to set values of GDT entries
// read description in header file for more info
// gdt_entry_t specific info 
// access bit info-> 
// 7   6  5   4   3 2 1 0
// P  DPL:2  DT   Type:4
// P -> segment present (Valid bit)
// DPL -> Ring level (0->kernel, 3-> user)
// DT -> Descriptor Type
// Type -> type of entry
//
// Granuality bit info ->
// 7 6 5 4  3 2 1 0
// G D 0 A    Len:4
// G -> Garnuality (0=1byte,1=4kilo kyte)
// D -> Operand Size (0=16bit,1=32bit)
// 0 -> always 0
// A -> Avaliable for System (always 0)

static void gdt_set_gate(uint32_t num, uint32_t base,uint32_t limit ,uint8_t access, uint8_t gran)
{
    gdt_entries[num].base_low = (base & 0xFFFF);
    gdt_entries[num].base_middle = ((base>>16)&0xFF);
    gdt_entries[num].base_high = ((base>>24)&0xFF);
    gdt_entries[num].limit_low   = (limit & 0xFFFF);
    gdt_entries[num].granularity = (limit >> 16) & 0x0F;
    gdt_entries[num].granularity |= gran & 0xF0;
    gdt_entries[num].access = access;
}


// For IDT
extern void idt_flush(uint32_t);

static void init_idt();
static void idt_set_gate(uint8_t,uint32_t,uint16_t,uint8_t);

idt_entry_t idt_entries[256];
idt_ptr_t idt_ptr;

static void init_idt()
{
    idt_ptr.limit = sizeof(idt_entry_t) * 256 -1;
    idt_ptr.base  = (uint32_t)&idt_entries;
    memset((unsigned char*) &idt_entries, 0, sizeof(idt_entry_t)*256);

    idt_set_gate( 0, (uint32_t)isr0 , 0x08, 0x8E);
    idt_set_gate( 1, (uint32_t)isr1 , 0x08, 0x8E);
    idt_set_gate( 2, (uint32_t)isr2 , 0x08, 0x8E);
    idt_set_gate( 3, (uint32_t)isr3 , 0x08, 0x8E);
    idt_set_gate( 4, (uint32_t)isr4 , 0x08, 0x8E);
    idt_set_gate( 5, (uint32_t)isr5 , 0x08, 0x8E);
    idt_set_gate( 6, (uint32_t)isr6 , 0x08, 0x8E);
    idt_set_gate( 7, (uint32_t)isr7 , 0x08, 0x8E);
    idt_set_gate( 8, (uint32_t)isr8 , 0x08, 0x8E);
    idt_set_gate( 9, (uint32_t)isr9 , 0x08, 0x8E);
    idt_set_gate( 10, (uint32_t)isr10 , 0x08, 0x8E);
    idt_set_gate( 11, (uint32_t)isr11 , 0x08, 0x8E);
    idt_set_gate( 12, (uint32_t)isr12 , 0x08, 0x8E);
    idt_set_gate( 13, (uint32_t)isr13 , 0x08, 0x8E);
    idt_set_gate( 14, (uint32_t)isr14 , 0x08, 0x8E);
    idt_set_gate( 15, (uint32_t)isr15 , 0x08, 0x8E);
    idt_set_gate( 16, (uint32_t)isr16 , 0x08, 0x8E);
    idt_set_gate( 17, (uint32_t)isr17 , 0x08, 0x8E);
    idt_set_gate( 18, (uint32_t)isr18 , 0x08, 0x8E);
    idt_set_gate( 19, (uint32_t)isr19 , 0x08, 0x8E);
    idt_set_gate( 20, (uint32_t)isr20 , 0x08, 0x8E);
    idt_set_gate( 21, (uint32_t)isr21 , 0x08, 0x8E);
    idt_set_gate( 22, (uint32_t)isr22 , 0x08, 0x8E);
    idt_set_gate( 23, (uint32_t)isr23 , 0x08, 0x8E);
    idt_set_gate( 24, (uint32_t)isr24 , 0x08, 0x8E);
    idt_set_gate( 25, (uint32_t)isr25 , 0x08, 0x8E);
    idt_set_gate( 26, (uint32_t)isr26 , 0x08, 0x8E);
    idt_set_gate( 27, (uint32_t)isr27 , 0x08, 0x8E);
    idt_set_gate( 28, (uint32_t)isr28 , 0x08, 0x8E);
    idt_set_gate( 29, (uint32_t)isr29 , 0x08, 0x8E);
    idt_set_gate( 30, (uint32_t)isr30 , 0x08, 0x8E);
    idt_set_gate( 31, (uint32_t)isr31, 0x08, 0x8E);

    idt_flush((uint32_t)&idt_ptr);
}

// sets individual ide entry
// flags -> 
// 7 6 5 4 3 2 1 0
// P DPL:2  (01110):5
// P -> is segment present
// DPL -> Ring level (0=kernel,3=user)
static void idt_set_gate(uint8_t num, uint32_t base, uint16_t sel, uint8_t flags)
{
    idt_entries[num].base_lo = base & 0xFFFF;
    idt_entries[num].base_hi = (base >> 16) & 0xFFFF;
    idt_entries[num].sel     = sel;
    idt_entries[num].always0 = 0;
    idt_entries[num].flags   = flags;
}


// reloads all the descriptor table entries
void init_descriptor_tables()
{
    printf("\n in Init");
    init_gdt();
    init_idt();
    printf("\ninit done");
}

