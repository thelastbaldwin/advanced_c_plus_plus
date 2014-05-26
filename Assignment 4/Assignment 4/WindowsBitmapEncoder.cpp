//
//  WindowsBitmapEncoder.cpp
//  Assignment 4
//
//  Created by Steve Minor on 5/25/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "WindowsBitmapEncoder.h"

namespace BitmapGraphics {
	HBitmapEncoder WindowsBitmapEncoder::clone(std::istream& sourceStream){
	
	};
	
	void WindowsBitmapEncoder::encodeToStream(){
		//WindowsBitmapHeader.write(stream)
		//WindowsBitmap.write(stream)
		//Do this last part with bitmap iterators? Do the whole thing with them?
	};
	
	std::string WindowsBitmapEncoder::getMimeType() const
    {
        return WindowsBitmapMimeType;
    }	
}
