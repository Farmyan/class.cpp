BITS 16

global stage2_start
extern main
section .text
stage2_start:
    cli                 
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    mov sp, 0x9000      
    sti                 
    call main           
hang:
    jmp hang
