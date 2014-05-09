//
//  Byte.h
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#pragma once

#include <iostream>

namespace Binary{
	class Byte{
	public:
		Byte(const unsigned char& _ch = 0);
		operator unsigned char() const;
		static Byte read(std::istream& is);
		void write(std::ostream& os);
	private:
		unsigned char ch;
	};
}
