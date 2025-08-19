static void bios_putc(char c)
    {
        __asm__ __volatile__("movb $0x0E, %%ah\n\t" "int $0x10" : : "a"(c) : "cc");
    }

static void bios_puts(const char* s)
    {
        while(*s) bios_putc(*s++);
    }

void main()
    {
        bios_puts("Stage2 C kernel says hi!\r\n");
        bios_puts("Loaded by VBR using BIOS INT 13h.\r\n");
        for(;;)
            {
                __asm__ __volatile__("hlt");
            }
    }
