gdtr:
gdt_limit      DW 0 ;limit
gdt_base       DD 0 ;base

global load_gdt
load_gdt:
    mov eax, [esp+4]
    mov cx, [esp+8]
    mov [gdt_base], eax
    mov [gdt_limit], cx
    lgdt [gdtr]
    ret
