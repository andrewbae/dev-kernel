#include "os.h"
#include "video.h"

static int video_cls(int TextColor)
{
        volatile u8_t *VideoMemory = (volatile u8_t *)VIDEO_80x24;
        u32_t count = 0;

        while (count < VIDEO_WIDTH * VIDEO_HEIGHT * VIDEO_CHARACTER_BYTE) {
                *(VideoMemory + count) = ' ';
                *(VideoMemory + (count + 1)) = TextColor;
                count = count + VIDEO_CHARACTER_BYTE;
        }
        return 0;
}

static int video_print(volatile u8_t *string, int TextColor)
{
        volatile u8_t *VideoMemory = (volatile u8_t *)VIDEO_80x24;
        u32_t count = 0;
        while (*(string + (count / 2)) != '\0') {
                *(VideoMemory + count) = *(string + (count / 2));
                *(VideoMemory + (count + 1)) = TextColor;
                count = count + VIDEO_CHARACTER_BYTE;
        }
        return 0;
}

void set_video(void)
{
        video_cls(0x0F);
        video_print("Daniel Smith Kernel", 0x0F);
}