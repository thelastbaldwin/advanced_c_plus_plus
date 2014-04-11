#include "TestHarness.h"
#include <string>
#include <sstream>


// Tests for methods which can drive trim and eat
// methods in Parse namespace
TEST(streamPeek, stringStream){
	int streamCharCount = 0;
	std::stringstream myStream("Steve");
	
	CHECK_EQUAL(myStream.peek(), 'S');
	
	// cruise through characters
	while(myStream.good()){
		myStream.peek();
		myStream.ignore();
		++streamCharCount;
	}
	
	CHECK_EQUAL(streamCharCount, 5);
}

TEST(erase, string){
	std::string myName("Steve");
	std::string::const_iterator beginTrim;
	std::string::const_iterator endTrim;
	
	for(auto iter = myName.begin(); iter != myName.end(); ++iter){
		
	}
}