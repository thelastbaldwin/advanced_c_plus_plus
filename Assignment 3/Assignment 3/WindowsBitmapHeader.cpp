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
    Binary::DoubleWord WindowsBitmapHeader::rawImageByteOffset = 54;
    
    //info header
    Binary::DoubleWord WindowsBitmapHeader::infoHeaderBytes = 40;
    Binary::Word WindowsBitmapHeader::bitsPerPixel = 24;
    Binary::Word WindowsBitmapHeader::numberOfPlanes = 1;
    Binary::DoubleWord WindowsBitmapHeader::compressionType = 0;
	Binary::DoubleWord WindowsBitmapHeader::compressedImageSize = 0;
	Binary::DoubleWord WindowsBitmapHeader::horizontalPixelsPerMeter = 0; //getting weird values
	Binary::DoubleWord WindowsBitmapHeader::verticalPixelsPerMeter = 0;
    Binary::DoubleWord WindowsBitmapHeader::numberOfColors = 0;
    Binary::DoubleWord WindowsBitmapHeader::numberOfImportantColors = 0; //getting bad value!!
    
    WindowsBitmapHeader::WindowsBitmapHeader():fileSize(0), bitmapWidth(0), bitmapHeight(0){};
    
    WindowsBitmapHeader::WindowsBitmapHeader(std::istream& inputStream):fileSize(0), bitmapWidth(0), bitmapHeight(0){
        readFileHeader(inputStream);
        readInfoHeader(inputStream);
    };
	
	void WindowsBitmapHeader::write(std::ostream& destinationStream) const{
		writeFileHeader(destinationStream);
		writeInfoHeader(destinationStream);
	}
	
	void WindowsBitmapHeader::writeFileHeader(std::ostream& destinationStream) const{
		firstIdentifier.write(destinationStream);
		secondIdentifier.write(destinationStream);
		fileSize.writeLittleEndian(destinationStream);
		reserved.writeLittleEndian(destinationStream);
		rawImageByteOffset.writeLittleEndian(destinationStream);
	};
	
	void WindowsBitmapHeader::writeInfoHeader(std::ostream& destinationStream) const{
		infoHeaderBytes.writeLittleEndian(destinationStream);
		bitmapWidth.writeLittleEndian(destinationStream);
		bitmapHeight.writeLittleEndian(destinationStream);
		numberOfPlanes.writeLittleEndian(destinationStream);
		bitsPerPixel.writeLittleEndian(destinationStream);
		compressionType.writeLittleEndian(destinationStream);
		compressedImageSize.writeLittleEndian(destinationStream);
		horizontalPixelsPerMeter.writeLittleEndian(destinationStream);
		verticalPixelsPerMeter.writeLittleEndian(destinationStream);
		numberOfColors.writeLittleEndian(destinationStream);
		numberOfImportantColors.writeLittleEndian(destinationStream);		
	}
	
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
		
		//infoHeaderBytes
        verifyEquality(infoHeaderBytes, Binary::DoubleWord::readLittleEndian(inputStream), "infoHeaderBytes");
		
		//bitmapWidth
        bitmapWidth = Binary::DoubleWord::readLittleEndian(inputStream);
		
		//bitmapHeight
        bitmapHeight = Binary::DoubleWord::readLittleEndian(inputStream);
		
		//numberOfPlanes
        verifyEquality(numberOfPlanes, Binary::Word::readLittleEndian(inputStream), "numberOfPlanes");
		
		//bitsPerPixel
        verifyEquality(bitsPerPixel, Binary::Word::readLittleEndian(inputStream), "bitsPerPixel");
		
		//compressionType
        verifyEquality(compressionType, Binary::DoubleWord::readLittleEndian(inputStream), "compressionType");
		
		//compressedImageSize
		//this looks to consistently = fileSize - rawImageByteOffset
//		verifyEquality(compressedImageSize, Binary::DoubleWord::readLittleEndian(inputStream), "compressedImageSize");
		Binary::DoubleWord::readLittleEndian(inputStream); 
		
		//horizontalPixelsPerMeter
		//this is where the trouble starts, huge weird value
//		verifyEquality(horizontalPixelsPerMeter, Binary::DoubleWord::readLittleEndian(inputStream), "horizontalPixelsPerMeter"); 
		Binary::DoubleWord::readLittleEndian(inputStream);
		
		//verticalPixelsPerMeter
		verifyEquality(verticalPixelsPerMeter, Binary::DoubleWord::readLittleEndian(inputStream), "verticalPixelsPerMeter");
		
		//numberOfColors
		verifyEquality(numberOfColors, Binary::DoubleWord::readLittleEndian(inputStream), "numberOfColors");
		
		//numberOfImportantColors
		//always huge weird value
		verifyEquality(numberOfImportantColors, Binary::DoubleWord::readLittleEndian(inputStream), "numberOfImportantColors");
		//Binary::DoubleWord::readLittleEndian(inputStream);
    }
    
    int WindowsBitmapHeader::getBitmapHeight(){
        return static_cast<int>(bitmapHeight);
    }
    
    int WindowsBitmapHeader::getBitmapWidth(){
        return static_cast<int>(bitmapWidth);
    }
}
