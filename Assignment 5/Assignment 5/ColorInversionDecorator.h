#pragma once

#include "IBitmapIterator.h"

namespace BitmapGraphics
{
    class ColorInversionDecorator : public IBitmapIterator
    {
    public:
        ColorInversionDecorator(const HBitmapIterator& originalIterator) :
        myOriginalIterator(originalIterator){}
        
        virtual void nextScanLine() { myOriginalIterator->nextScanLine(); }
        virtual bool isEndOfImage() const { return myOriginalIterator->isEndOfImage(); }
        virtual void nextPixel() { myOriginalIterator->nextPixel(); }
        virtual bool isEndOfScanLine() const { return myOriginalIterator->isEndOfScanLine(); }
        
        virtual int getBitmapWidth() const { return myOriginalIterator->getBitmapWidth(); }
        virtual int getBitmapHeight() const { return myOriginalIterator->getBitmapHeight(); }
		
        virtual Color getColor() const
        {
			Color originalColor = myOriginalIterator->getColor();
			
            return Color(255 - originalColor.getRed(),
						 255 - originalColor.getGreen(),
						 255 - originalColor.getBlue());
        }
		
    private:
        HBitmapIterator myOriginalIterator;
    };
}

