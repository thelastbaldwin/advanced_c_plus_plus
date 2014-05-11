//
//  WindowsBitmapHeader.cpp
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "WindowsBitmapHeader.h"

namespace BitmapGraphics{
	Binary::Byte WindowsBitmapHeader::firstIdentifier = 'B';
	Binary::Byte WindowsBitmapHeader::secondIdentifier = 'M';
	Binary::DoubleWord WindowsBitmapHeader::reserved = '0';
	Binary::Word WindowsBitmapHeader::bitsPerPixel = 24;
}
