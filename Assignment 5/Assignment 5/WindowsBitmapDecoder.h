#pragma once

#include "IBitmapDecoder.h"
#include "Bitmap.h"

namespace BitmapGraphics
{
    
    class WindowsBitmapDecoder : public IBitmapDecoder
    {
    public:
        WindowsBitmapDecoder();
        
        
        virtual HBitmapDecoder clone(std::istream& sourceStream);
        
        virtual HBitmapIterator createIterator();
        
        virtual std::string getMimeType() const;
        
        virtual bool isSupported(const std::string& firstChunk) const;
        
    private:
        std::istream& mySourceStream;
        HBitmap myBitmap;
        
        WindowsBitmapDecoder(std::istream& sourceStream);
    };
    
}