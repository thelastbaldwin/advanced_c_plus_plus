#include "TestHarness.h"
#include <string>
#include <sstream>
#include "Parse.h"

TEST(eatChars, Parse){
	std::stringstream myStream("666 Number");
	Parse::eat(myStream, "666 ");
	std::string leftOvers;
	myStream >> leftOvers;
	CHECK_EQUAL(leftOvers, "Number");
}

TEST(eatNothing, Parse){
	std::stringstream myStream("TotallyWickedBadass");
	Parse::eat(myStream, "12345678&");
	std::string leftOvers;
	myStream >> leftOvers;
	CHECK_EQUAL(leftOvers, "TotallyWickedBadass");
}

TEST(trimFront, Parse){
	std::string myName("ABCDEFSteve");
	Parse::trim(myName, "ABCDEF");
	CHECK_EQUAL("Steve", myName);
}

TEST(trimBack, Parse){
	std::string myName("SteveABCDEF");
	Parse::trim(myName, "ABCDEF");
	CHECK_EQUAL("Steve", myName);
}

TEST(trimFrontBack, Parse){
	std::string myName("ABCDEFSteveABCDEF");
	Parse::trim(myName, "ABCDEF");
	CHECK_EQUAL("Steve", myName);
}

TEST(trimNothing, Parse){
	std::string myName("Steve");
	Parse::trim(myName, "ABCDEF");
	CHECK_EQUAL("Steve", myName);
}

TEST(trimEverything, Parse)
{
    std::string actual("Hello 1234");
    std::string trimmables("Hello 0123456789");
    Parse::trim(actual, trimmables);
    std::string expected;
    CHECK_EQUAL(expected, actual);
}