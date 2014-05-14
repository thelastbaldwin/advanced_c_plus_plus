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
    //file header
	Binary::Byte WindowsBitmapHeader::firstIdentifier = 'B';
	Binary::Byte WindowsBitmapHeader::secondIdentifier = 'M';
	Binary::DoubleWord WindowsBitmapHeader::reserved = 0;
    Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset = 54; //14 + 40
    
    //info header
    Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes = 40;
    Binary::Word WindowsBitmapHeader::bitsPerPixel = 24;
    Binary::Word WindowsBitmapHeader::numberOfPlanes = 1;
    Binary::DoubleWord WindowsBitmapHeader::compressionType = 0;
	Binary::DoubleWord WindowsBitmapHeader::compressedImageSize = 0;
	Binary::DoubleWord WindowsBitmapHeader::horizontalPixelsPerMeter = 0;
	Binary::DoubleWord WindowsBitmapHeader::verticalPixelsPerMeter = 0;
    Binary::DoubleWord WindowsBitmapHeader::numberOfColors = 0;
    Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors = 0; //getting bad value!!
    
    WindowsBitmapHeader::WindowsBitmapHeader(){};
    
    WindowsBitmapHeader::WindowsBitmapHeader(std::istream& inputStream){
        readFileHeader(inputStream);
        readInfoHeader(inputStream);
    };
    
    int WindowsBitmapHeader::getFileSize(){
        return static_cast<int>(fileSize);
    };
    void WindowsBitmapHeader::readFileHeader(std::istream& inputStream){
		//14 bytes
        verifyEquality(firstIdentifier, Binary::Byte::read(inputStream), "firstIdentifier");
        verifyEquality(secondIdentifier, Binary::Byte::read(inputStream), "secondIdentifier");
        fileSize = Binary::DoubleWord::readLittleEndian(inputStream);
        verifyEquality(reserved, Binary::DoubleWord::readLittleEndian(inputStream), "reserved");
        verifyEquality(rawImageByteOffset, Binary::DoubleWord::readLittleEndian(inputStream), "rawImageByteOffset");
    }
    
    void WindowsBitmapHeader::readInfoHeader(std::istream &inputStream){
		//40 bytes
        verifyEquality(infoHeaderBytes, Binary::DoubleWord::readLittleEndian(inputStream), "infoHeaderBytes");
        bitmapWidth = Binary::DoubleWord::readLittleEndian(inputStream);
        bitmapHeight = Binary::DoubleWord::readLittleEndian(inputStream);
        verifyEquality(numberOfPlanes, Binary::Word::readLittleEndian(inputStream), "numberOfPlanes");
        verifyEquality(bitsPerPixel, Binary::Word::readLittleEndian(inputStream), "bitsPerPixel");
        verifyEquality(compressionType, Binary::DoubleWord::readLittleEndian(inputStream), "compressionType");
		Binary::DoubleWord::readLittleEndian(inputStream); //"compressedImageSize"
		Binary::DoubleWord::readLittleEndian(inputStream); //horizontalPixelsPerMeter
		Binary::DoubleWord::readLittleEndian(inputStream); //verticalPixelsPerMeter
		Binary::DoubleWord::readLittleEndian(inputStream); //numberOfColors
		Binary::DoubleWord::readLittleEndian(inputStream); //numberOfImportantColors
    }
    
    int WindowsBitmapHeader::getBitmapHeight(){
        return static_cast<int>(bitmapHeight);
    }
    
    int WindowsBitmapHeader::getBitmapWidth(){
        return static_cast<int>(bitmapWidth);
    }
}
