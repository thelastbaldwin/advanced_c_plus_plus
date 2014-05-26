#include "DoubleWord.h"
#include <iostream>

namespace Binary
{
    union DoubleWordValue
    {
        uint32_t dword;
        unsigned char bytes[4];
    };

    DoubleWord::DoubleWord(uint32_t value)
    {
        myValue = value;
    }

    DoubleWord::operator uint32_t() const
    {
        return myValue;
    }

    void DoubleWord::writeLittleEndian(std::ostream& destinationStream) const
    {
#ifdef Little_Endian_
        writeNativeOrder(destinationStream);
#else
        writeSwappedOrder(destinationStream);
#endif
    }

    void DoubleWord::writeBigEndian(std::ostream& destinationStream) const
    {
#ifdef Little_Endian_
        writeSwappedOrder(destinationStream);
#else
        writeNativeOrder(destinationStream);
#endif
    }

    DoubleWord DoubleWord::readBigEndian(std::istream& sourceStream)
    {
#ifdef Little_Endian_
        return readSwappedOrder(sourceStream);
#else
        return readNativeOrder(sourceStream);
#endif
    }

    DoubleWord DoubleWord::readLittleEndian(std::istream& sourceStream)
    {
#ifdef Little_Endian_
        return readNativeOrder(sourceStream);
#else
        return readSwappedOrder(sourceStream);
#endif
    }

    DoubleWord DoubleWord::readNativeOrder(std::istream& sourceStream)
    {
        DoubleWordValue value;
        
        value.bytes[0] = sourceStream.get();
        value.bytes[1] = sourceStream.get();
        value.bytes[2] = sourceStream.get();
        value.bytes[3] = sourceStream.get();

        return value.dword;
    }

    DoubleWord DoubleWord::readSwappedOrder(std::istream& sourceStream)
    {
        DoubleWordValue value;
        
        value.bytes[3] = sourceStream.get();
        value.bytes[2] = sourceStream.get();
        value.bytes[1] = sourceStream.get();
        value.bytes[0] = sourceStream.get();
        
        return value.dword;
    }

    void DoubleWord::writeNativeOrder(std::ostream& destinationStream) const
    {
        DoubleWordValue value;
		value.dword = myValue;
        
        destinationStream.put(value.bytes[0]);
        destinationStream.put(value.bytes[1]);
        destinationStream.put(value.bytes[2]);
        destinationStream.put(value.bytes[3]);
    }

    void DoubleWord::writeSwappedOrder(std::ostream& destinationStream) const
    {
        DoubleWordValue value;
		value.dword = myValue;
        
        destinationStream.put(value.bytes[3]);
        destinationStream.put(value.bytes[2]);
        destinationStream.put(value.bytes[1]);
        destinationStream.put(value.bytes[0]);
    }
}
