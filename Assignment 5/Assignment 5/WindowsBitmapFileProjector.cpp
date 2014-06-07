//
//  WindowsBitmapFileProjector.cpp
//  Assignment 5
//
//  Created by Steve Minor on 6/7/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "WindowsBitmapFileProjector.h"

namespace Framework{
	WindowsBitmapFileProjector::WindowsBitmapFileProjector(std::string _filename, BitmapGraphics::CodecLibrary& _codecLibrary):
	filename(_filename),
	codecLibrary(_codecLibrary){};
	
	void WindowsBitmapFileProjector::projectCanvas(const Framework::ICanvas &canvas) {
		//create an encoder from the codecLibrary
		auto canvasIter = canvas.createBitmapIterator();
		codecLibrary.createEncoder(BitmapGraphics::WindowsBitmapMimeType, canvasIter);
	}
}