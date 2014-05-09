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
		
	}
	
	DoubleWord DoubleWord::readLittleEndian(std::istream &is){
		
	}
}