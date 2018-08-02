BITS 32
global _start
extern kmain

%define MULTIBOOT_HEADER_MAGIC 0x1BADB002
%define MULTIBOOT_HEADER_FLAGS 0x00000000
%define CHECKSUM - (MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)

;-- Entry Point
_start:
        jmp start

;-- Multiboot header --
section .text
        align 4

        dd MULTIBOOT_HEADER_MAGIC
        dd MULTIBOOT_HEADER_FLAGS
        dd CHECKSUM
;-- /Multiboot header --

start:
        
        cli
        mov esp, stack_space
        call kmain
        hlt

section .bss
resb 8192
stack_space:

