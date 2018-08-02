#ifndef X86_BOOT_VIDEO_H
#define X86_BOOT_VIDEO_H

#ifndef TYPES_H
#include <linux/types.h>
#endif

#define VIDEO_WIDTH 80
#define VIDEO_HEIGHT 25
#define VIDEO_CHARACTER_BYTE 2
#define VIDEO_80x24 0xb8000       //General-Purpose I/O(256bytes 8000~80FF) in Memory-mapped I/O

#endif