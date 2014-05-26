#pragma once

//#include "IBitmapIterator.h"
#include <iostream>
#include <memory>
#include <string>

namespace BitmapGraphics
{
    
    class IBitmapEncoder;
    typedef std::shared_ptr<IBitmapEncoder> HBitmapEncoder;
    
    class IBitmapEncoder
    {
    public:
        virtual ~IBitmapEncoder() { }
        
        virtual HBitmapEncoder clone(std::istream& sourceStream) = 0;
        
        virtual void EncodeToStream() = 0;
        
        virtual std::string getMimeType() const = 0;
    };
    
}
