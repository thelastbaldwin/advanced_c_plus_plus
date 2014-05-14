//
//  Bitmap.h
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#pragma once

#include "RGBColor.h"
#include <iosfwd>
#include <vector>

namespace BitmapGraphics{
	class Bitmap{
	public:
		typedef std::vector<RGBColor> ScanLine;
		typedef std::vector<ScanLine> ScanLineCollection;
		typedef ScanLineCollection::iterator ScanLineIterator;
		
		Bitmap (int _width, int _height, std::istream& sourceStream);
		
		const int getWidth() const;
		const int getHeight() const;
		
		ScanLineIterator begin();
		ScanLineIterator end();
	
		void readScanLines(std::istream& sourceStream);
		void write(std::ostream& destinationStream) const;
	private:
		int width;
		int height;
				ScanLineCollection scanLines;
	};
}
