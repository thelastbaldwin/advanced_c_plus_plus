//
//  WindowsBitmapHeader.h
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#pragma once

#include <iostream>

namespace BitmapGraphics{
	class WindowsBitmapHeader{
	public:
		int getFileSize();
		void readInfoHeader(std::istream& inputStream);
		void readFileHeader(std::istream& inputStream);
		int getBitmapHeight();
		int getBitmapWidth();
	
	};
}
