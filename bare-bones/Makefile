# Tools
CROSS=i686-elf-
CC=$(CROSS)gcc
AS=$(CROSS)as
GRUB=grub-mkrescue
VM=qemu-system-i386

# Directories
OUT=build
SRC=src
ISO_DIR=$(OUT)/isodir
ISO_BOOT=$(ISO_DIR)/boot
GRUB_DIR=$(ISO_BOOT)/grub

# Targets
BOOT=boot
KERN=kernel
OS=myos

# Objects
boot_obj=$(OUT)/$(BOOT).o
kern_obj=$(OUT)/$(KERN).o
os_bin=$(OUT)/$(OS).bin
os_iso=$(OUT)/$(OS).iso

# Config files
GRUB_CFG=grub.cfg

# Flags
CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LDFLAGS=-ffreestanding -O2 -nostdlib

# Default target
all: run

# Output directory
$(OUT):
	mkdir $(OUT)

# Assemble bootloader
$(boot_obj): $(SRC)/$(BOOT).s | $(OUT)
	$(AS) $< -o $@

# Compile kernel
$(kern_obj): $(SRC)/$(KERN).c | $(OUT)
	$(CC) -c $< -o $@ $(CFLAGS)

# Link into one binary
$(os_bin): $(kern_obj) $(boot_obj)
	$(CC) -T $(SRC)/linker.ld -o $@ $^ $(LDFLAGS)

# Create ISO
$(os_iso): $(os_bin)
	mkdir -p $(GRUB_DIR)
	cp $< $(ISO_BOOT)
	cp $(SRC)/$(GRUB_CFG) $(GRUB_DIR)
	$(GRUB) -o $@ $(ISO_DIR)

# Run
run: $(os_iso)
	$(VM) -cdrom $<

clean:
	rm -rf $(OUT)

.PHONY: all clean run

