#pragma once

namespace BitmapGraphics
{
    const std::string WindowsBitmapMimeType = "image/x-ms-bmp";
	
    inline int getNumberOfPadBytes(int width)
    {
        int remainder = (width * 3) % 4;
        return (remainder == 0) ? 0 : (4 - remainder);
    }
	
}