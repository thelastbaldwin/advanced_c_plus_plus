#include "Project.h"
#include "TestHarness.h"
#include "Bitmap.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "BitmapIterator.h"
#include "binary_ostream_iterator.h"
#include <fstream>

using namespace BitmapGraphics;

TEST(createDecoder, WindowsBitmapDecoder)
{
    std::ifstream bitmapStream(PROJECT_PATH + "basic.bmp", std::ios::binary);
    CHECK(bitmapStream.is_open());
	
	WindowsBitmapDecoder bmDecoder;
    
    HBitmapDecoder decoder = bmDecoder.clone(bitmapStream);
    CHECK_EQUAL("image/x-ms-bmp", decoder->getMimeType());
}

TEST(BitmapSizeTest, BitmapIterator)
{
    std::ifstream bitmapStream(PROJECT_PATH + "basic.bmp", std::ios::binary);
    CHECK(bitmapStream.is_open());
	
	WindowsBitmapDecoder bmDecoder;
    
    HBitmapDecoder decoder = bmDecoder.clone(bitmapStream);
    HBitmapIterator bitmapIter = decoder->createIterator();
    
    CHECK_EQUAL(100, bitmapIter->getBitmapWidth());
    CHECK_EQUAL(100, bitmapIter->getBitmapHeight());
}

TEST(BitmapScanLinesTest, BitmapIterator)
{
	std::ifstream bitmapStream(PROJECT_PATH + "basic.bmp", std::ios::binary);
    CHECK(bitmapStream.is_open());
	
	WindowsBitmapDecoder bmDecoder;
    
    HBitmapDecoder decoder = bmDecoder.clone(bitmapStream);
    HBitmapIterator bitmapIter = decoder->createIterator();
	
    int numberOfScanLines = 0;
    while (! bitmapIter->isEndOfImage())
    {
        int numberOfPixelsInScanLine = 0;
        while (! bitmapIter->isEndOfScanLine())
        {
            ++numberOfPixelsInScanLine;
            bitmapIter->nextPixel();
        }
        CHECK_EQUAL(100, numberOfPixelsInScanLine);
        ++numberOfScanLines;
        
        bitmapIter->nextScanLine();
    }
    CHECK_EQUAL(100, numberOfScanLines);
}

TEST(BitmapReadWrite, Bitmap)
{
    // Read in the bitmap
    
    std::ifstream bitmapStream(PROJECT_PATH + "basic.bmp", std::ios::binary);
    CHECK(bitmapStream.is_open());
	
	WindowsBitmapDecoder bmDecoder;
    
    HBitmapDecoder decoder = bmDecoder.clone(bitmapStream);
    HBitmapIterator bitmapIter = decoder->createIterator();
    
    // Write out the bitmap to a different file with its write() method
	
    std::ofstream outputStream(PROJECT_PATH + "output.bmp", std::ios::binary);
    CHECK(outputStream.is_open());
    
    WindowsBitmapEncoder bmEncoder;
	HBitmapEncoder encoder = bmEncoder.clone(bitmapIter);
    encoder->encodeToStream(outputStream);
    outputStream.close();
	
    // Read that one back in and check sizes
    
    std::ifstream bitmapStream2(PROJECT_PATH + "output.bmp", std::ios::binary);
    CHECK(bitmapStream2.is_open());
    
	
    HBitmapDecoder decoder2 = bmDecoder.clone(bitmapStream2);
    bitmapIter = decoder2->createIterator();
    
    int numberOfScanLines = 0;
    while (! bitmapIter->isEndOfImage())
    {
        int numberOfPixelsInScanLine = 0;
        while (! bitmapIter->isEndOfScanLine())
        {
            ++numberOfPixelsInScanLine;
            bitmapIter->nextPixel();
        }
        CHECK_EQUAL(100, numberOfPixelsInScanLine);
        ++numberOfScanLines;
        
        bitmapIter->nextScanLine();
    }
    CHECK_EQUAL(100, numberOfScanLines);
}
//
//
////// --- Repeat the tests with a bitmap that requires pad bytes (101x101)
//
//TEST(BitmapSizeTest_101, BitmapIterator)
//{
//    std::ifstream bitmapStream("basic_101.bmp", std::ios::binary);
//    CHECK(bitmapStream.is_open());
//    
//    WindowsBitmapDecoder decoder(bitmapStream);
//    HBitmapIterator bitmapIter = decoder.createIterator();
//    
//    CHECK_EQUAL(101, bitmapIter->getBitmapWidth());
//    CHECK_EQUAL(101, bitmapIter->getBitmapHeight());
//}
//
//TEST(BitmapScanLinesTest_101, BitmapIterator)
//{
//    std::ifstream bitmapStream("basic_101.bmp", std::ios::binary);
//    CHECK(bitmapStream.is_open());
//    
//    WindowsBitmapDecoder decoder(bitmapStream);
//    HBitmapIterator bitmapIter = decoder.createIterator();
//    
//    int numberOfScanLines = 0;
//    while (! bitmapIter->isEndOfImage())
//    {
//        int numberOfPixelsInScanLine = 0;
//        while (! bitmapIter->isEndOfScanLine())
//        {
//            ++numberOfPixelsInScanLine;
//            bitmapIter->nextPixel();
//        }
//        CHECK_EQUAL(101, numberOfPixelsInScanLine);
//        ++numberOfScanLines;
//        
//        bitmapIter->nextScanLine();
//    }
//    CHECK_EQUAL(101, numberOfScanLines);
//}
//
//TEST(BitmapReadWrite_101, Bitmap)
//{
//    // Read in the bitmap
//    
//    std::ifstream bitmapStream("basic_101.bmp", std::ios::binary);
//    CHECK(bitmapStream.is_open());
//    
//    WindowsBitmapDecoder decoder(bitmapStream);
//    HBitmapIterator bitmapIter = decoder.createIterator();
//    
//    // Write out the bitmap to a different file with its write() method
//    
//    std::ofstream outputStream("output_101.bmp", std::ios::binary);
//    CHECK(outputStream.is_open());
//    
//    WindowsBitmapEncoder encoder(bitmapIter);
//    encoder.encodeToStream(outputStream);
//    outputStream.close();
//    
//    // Read that one back in and check sizes
//    
//    std::ifstream bitmapStream2("output_101.bmp", std::ios::binary);
//    CHECK(bitmapStream2.is_open());
//    
//    WindowsBitmapDecoder decoder2(bitmapStream2);
//    bitmapIter = decoder2.createIterator();
//    
//    int numberOfScanLines = 0;
//    while (! bitmapIter->isEndOfImage())
//    {
//        int numberOfPixelsInScanLine = 0;
//        while (! bitmapIter->isEndOfScanLine())
//        {
//            ++numberOfPixelsInScanLine;
//            bitmapIter->nextPixel();
//        }
//        CHECK_EQUAL(101, numberOfPixelsInScanLine);
//        ++numberOfScanLines;
//        
//        bitmapIter->nextScanLine();
//    }
//    CHECK_EQUAL(101, numberOfScanLines);
//}
