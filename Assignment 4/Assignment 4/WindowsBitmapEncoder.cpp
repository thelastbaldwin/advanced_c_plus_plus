//
//  WindowsBitmapEncoder.cpp
//  Assignment 4
//
//  Created by Steve Minor on 5/25/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics {
	WindowsBitmapEncoder::WindowsBitmapEncoder(){
	
	}
	
	WindowsBitmapEncoder::WindowsBitmapEncoder(HBitmapIterator& bitmapIterator):
	myIterator(bitmapIterator){
	
	};
	
	HBitmapEncoder WindowsBitmapEncoder::clone(HBitmapIterator& bitmapIter){
		return HBitmapEncoder(new WindowsBitmapEncoder(bitmapIter));
	};
	
	void WindowsBitmapEncoder::encodeToStream(std::ostream& destinationStream){
		
		if (myIterator == NULL)
		{
			throw std::runtime_error("Invalid use of prototype encoder");
		}
		
		WindowsBitmapHeader header(myIterator->getBitmapWidth(), myIterator->getBitmapHeight());
		header.write(destinationStream);
		
		while (!myIterator->isEndOfImage())
		{
			while (!myIterator->isEndOfScanLine())
			{
				Color color = myIterator->getColor();
				color.write(destinationStream);
				myIterator->nextPixel();
			}
			//add padding if necessary
			for (int pad = 0; pad < getNumberOfPadBytes(myIterator->getBitmapWidth()); ++pad)
			{
				destinationStream.put(0x00);
			}
			
			myIterator->nextScanLine();
		}
	};
	
	std::string WindowsBitmapEncoder::getMimeType() const
    {
        return WindowsBitmapMimeType;
    }	
}
