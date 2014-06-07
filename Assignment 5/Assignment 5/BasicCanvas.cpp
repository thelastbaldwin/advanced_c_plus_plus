//
//  BasicCanvas.cpp
//  Assignment 5
//
//  Created by Steve Minor on 6/3/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "BasicCanvas.h"
#include "BasicCanvasBitmapIterator.h"

namespace Framework{
	BasicCanvas::BasicCanvas(const int& _width, const int& _height):
		width(_width),
		height(_height){};
	
	void BasicCanvas::setPixelColor (const VG::Point& location, const BitmapGraphics::Color& color){
		myPixels.insert(std::pair<VG::Point, BitmapGraphics::Color>(location, color));
	}
	
	BitmapGraphics::Color BasicCanvas::getPixelColor (const VG::Point& location) const{
		auto foundPoint = myPixels.find(location);
		if (foundPoint != myPixels.end())
		{
			return foundPoint->second;
		}
		//should never reach this condition, the scene will fill this with a background color of black
		return BitmapGraphics::Color();
	};
	
	int BasicCanvas::getWidth () const{
		return height;
	}
	int BasicCanvas::getHeight () const{
		return width;
	}
	
	BitmapGraphics::HBitmapIterator BasicCanvas::createBitmapIterator() const{
		return BitmapGraphics::HBitmapIterator(new BasicCanvasBitmapIterator(*this));
	}
}