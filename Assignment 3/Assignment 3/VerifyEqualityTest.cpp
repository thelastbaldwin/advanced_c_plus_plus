#include "TestHarness.h"
#include "VerifyEquality.h"
#include "Word.h"
#include "DoubleWord.h"
#include <iostream>

TEST(verifyEquality, Word)
{
    const unsigned char input[] = { 0xAB, 0xCD, 0 };
    std::stringstream ss(reinterpret_cast<const char*>(input));

    Binary::Word actual = Binary::Word::readLittleEndian(ss);
    Binary::Word notReallyExpected(0xABCD);
	bool hasFailed = false;

    try
    {
        verifyEquality(notReallyExpected, actual, "Word");
        CHECK(false);
    }
    catch (const std::exception& e)
    {
        //std::cout << e.what() << std::endl;
        hasFailed = true;
    }
	
	CHECK(hasFailed);
}

TEST(verifyEquality, DoubleWord)
{
    const unsigned char input[] = { 0xb1, 0xb2, 0xb3, 0xb4, 0 };
    std::stringstream ss(reinterpret_cast<const char*>(input));
    
    const Binary::DoubleWord actual = Binary::DoubleWord::readLittleEndian(ss);
    const Binary::DoubleWord notReallyExpected(0xb1b2b3b4);
    
	bool hasFailed = false;
    
    try
    {
        verifyEquality(notReallyExpected, actual, "DoubleWord");
        CHECK(false);
    }
    catch (const std::exception& e)
    {
        //std::cout << e.what() << std::endl;
        hasFailed = true;
    }
	
	CHECK(hasFailed);
}