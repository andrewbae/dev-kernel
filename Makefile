GCC 		= 	gcc
NASM 		=	nasm
LD			=	ld

GCCFLAGS 	=	-Iinclude/ -m32 -c -o
NASMFLAGS	= 	-f elf32 -o
LDFLAGS 	=	-m elf_i386 -T

SRCS_GCC	=	kernel/kernel.c
SRCS_NASM	=	boot/boot.asm
SRCS_LD		=	my_kernel

OBJS_GCC	=	kernel.o
OBJS_NASM	=	boot.o
OBJS_LD		=   $(OBJS_NASM) $(OBJS_GCC)

LD_SCRIPT	=   ld/linker.ld

all : $(SRCS_LD)

$(OBJS_GCC)		: $(SRCS_GCC)
		$(GCC)	$(GCCFLAGS) $@ $^

$(OBJS_NASM) 	: $(SRCS_NASM)
		$(NASM) $(NASMFLAGS) $@ $^
		
$(SRCS_LD) 		: $(OBJS_LD)
		$(LD) $(LDFLAGS) $(LD_SCRIPT) -o $@ $^

clean 	:
		rm *.o $(OBJS_LD)
