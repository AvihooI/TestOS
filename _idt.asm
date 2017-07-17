idtr:
    idt_size    dw 256*8 - 1
    idt_offset  dd _idt
    

global _idt
align 8
_idt times 256 dq 0

global load_idt
load_idt:
    lidt [idtr]
    ret

global _isr_0
global _isr_1
global _isr_2
global _isr_3
global _isr_4
global _isr_5
global _isr_6
global _isr_7
global _isr_8
global _isr_9
global _isr_10
global _isr_11
global _isr_12
global _isr_13
global _isr_14
global _isr_15
global _isr_16
global _isr_17
global _isr_18
global _isr_19
global _isr_20
global _isr_21
global _isr_22
global _isr_23
global _isr_24
global _isr_25
global _isr_26
global _isr_27
global _isr_28
global _isr_29
global _isr_30
global _isr_31


extern isr_0
_isr_0: ;divide error, error code: no
    cli
    push byte 0
    push byte 0
    jmp _isr_common

_isr_1: ;debug exception, error code: no
    cli
    push byte 0
    push byte 1
    jmp _isr_common

_isr_2: ;NMI external interrupt, error code: no
    cli
    push byte 0
    push byte 2
    jmp _isr_common

_isr_3: ;Breakpoint, error code: no
    cli
    push byte 0
    push byte 3
    jmp _isr_common

_isr_4: ;Overflow, error code: no
    cli
    push byte 0
    push byte 4
    jmp _isr_common

_isr_5: ;Bound range exceeded, error code: no
    cli
    push byte 0
    push byte 5
    jmp _isr_common

_isr_6: ;Invalid opcode, error code: no
    cli
    push byte 0
    push byte 6
    jmp _isr_common

_isr_7: ;Device not available (no x87 coprocessor - shouldn't really happen), error code: no
    cli
    push byte 0
    push byte 7
    jmp _isr_common

_isr_8: ;Double Fault, error code: always 0
    cli 
    push byte 8
    jmp _isr_common

_isr_9: ;Coprocessor segment overrun, error code: no
    cli 
    push byte 0
    push byte 9
    jmp _isr_common

_isr_10: ;Invalid TSS, error code: yes
    cli 
    push byte 10
    jmp _isr_common

_isr_11: ;Segment not present, error code: yes
    cli 
    push byte 11
    jmp _isr_common

_isr_12: ;Stack-Segment fault, error code: yes
    cli 
    push byte 12
    jmp _isr_common

_isr_13: ;General Protection fault, error code: yes
    cli 
    push byte 13
    jmp _isr_common

_isr_14: ;Page fault, error code: yes
    cli 
    push byte 14
    jmp _isr_common

_isr_16: ;x87 floating point error (math fault), error code: no
    cli
    push byte 0
    push byte 16
    jmp _isr_common

_isr_17: ;Alignment Check, error code: yes
    cli
    push byte 17
    jmp _isr_common

_isr_18: ;Machine check, error code: no
    cli
    push byte 0
    push byte 18
    jmp _isr_common

_isr_19: ;SIMD floating point exception, error code: no
    cli
    push byte 0
    push byte 19
    jmp _isr_common

_isr_20: ;Virtualization exception, error code: no
    cli
    push byte 0
    push byte 20
    jmp _isr_common

_isr_15: ;reserved interrupts, error code: no
_isr_21:
_isr_22:
_isr_23:
_isr_24:
_isr_25:
_isr_26:
_isr_27:
_isr_28:
_isr_29:
_isr_30:
_isr_31:
    cli
    push byte 0
    push byte 15 ;doesn't really matter
    jmp _isr_common

_isr_common:
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
    extern fault_handler
    call fault_handler
    pop eax
    pop gs
    pop fs
    pop es
    pop ds
    popa
    add esp, 8 ;cleans the pushed error code and pushed isr number
    iret ;pops CS, EIP, EFLAGS, SS and ESP



