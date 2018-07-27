#define VGA_VIDEO_COLUMMS	 		80
#define VGA_VIDEO_LINES				25
#define VGA_VIDEO_CHARACTER_BYTE	2
#define VGA_VIDIO_MEMORY_ADDRESS	0xb8000 //General-Purpose I/O(256bytes 8000~80FF) in Memory-mapped I/O

void kmain(void)
{
        const char		*VideoText		= "daniel smith kernel";
        volatile char 	*VideoMemory	= (volatile char *)VGA_VIDIO_MEMORY_ADDRESS;
		
		unsigned int VideoTextNumber 	= 0;
		unsigned int VideoNumber		= 0;

		// Initialization VGA Memory space
	    while(VideoNumber < VGA_VIDEO_COLUMMS * VGA_VIDEO_LINES * VGA_VIDEO_CHARACTER_BYTE) {
		        VideoMemory[VideoNumber] = ' ';
				//VGA Text mode color(0x0F is set background to black and text color white)
		        VideoMemory[VideoNumber + 1] = 0x0F; 		
		        VideoNumber = VideoNumber + 2;
	    }

	    VideoNumber = 0;

	    while(VideoText[VideoTextNumber] != '\0') {
		        VideoMemory[VideoNumber] = VideoText[VideoTextNumber];
		        VideoMemory[VideoNumber + 1] = 0x0F;
		        ++VideoTextNumber;
		        VideoNumber = VideoNumber + 2;
	    }
        
	return;
}