#include "TestHarness.h"
#include "RGBColor.h"
#include <vector>
#include <sstream>

using namespace BitmapGraphics;

TEST(createColor, RGBColor)
{
    RGBColor color(0xAA, 0xBB, 0xCC);
    
    CHECK_EQUAL(0xAA, color.getRed());
    CHECK_EQUAL(0xBB, color.getGreen());
    CHECK_EQUAL(0xCC, color.getBlue());
}

TEST(readColor, RGBColor)
{
    unsigned char colorData[] = { 0x23, 0x24, 0x25, 0 };
    std::istringstream colorStream(reinterpret_cast<char*>(colorData));
    
    RGBColor color = RGBColor::read(colorStream);
    
    CHECK_EQUAL(0x23, color.getBlue());
    CHECK_EQUAL(0x24, color.getGreen());
    CHECK_EQUAL(0x25, color.getRed());
}

TEST(readScanLines, RGBColor)
{
    unsigned char colorData[] = {
        0xAA, 0xBB, 0xCC, 0x23, 0x24, 0x25,
        0x11, 0x22, 0x33, 0xDD, 0xEE, 0xFF,
        0
    };
    std::istringstream colorStream(reinterpret_cast<char*>(colorData));
    
    typedef std::vector<RGBColor> ScanLine;
    typedef std::vector<ScanLine> ScanLineContainer;
    
    const int Width = 2;
    const int Height = 2;
    
    ScanLineContainer scanLines;
    
    for (int row = 0; row < Height; ++row)
    {
        ScanLine scanLine;
        
        for (int column = 0; column < Width; ++column)
        {
            scanLine.push_back(RGBColor::read(colorStream));
        }
        
        scanLines.push_back(scanLine);
    }
    
    RGBColor expected(0x33, 0x22, 0x11);
    RGBColor actual = scanLines[1][0];
	CHECK_EQUAL(expected, actual);
}