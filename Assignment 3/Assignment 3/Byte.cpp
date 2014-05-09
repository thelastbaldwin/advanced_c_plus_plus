//
//  Byte.cpp
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "Byte.h"

namespace Binary{
	Byte::Byte(const unsigned char& _ch):ch(_ch){};
	
	Byte::operator unsigned char() const
	{
		return ch;
	}
	
	Byte Byte::read(std::istream &is){
		unsigned char ch;
		is >> ch;
		return Byte(ch);
	}
	
	void Byte::write(std::ostream& os){
		os << ch;
	}

}
