//
//  BasicCanvasBitmapIterator.cpp
//  Assignment 5
//
//  Created by Steve Minor on 6/6/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "BasicCanvasBitmapIterator.h"

namespace Framework{
	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(BasicCanvas& _canvas):
	canvas(_canvas),
	width(_canvas.getWidth()),
	height(_canvas.getHeight()),
	xIndex(0),
	yIndex(0){}
	
	void BasicCanvasBitmapIterator::nextScanLine(){
		++yIndex;
	}
	
	bool BasicCanvasBitmapIterator::isEndOfImage() const{
		return yIndex >= height && xIndex > width;
	}
	
	void BasicCanvasBitmapIterator::nextPixel(){
		//if not at end of scanline, just go to the next
		if (!isEndOfScanLine()) {
			++xIndex;
		//if at the end of scanline, go to the next row
		//if not at last row
		}else{
			if(yIndex != height){
				xIndex = 0;
				++yIndex;
			}			
		}
	}
	
	bool BasicCanvasBitmapIterator::isEndOfScanLine() const{
		return xIndex == width;
	}
	
	BitmapGraphics::Color BasicCanvasBitmapIterator::getColor() const{
		return canvas.getPixelColor(VG::Point(xIndex, yIndex));
	}
	
	int BasicCanvasBitmapIterator::getBitmapWidth() const{
		return width;
	}
	
	int BasicCanvasBitmapIterator::getBitmapHeight() const{
		return height;
	}
}