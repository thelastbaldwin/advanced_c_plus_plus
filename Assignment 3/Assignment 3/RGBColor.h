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
        explicit RGBColor(const Binary::Byte& _red = 0,
                 const Binary::Byte& _green = 0,
                 const Binary::Byte& _blue = 0);
		
		Binary::Byte getRed() const;
        Binary::Byte getGreen() const;
        Binary::Byte getBlue() const;
        
        static RGBColor read(std::istream& sourceStream);
        void write(std::ostream& destinationStream) const;
        
        bool operator==(const RGBColor& rhs) const;
	private:
		Binary::Byte red;
		Binary::Byte green;
		Binary::Byte blue;
	};
}

std::ostream& operator<<(std::ostream& os, const BitmapGraphics::RGBColor& rhs);

#endif /* defined(__Assignment_3__RGBColor__) */
