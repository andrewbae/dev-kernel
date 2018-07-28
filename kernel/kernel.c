#include <linux/video.h>

void kmain(void)
{
		char *VideoText = "daniel smith kernel";

		vga_cls(0x0F);
		vga_write(VideoText, 0x0F);
		vga_write("overlap test ", 0x0F);
		vga_write("overlap test", 0x0F);
	return;
}