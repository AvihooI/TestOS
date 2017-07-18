section .text

global _irq_0
global _irq_1
global _irq_2
global _irq_3
global _irq_4
global _irq_5
global _irq_6
global _irq_7
global _irq_8
global _irq_9
global _irq_10
global _irq_11
global _irq_12
global _irq_13
global _irq_14
global _irq_15

_irq_0:
    cli
    push byte 0
    push byte 32
    jmp _irq_common

_irq_1:
    cli
    push byte 0
    push byte 33
    jmp _irq_common

_irq_2:
    cli
    push byte 0
    push byte 34
    jmp _irq_common

_irq_3:
    cli
    push byte 0
    push byte 35
    jmp _irq_common

_irq_4:
    cli
    push byte 0
    push byte 36
    jmp _irq_common

_irq_5:
    cli
    push byte 0
    push byte 37
    jmp _irq_common

_irq_6:
    cli
    push byte 0
    push byte 38
    jmp _irq_common

_irq_7:
    cli
    push byte 0
    push byte 39
    jmp _irq_common

_irq_8:
    cli
    push byte 0
    push byte 40
    jmp _irq_common

_irq_9:
    cli
    push byte 0
    push byte 41
    jmp _irq_common

_irq_10:
    cli
    push byte 0
    push byte 42
    jmp _irq_common

_irq_11:
    cli
    push byte 0
    push byte 43
    jmp _irq_common

_irq_12:
    cli
    push byte 0
    push byte 44
    jmp _irq_common

_irq_13:
    cli
    push byte 0
    push byte 45
    jmp _irq_common

_irq_14:
    cli
    push byte 0
    push byte 46
    jmp _irq_common

_irq_15:
    cli
    push byte 0
    push byte 47
    jmp _irq_common

_irq_common:
    pusha
    push ds
    push es
    push fs
    push gs
    mov ax, 0x10 ;Load ring-0 DS selector
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov eax, esp ;Push the stack
    push eax
    extern irq_main_handler
    call irq_main_handler
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8 ;cleans the pushed error code and pushed isr number
    iret ;pops CS, EIP, EFLAGS, SS and ESP
