section .text

global outb
outb:
    mov edx, [esp+4]
    mov eax, [esp+8]
    out dx, al 
    ret

global inb
inb:
    mov edx, [esp+4]
    xor eax, eax
    in al, dx
    ret