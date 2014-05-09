//
//  DoubleWord.cpp
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "DoubleWord.h"

namespace Binary{
	DoubleWord::DoubleWord(uint32_t _wrd):wrd(_wrd){};
	DoubleWord::operator uint32_t(){
		return wrd;
	}
	    
    DoubleWord DoubleWord::readBigEndian(std::istream &is){
        return readSwappedOrder(is);
    }
    
    DoubleWord DoubleWord::readLittleEndian(std::istream &is){
        return readNativeOrder(is);
    }
    
    DoubleWord DoubleWord::readNativeOrder(std::istream& is){
        DoubleWord doubleword;
        Byte *bytes = reinterpret_cast<Byte*>(&doubleword);
        
        bytes[0] = Byte::read(is);
        bytes[1] = Byte::read(is);
        bytes[2] = Byte::read(is);
        bytes[3] = Byte::read(is);
        
        return doubleword;
    }
    
    DoubleWord DoubleWord::readSwappedOrder(std::istream& is){
        DoubleWord doubleword;
        Byte *bytes = reinterpret_cast<Byte*>(&doubleword);
        
        bytes[3] = Byte::read(is);
        bytes[2] = Byte::read(is);
        bytes[1] = Byte::read(is);
        bytes[0] = Byte::read(is);
        
        return doubleword;
    }
}