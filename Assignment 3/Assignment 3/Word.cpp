//
//  Word.cpp
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "Word.h"

namespace Binary{
	Word::Word(uint16_t _wrd):wrd(_wrd){};
	
	Word::operator uint16_t() const{
		return wrd;
	}
    
    Word Word::readBigEndian(std::istream &is){
        return readSwappedOrder(is);
    }
    
    Word Word::readLittleEndian(std::istream &is){
        return readNativeOrder(is);
    }
	
	void Word::writeLittleEndian(std::ostream &os){
		union uint16_carray convert;
		convert.intVal = wrd;

		os	<<	convert.carray[0]
		<<	convert.carray[1];
	}
    
    Word Word::readNativeOrder(std::istream& sourceStream){        
        Word word;
        Byte *bytes = reinterpret_cast<Byte*>(&word);

        bytes[0] = Byte::read(sourceStream);
        bytes[1] = Byte::read(sourceStream);
        
        return word;
    }    
    
    Word Word::readSwappedOrder(std::istream& sourceStream){
        Word word;
        Byte *bytes = reinterpret_cast<Byte*>(&word);
        
        bytes[1] = Byte::read(sourceStream);
        bytes[0] = Byte::read(sourceStream);
        
        return word;        
    }
}