//
//  BasicCanvasBitmapIterator.cpp
//  Assignment 5
//
//  Created by Steve Minor on 6/6/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "BasicCanvasBitmapIterator.h"

namespace Framework{
	BasicCanvasBitmapIterator::BasicCanvasBitmapIterator(const BasicCanvas& _canvas):
	canvas(_canvas),
	width(_canvas.getWidth()),
	height(_canvas.getHeight()),
	xIndex(0),
	yIndex(0),
	canvasIter(canvas.getPixelMap().cbegin()){}
	
	void BasicCanvasBitmapIterator::nextScanLine(){
		if(!isEndOfImage()){
			++yIndex;
			xIndex = 0;
		}		
	}
	
	bool BasicCanvasBitmapIterator::isEndOfImage() const{
		return canvasIter == canvas.getPixelMap().cend();
	}
	
	void BasicCanvasBitmapIterator::nextPixel(){
		if(!isEndOfImage()){
			++canvasIter;
			++xIndex;
		}		
	}
	
	bool BasicCanvasBitmapIterator::isEndOfScanLine() const{
		return xIndex == getBitmapWidth();
	}
	
	BitmapGraphics::Color BasicCanvasBitmapIterator::getColor() const{
		if(isEndOfImage()){
			std::cout << xIndex << ", " << yIndex << std::endl;
			throw std::runtime_error("bad iterator");
		}
		return canvasIter->second;
	}
	
	int BasicCanvasBitmapIterator::getBitmapWidth() const{
		return width;
	}
	
	int BasicCanvasBitmapIterator::getBitmapHeight() const{
		return height;
	}
}