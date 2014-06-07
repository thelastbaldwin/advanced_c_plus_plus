#include "Bitmap.h"
#include "BitmapIterator.h"

namespace BitmapGraphics
{
    
    Bitmap::Bitmap(int width, int height) :
    myWidth(width),
    myHeight(height){}
    
    int Bitmap::getWidth() const
    {
        return myWidth;
    }
    
    int Bitmap::getHeight() const
    {
        return myHeight;
    }
    
    int Bitmap::getNumberOfPadBytes() const
    {
        int remainder = (myWidth * 3) % 4;
        return (remainder == 0) ? 0 : (4 - remainder);
    }
    
    Bitmap::ScanLineIterator Bitmap::begin()
    {
        return myScanLines.begin();
    }
    
    Bitmap::ScanLineIterator Bitmap::end()
    {
        return myScanLines.end();
    }
    
    void Bitmap::addScanline(const ScanLine& scanLine)
    {
        myScanLines.push_back(scanLine);
    }
    
    void Bitmap::write(std::ostream& destinationStream) const
    {
        for (auto& scanLine : myScanLines)
        {
            // Write row of pixels
            for (auto& color : scanLine)
            {
                color.write(destinationStream);
            }
            
            // Write pad bytes
            for (int pad = 0; pad < getNumberOfPadBytes(); ++pad)
            {
                Binary::Byte(0).write(destinationStream);
            }
        }
    }
    
    HBitmapIterator Bitmap::createIterator()
    {
        return HBitmapIterator(new BitmapIterator(*this));
    }
    
}