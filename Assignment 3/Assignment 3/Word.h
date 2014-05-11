//
//  Word.h
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
	class Word{
	public:
        Word(uint16_t _wrd = 0);
	    operator uint16_t() const;
        
		static Word readBigEndian(std::istream& is);
		static Word readLittleEndian(std::istream& is);
		
		void writeLittleEndian(std::ostream& os);
    private:
        uint16_t wrd;
		union uint16_carray {
			uint16_t intVal;
			unsigned char carray[2];
		};
        static Word readNativeOrder(std::istream& is);
        static Word readSwappedOrder(std::istream& is);
	};
}
