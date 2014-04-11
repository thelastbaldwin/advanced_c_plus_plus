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
	std::string justName = Parse::trim(myName, "ABCDEF");
	CHECK_EQUAL("Steve", justName);
}

TEST(trimBack, Parse){
	std::string myName("SteveABCDEF");
	std::string justName = Parse::trim(myName, "ABCDEF");
	CHECK_EQUAL("Steve", justName);
}

TEST(trimFrontBack, Parse){
	std::string myName("ABCDEFSteveABCDEF");
	std::string justName = Parse::trim(myName, "ABCDEF");
	CHECK_EQUAL("Steve", justName);
}

TEST(trimNothing, Parse){
	std::string myName("Steve");
	std::string justName = Parse::trim(myName, "ABCDEF");
	CHECK_EQUAL("Steve", justName);
}