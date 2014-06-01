#pragma once

#include <iosfwd>
#include <cstdint>

namespace Binary
{
    class DoubleWord
    {
    public:
        DoubleWord(uint32_t value = 0);
        operator uint32_t() const;

        void writeLittleEndian(std::ostream& destinationStream) const;
        void writeBigEndian(std::ostream& destinationStream) const;

        static DoubleWord readLittleEndian(std::istream& sourceStream);
        static DoubleWord readBigEndian(std::istream& sourceStream);

    private:
        uint32_t myValue;

        void writeNativeOrder(std::ostream& destinationStream) const;
        void writeSwappedOrder(std::ostream& destinationStream) const;

        static DoubleWord readNativeOrder(std::istream& sourceStream);
        static DoubleWord readSwappedOrder(std::istream& sourceStream);
    };
}
