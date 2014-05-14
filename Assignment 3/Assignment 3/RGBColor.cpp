//
//  RGBColor.cpp
//  Assignment 3
//
//  Created by Steve Minor on 5/11/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "RGBColor.h"

namespace BitmapGraphics {
	RGBColor::RGBColor(const Binary::Byte& _red,
					   const Binary::Byte& _green,
					   const Binary::Byte& _blue):
	red(_red),
	green(_green),
	blue(_blue){}
	
	Binary::Byte RGBColor::getRed() const { return red; }
    Binary::Byte RGBColor::getGreen() const { return green; }
    Binary::Byte RGBColor::getBlue() const { return blue; }
    
    RGBColor RGBColor::read(std::istream& sourceStream)
    {
        Binary::Byte blue = Binary::Byte::read(sourceStream);
        Binary::Byte green = Binary::Byte::read(sourceStream);
        Binary::Byte red = Binary::Byte::read(sourceStream);

        return RGBColor(red, green, blue);
    }
    
    void RGBColor::write(std::ostream& destinationStream) const
    {
        blue.write(destinationStream);
        green.write(destinationStream);
        red.write(destinationStream);
    }
    
    bool RGBColor::operator==(const RGBColor& rhs) const
    {
        return (getRed() == rhs.getRed()) && (getGreen() == rhs.getGreen()) && (getBlue() == rhs.getBlue());
    }	
}

std::ostream& operator<<(std::ostream& os, const BitmapGraphics::RGBColor& rhs){
	rhs.write(os);
	return os;
}
