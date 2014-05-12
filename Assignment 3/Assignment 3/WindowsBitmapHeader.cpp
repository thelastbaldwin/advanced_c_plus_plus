//
//  WindowsBitmapHeader.cpp
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "WindowsBitmapHeader.h"

namespace BitmapGraphics{
    //static constants
	Binary::Byte WindowsBitmapHeader::firstIdentifier = 'B';
	Binary::Byte WindowsBitmapHeader::secondIdentifier = 'M';
	Binary::DoubleWord WindowsBitmapHeader::reserved = 0;
    Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset = 54; //14 + 40
    
    Binary::Word WindowsBitmapHeader::bitsPerPixel = 24;
    
    void WindowsBitmapHeader::readFileHeader(std::istream& inputStream){
        //firstIdentifier
        //secondIdentifier
        //fileSize
        //reserved
        //rawImageByteOffest
        verifyEquality(firstIdentifier, Binary::Byte::read(inputStream), "firstIdentifier");
        verifyEquality(secondIdentifier, Binary::Byte::read(inputStream), "secondIdentifier");
        fileSize = Binary::DoubleWord::readLittleEndian(inputStream);
        verifyEquality(reserved, Binary::DoubleWord::readLittleEndian(inputStream), "reserved");
        verifyEquality(rawImageByteOffset, Binary::DoubleWord::readLittleEndian(inputStream), "rawImageByteOffset");
    }
    
    void WindowsBitmapHeader::readInfoHeader(std::istream &inputStream){
        //infoHeaderBytes DW = 40
        //bitmapWidth DW
        //bitmapHeight DW
        //numberOfPlanes W = 1
        //bitsPerPixel W = 24
        //compressionType DW
        //compressedImageSize DW
        //horizontalPixelsPerMeter DW = N/A?
        //verticalPizelsPerMter DW = N/A?
        //numberOfColors DW = 0
        //numberofImportantColors DW = 0
    }
}
