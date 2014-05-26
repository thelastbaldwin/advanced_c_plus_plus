#pragma once

#include "Byte.h"

namespace BitmapGraphics
{
    
    class Color
    {
    public:
        explicit Color(const Binary::Byte& red = 0,
                       const Binary::Byte& green = 0,
                       const Binary::Byte& blue = 0);
        
        static Color read(std::istream& sourceStream);
        void write(std::ostream& destinationStream) const;
        
        Binary::Byte getRed() const;
        Binary::Byte getGreen() const;
        Binary::Byte getBlue() const;
        
        bool operator==(const Color& rhs) const;
        
    private:
        Binary::Byte myRed;
        Binary::Byte myGreen;
        Binary::Byte myBlue;
    };
    
    std::ostream& operator<<(std::ostream& os, const Color& color);
    
}