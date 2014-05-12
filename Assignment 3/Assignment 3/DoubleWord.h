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
        
        bool operator==(const DoubleWord& other)const;
        bool operator!=(const DoubleWord& other)const;
		
		static DoubleWord read(std::istream& is);
		static DoubleWord readBigEndian(std::istream& is);
		static DoubleWord readLittleEndian(std::istream& is);
		
		void write(std::ostream& os) const;
		void writeLittleEndian(std::ostream& os) const;
		void writeBigEndian(std::ostream& os) const;
        
        friend std::ostream& operator<<(std::ostream& os, const Binary::DoubleWord& dw);
        
	private:
		uint32_t wrd;
		union uint32_carray {
			uint32_t intVal;
			unsigned char carray[4];
		};
		
		void writeNativeOrder(std::ostream& os, const union uint32_carray& convert) const;
		void writeSwappedOrder(std::ostream& os, const union uint32_carray& convert) const;
		
		static DoubleWord readNativeOrder(std::istream& is);
        static DoubleWord readSwappedOrder(std::istream& is);
	};
}



