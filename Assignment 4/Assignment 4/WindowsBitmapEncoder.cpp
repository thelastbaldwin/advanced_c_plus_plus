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
	
	WindowsBitmapEncoder::WindowsBitmapEncoder(HBitmapIterator& bitmapIterator){
	
	};
	
	HBitmapEncoder WindowsBitmapEncoder::clone(HBitmapIterator& bitmapIter){
		WindowsBitmapEncoder encoder(bitmapIter);
	};
	
	void WindowsBitmapEncoder::encodeToStream(std::ostream& sourceStream){
		//WindowsBitmapHeader.write(mySourceStream)
		//WindowsBitmap.write(mySourceStream)
		//Do this last part with bitmap iterators? Do the whole thing with them?
	};
	
	std::string WindowsBitmapEncoder::getMimeType() const
    {
        return WindowsBitmapMimeType;
    }	
}
