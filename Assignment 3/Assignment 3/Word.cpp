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
}