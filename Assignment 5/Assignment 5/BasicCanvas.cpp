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
		auto success = myPixels.insert(std::pair<VG::Point, BitmapGraphics::Color>(location, color));
		if(!success.second){
			std::cout << "unable to save " << location.getX() << ", " <<location.getY() << std::endl;
		}
	}
	
	BitmapGraphics::Color BasicCanvas::getPixelColor (const VG::Point& location) const{
		auto foundPoint = myPixels.find(location);
		if (foundPoint != myPixels.end())
		{
			return foundPoint->second;
		}
		//if point is not found
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
	
	const std::map<VG::Point, BitmapGraphics::Color>& BasicCanvas::getPixelMap() const{
		return myPixels;
	}
}