GCC 		= 	gcc
NASM 		=	nasm
LD			=	ld

GCCFLAGS 	=	-Iinclude/ -m32 -c -o
NASMFLAGS	= 	-f elf32 -o
LDFLAGS 	=	-m elf_i386 -T
LD_SCRIPT	=   arch/$(ARCH)/boot/setup.ld