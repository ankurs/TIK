[GLOBAL gdt_flush]
gdt_flush:
    mov eax,[esp+4] ; pointer to new gdt passed as parameter
    lgdt [eax]    ; load the new GDT pointer value
    mov ax,0x10   ; offset in GDT to our data segment as kernel data segment is the 3rd entry
    ; load all segment registers
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    jmp 0x08:flush; 0x08 is the offset to our code segment as kernel code segment is 2nd entry
flush:
    ret ; return

[GLOBAL idt_flush]
idt_flush:
    mov eax, [esp+4] ; Get the pointer to the IDT
    lidt [eax]       ; Load the IDT pointer
    ret              ; return
