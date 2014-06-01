#pragma once

#include "Color.h"
#include "IBitmapIterator.h"
#include <list>

namespace BitmapGraphics
{
    
    class Bitmap
    {
    public:
        typedef std::list<Color> ScanLine;
        typedef ScanLine::iterator ColorIterator;
        
    private:
        typedef std::list<ScanLine> ScanLineCollection;
        
    public:
        typedef ScanLineCollection::iterator ScanLineIterator;
        
        Bitmap(int width, int height);
        
        ScanLineIterator begin();
        ScanLineIterator end();
        
        int getWidth() const;
        int getHeight() const;
        
        // This can be removed after the read and write methods are gone
        int getNumberOfPadBytes() const;
        
        // This should move to the encoder
        void write(std::ostream& destinationStream) const;
        
        void addScanline(const ScanLine& scanLine);
        
        HBitmapIterator createIterator();
        
    private:
        int myWidth;
        int myHeight;
        
        ScanLineCollection myScanLines;
    };
    
    typedef std::shared_ptr<Bitmap> HBitmap;
    
}