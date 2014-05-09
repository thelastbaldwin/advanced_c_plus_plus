//
//  DoubleWord.h
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#pragma once

#include <cstdint>
#include <iosfwd>
#include "Byte.h"

namespace Binary{
	class DoubleWord{
	public:
		DoubleWord(uint32_t _wrd = 0);
		operator uint32_t();
		static DoubleWord readBigEndian(std::istream& is);
		static DoubleWord readLittleEndian(std::istream& is);
	private:
		uint32_t wrd;
        static DoubleWord readNativeOrder(std::istream& is);
        static DoubleWord readSwappedOrder(std::istream& is);
	};
}



