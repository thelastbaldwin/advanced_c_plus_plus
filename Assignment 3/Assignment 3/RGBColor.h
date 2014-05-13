//
//  RGBColor.h
//  Assignment 3
//
//  Created by Steve Minor on 5/11/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_3__RGBColor__
#define __Assignment_3__RGBColor__

#include <iostream>
#include "Byte.h"

namespace BitmapGraphics{
	class RGBColor{
	public:
        RGBColor(const Binary::Byte& blue,
                 const Binary::Byte& green,
                 const Binary::Byte& red);
	private:
		Binary::Byte red;
		Binary::Byte green;
		Binary::Byte blue;
	};
}

#endif /* defined(__Assignment_3__RGBColor__) */
