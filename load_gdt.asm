gdtr:
gdt_limit      DW 0 ;limit
gdt_base       DD 0 ;base

global load_gdt
load_gdt:
    mov eax, [esp+4]
    mov ch, [esp+8]
    mov [gdt_limit], eax
    mov [gdt_base], ch
    lgdt [gdtr]
    ret
