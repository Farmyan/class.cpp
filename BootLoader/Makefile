NASM = nasm
CC   = clang
LD   = ld

NASM_BINFLAGS = -f bin
NASM_ELFFLAGS = -f elf32

CFLAGS = -ffreestanding -fno-pie -m32 -nostdlib -g
LDFLAGS = -m elf_i386 -Ttext 0x8000 --oformat binary

SRC_ASM_DIR = src/asm
SRC_C_DIR   = src/c
BUILD_DIR   = build
ASM_OBJ_DIR = $(BUILD_DIR)/obj/asm
C_OBJ_DIR   = $(BUILD_DIR)/obj/c

MBR_BIN    = $(BUILD_DIR)/mbr.bin
VBR_BIN    = $(BUILD_DIR)/vbr.bin
STAGE2_BIN = $(BUILD_DIR)/stage2.bin
DISK_IMG   = $(BUILD_DIR)/disk.img

C_SRC   = $(wildcard $(SRC_C_DIR)/*.c)
C_OBJ   = $(patsubst $(SRC_C_DIR)/%.c,$(C_OBJ_DIR)/%.o,$(C_SRC))
ASM_OBJ_ELF = $(ASM_OBJ_DIR)/stage2_entry.o

STAGE2_SECTORS = 16

all: $(DISK_IMG)

$(MBR_BIN): $(SRC_ASM_DIR)/mbr.asm
	@mkdir -p $(BUILD_DIR)
	$(NASM) $(NASM_BINFLAGS) $< -o $@

$(VBR_BIN): $(SRC_ASM_DIR)/vbr.asm
	@mkdir -p $(BUILD_DIR)
	$(NASM) $(NASM_BINFLAGS) $< -o $@

$(ASM_OBJ_ELF): $(SRC_ASM_DIR)/stage2_entry.asm | $(ASM_OBJ_DIR)
	@mkdir -p $(ASM_OBJ_DIR)
	$(NASM) $(NASM_ELFFLAGS) $< -o $@

$(C_OBJ_DIR)/%.o: $(SRC_C_DIR)/%.c | $(C_OBJ_DIR)
	@mkdir -p $(C_OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(STAGE2_BIN): $(ASM_OBJ_ELF) $(C_OBJ)
	$(LD) $(LDFLAGS) -o $@ $^
	truncate -s $$(( $(STAGE2_SECTORS)*512 )) $@

$(DISK_IMG): $(MBR_BIN) $(VBR_BIN) $(STAGE2_BIN)
	@mkdir -p $(BUILD_DIR)
	truncate -s 10M $@
	dd if=$(MBR_BIN) of=$@ conv=notrunc
	dd if=$(VBR_BIN) of=$@ bs=512 seek=1 conv=notrunc
	dd if=$(STAGE2_BIN) of=$@ bs=512 seek=2 conv=notrunc
	@echo "Disk image built: $@"

$(ASM_OBJ_DIR) $(C_OBJ_DIR):
	mkdir -p $@

clean:
	rm -rf $(BUILD_DIR)

.PHONY: all clean
