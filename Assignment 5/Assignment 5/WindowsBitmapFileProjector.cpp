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
		BitmapGraphics::HBitmapIterator canvasIter = canvas.createBitmapIterator();
		BitmapGraphics::HBitmapEncoder encoder = codecLibrary.createEncoder(BitmapGraphics::WindowsBitmapMimeType, canvasIter);
		
		//create a new empty file for writing to
		std::ofstream bitmapFile(PROJECT_PATH + filename, std::ios::binary);
		encoder->encodeToStream(bitmapFile);
		bitmapFile.close();
	}
}