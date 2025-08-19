BITS 16
ORG 0x7C00

start:
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x7C00

    mov bx, 0x7E00
    mov es, bx

    mov ah, 0x02  
    mov al, 0x01  
    mov ch, 0x00
    mov cl, 0x02
    mov dh, 0x00
    int 0x13
    jc disk_error

    jmp 0x0000:0x7E00

disk_error:
    mov ah, 0x0E
    mov al, 'E'
    int 0x10
hang:
    hlt
    jmp hang

times 446 db 0
db 0x80,0,2,0,6,0,32,63,0
dd 1
dd 0x1000
times 16*3 db 0

dw 0xAA55
