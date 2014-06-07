#pragma once

#include <iostream>

namespace Binary
{
    class Byte
    {
    public:
        Byte(unsigned char value = 0) : myValue(value) { }
        operator unsigned char() const { return myValue; }

        void write(std::ostream& destinationStream) const
        {
            destinationStream.put(myValue);
        }
        
        static Byte read(std::istream& sourceStream)
        {
            return sourceStream.get();
        }
		
		int toInt(){
			return int(myValue);
		}

    private:
        unsigned char myValue;
    };
}
