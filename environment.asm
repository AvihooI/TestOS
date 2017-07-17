gdtr:
    gdt_limit   dw 8*5
    gdt_base    dd gd_table

align 8
gd_table:
.gdt_e_null:
    dd gdt_limit
    dd gdt_base
.gdt_e_code_0:
    dw 0xffff
    dw 0
    db 0
    db 0x9a
    db 11001111b
    db 0
.gdt_e_data_0:
    dw 0xffff
    dw 0
    db 0
    db 0x92
    db 11001111b
    db 0
.gdt_e_code_3:
    dw 0xffff
    dw 0
    db 0
    db 0xfa
    db 11001111b
    db 0
.gdt_e_data_3:
    dw 0xffff
    dw 0
    db 0
    db 0xf2
    db 11001111b
    db 0

global environment
environment:
    mov esp, stack_top
gdt_setup:   
    lgdt [gdtr]
    jmp 0x08:gdt_reload
gdt_reload:
    mov ax, 0x10
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
finish:
    extern kernel_main
    call kernel_main
    cli
    .hang: hlt
    jmp .hang

section .bss
align 4

stack_bottom:
resb 16384
stack_top:
