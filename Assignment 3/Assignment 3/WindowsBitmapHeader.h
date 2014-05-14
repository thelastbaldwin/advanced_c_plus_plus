//
//  WindowsBitmapHeader.h
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#pragma once

#include "Word.h"
#include "DoubleWord.h"
#include "VerifyEquality.h"

namespace BitmapGraphics{
	class WindowsBitmapHeader{
	public:
        WindowsBitmapHeader();
        WindowsBitmapHeader(std::istream& inputStream);
		int getFileSize();
		void readInfoHeader(std::istream& inputStream);
		void readFileHeader(std::istream& inputStream);
		int getBitmapHeight();
		int getBitmapWidth();
        
		void write(std::ostream& destinationStream) const;
        void writeFileHeader(std::ostream& destinationStream) const;
		void writeInfoHeader(std::ostream& destinationStream) const;
    private:
        // file header
        static Binary::Byte firstIdentifier;
        static Binary::Byte secondIdentifier;
        Binary::DoubleWord fileSize;
        static Binary::DoubleWord reserved;
        static Binary::DoubleWord rawImageByteOffset;
        
        // info header
        static Binary::DoubleWord infoHeaderBytes;
        Binary::DoubleWord bitmapWidth;
        Binary::DoubleWord bitmapHeight;
        static Binary::Word numberOfPlanes;
        static Binary::Word bitsPerPixel;
        static Binary::DoubleWord compressionType;
		static Binary::DoubleWord compressedImageSize;
        static Binary::DoubleWord horizontalPixelsPerMeter;
        static Binary::DoubleWord verticalPixelsPerMeter;
        static Binary::DoubleWord numberOfColors;
        static Binary::DoubleWord numberOfImportantColors;
	};
}
