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
	
	DoubleWord DoubleWord::read(std::istream &is){
		#ifdef Little_Endian
			return readNativeOrder(is);
		#endif
			return readSwappedOrder(is);
    }
	   
    DoubleWord DoubleWord::readBigEndian(std::istream &is){
        return readSwappedOrder(is);
    }
    
    DoubleWord DoubleWord::readLittleEndian(std::istream &is){
        return readNativeOrder(is);
    }
	
	void DoubleWord::writeNativeOrder(std::ostream& os, const union uint32_carray& convert) const{
		//little Endian
		os	<<	convert.carray[0]
			<<	convert.carray[1]
			<<	convert.carray[2]
			<<	convert.carray[3];
	}
	
	void DoubleWord::writeSwappedOrder(std::ostream& os, const union uint32_carray& convert) const{
		//big Endian
		os	<<	convert.carray[3]
			<<	convert.carray[2]
			<<	convert.carray[1]
			<<	convert.carray[0];
	}
	
	void DoubleWord::write(std::ostream& os) const{
		union uint32_carray convert;
		convert.intVal = wrd;
		#ifdef Little_Endian
			writeNativeOrder(os, convert);
		#else
			writeSwappedOrder(os, convert);
		#endif
	}
	
	void DoubleWord::writeLittleEndian(std::ostream &os) const{
		union uint32_carray convert;
		convert.intVal = wrd;
		writeNativeOrder(os, convert);
	}
	
	void DoubleWord::writeBigEndian(std::ostream &os) const{
		union uint32_carray convert;
		convert.intVal = wrd;
		writeSwappedOrder(os, convert);
	}
    
    DoubleWord DoubleWord::readNativeOrder(std::istream& is){
		//little endian
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