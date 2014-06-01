#pragma once

#include "IBitmapIterator.h"

namespace BitmapGraphics
{	
    class BrightnessDecorator : public IBitmapIterator
    {
    public:
        BrightnessDecorator(const HBitmapIterator& originalIterator, int _brightnessAmount) :
        myOriginalIterator(originalIterator), myBrightnessAmount(_brightnessAmount){}
        
        virtual void nextScanLine() { myOriginalIterator->nextScanLine(); }
        virtual bool isEndOfImage() const { return myOriginalIterator->isEndOfImage(); }
        virtual void nextPixel() { myOriginalIterator->nextPixel(); }
        virtual bool isEndOfScanLine() const { return myOriginalIterator->isEndOfScanLine(); }
        
        virtual int getBitmapWidth() const { return myOriginalIterator->getBitmapWidth(); }
        virtual int getBitmapHeight() const { return myOriginalIterator->getBitmapHeight(); }
		
        virtual Color getColor() const
        {
			Color originalColor = myOriginalIterator->getColor();
            
			typedef ranged_number<int, 0, 255> rangedColor;
			
			rangedColor red = originalColor.getRed() + myBrightnessAmount;
			rangedColor green = originalColor.getGreen() + myBrightnessAmount;
			rangedColor blue = originalColor.getBlue() + myBrightnessAmount;
			
			//has to be a cleaner way to do this...
			Binary::Byte brightRed = red;
			Binary::Byte brightGreen = green;
			Binary::Byte brightBlue = blue;
			
            return Color(brightRed, brightGreen, brightBlue);
        }
		
    private:
        HBitmapIterator myOriginalIterator;
		int myBrightnessAmount;
    };
}
