gdtr:
gdt_limit      DW 0 ;limit
gdt_base       DD 0 ;base

global load_gdt
load_gdt:
    mov eax, [esp+4] ;load base parameter
    mov cx, [esp+8] ;load limit parameter
    mov [gdt_base], eax
    mov [gdt_limit], cx
    lgdt [gdtr]
    jmp 2*8:reload
reload:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    ret 
