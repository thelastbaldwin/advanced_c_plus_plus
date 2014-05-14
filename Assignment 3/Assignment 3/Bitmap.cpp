//
//  Bitmap.cpp
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "Bitmap.h"

namespace BitmapGraphics{
	Bitmap::Bitmap(int _width, int _height, std::istream& sourceStream):width(_width), height(_height){
		readScanLines(sourceStream);
	};
	
	const int Bitmap::getWidth() const{
		return width;
	}
	
	const int Bitmap::getHeight() const{
		return height;
	}
	
	Bitmap::ScanLineIterator Bitmap::begin(){
		return scanLines.begin();
	}
	
	Bitmap::ScanLineIterator Bitmap::end(){
		return scanLines.end();
	}
	
	void Bitmap::readScanLines(std::istream &sourceStream){
		for (int row = 0; row < height; ++row)
		{
			ScanLine scanLine;
			
			for (int column = 0; column < width; ++column)
			{
				scanLine.push_back(RGBColor::read(sourceStream));
			}
			
			scanLines.push_back(scanLine);
		}
	}
	
	void Bitmap::write(std::ostream& destinationStream) const{
		for(auto scanLineIter : scanLines){
			for(auto color: scanLineIter){
				color.write(destinationStream);
			}
		}
	}
}