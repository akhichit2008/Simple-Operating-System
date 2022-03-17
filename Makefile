CC = gcc
all : compile_asm compile_kernel link_kernel build_iso start_emulation
compile_asm:
	as --32 boot.s -o boot.o
compile_kernel:
	gcc -m32 -c Kernel/src/kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra	
link_kernel:
	ld -m elf_i386 -T linker.ld kernel.o boot.o -o QOS.bin -nostdlib
build_iso:
	mkdir -p isodir/boot/grub
	cp QOS.bin isodir/boot/QOS.bin
	cp grub.cfg isodir/boot/grub/grub.cfg
	grub-mkrescue -o QOS.iso isodir	
start_emulation:
	qemu-system-x86_64 -cdrom QOS.iso	
