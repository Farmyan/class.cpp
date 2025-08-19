BITS 16
ORG 0x7E00

start:
    xor ax, ax
    mov ds, ax
    mov es, ax

    mov bx, 0x8000
    mov es, bx
    mov ah, 0x02
    mov al, 16       
    mov ch, 0x00
    mov cl, 0x03
    mov dh, 0x00
    int 0x13
    jc vbr_error

    jmp 0x0000:0x8000

vbr_error:
    mov ah, 0x0E
    mov al, 'V'
    int 0x10
    jmp $

times 510-($-$$) db 0
dw 0xAA55
