ARCH 		=   x86
KERNEL      =   kernel.elf

include ./arch/$(ARCH)/boot/config.make
include ./arch/$(ARCH)/boot/Makefile

all : $(KERNEL)

$(KERNEL) 		: $(OBJS)
		$(LD) $(LDFLAGS) $(LD_SCRIPT) -o $@ $^

%.o 	: %.c
		$(GCC)	$(GCCFLAGS) $@ $^

%.o  	: %.asm
		$(NASM) $(NASMFLAGS) $@ $^

clean 	:
		rm -f ./arch/$(ARCH)/boot/*.o

run     :
		qemu-system-i386 -kernel $(KERNEL)