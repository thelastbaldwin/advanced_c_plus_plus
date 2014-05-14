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
	
	DoubleWord::operator uint32_t() const{
		return wrd;
	}
	   
    DoubleWord DoubleWord::readBigEndian(std::istream &is){
        return readSwappedOrder(is);
    }
    
    DoubleWord DoubleWord::readLittleEndian(std::istream &is){
        return readNativeOrder(is);
    }
	
	void DoubleWord::writeNativeOrder(std::ostream& os) const{
		//little Endian
		union uint32_carray convert;
		convert.intVal = wrd;
		
		os	<<	convert.carray[0]
			<<	convert.carray[1]
			<<	convert.carray[2]
			<<	convert.carray[3];
	}
	
	void DoubleWord::writeSwappedOrder(std::ostream& os) const{
		//big Endian
		union uint32_carray convert;
		convert.intVal = wrd;
		
		os	<<	convert.carray[3]
			<<	convert.carray[2]
			<<	convert.carray[1]
			<<	convert.carray[0];
	}
	
	void DoubleWord::writeLittleEndian(std::ostream &os) const{
		writeNativeOrder(os);
	}
	
	void DoubleWord::writeBigEndian(std::ostream &os) const{
		writeSwappedOrder(os);
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
		//big endian
        DoubleWord doubleword;
        Byte *bytes = reinterpret_cast<Byte*>(&doubleword);
        
        bytes[3] = Byte::read(is);
        bytes[2] = Byte::read(is);
        bytes[1] = Byte::read(is);
        bytes[0] = Byte::read(is);
        
        return doubleword;
    }
}