#include "TestHarness.h"
#include "XMLStreamer.h"

#define STR(s) #s

// Scratch tests 

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

TEST(getLineTest, stringStream){
	std::stringstream ss(STR(<VectorGraphic closed="true">    <Point x="0" y="0"/>));
	std::string token;
	
	std::getline(ss, token, '>');
	CHECK_EQUAL(STR(<VectorGraphic closed="true"), token);
	std::getline(ss, token, '>');
	Parse::trim(token, " <>");
	CHECK_EQUAL("Point x=\"0\" y=\"0\"/", token);
}

TEST(getTagContentsTest, stringStream){
	using namespace std;
	
	stringstream ss(STR(
		<VectorGraphic closed="true">
		<Point x="0" y="0"/>
		<Point x="10" y="0">
		</Point>
		<Point x="10" y="10"/>
		<Point x="0" y="10"/>
		</VectorGraphic>
	));
	
	std::string token;
	std::getline(ss, token, '>');
	Parse::trim(token, " \t\n<>");
	CHECK_EQUAL(STR(VectorGraphic closed="true"), token);
	std::getline(ss, token, '>');
	Parse::trim(token, " \t\n<>");
	CHECK_EQUAL(STR(Point x="0" y="0"/), token);
}

TEST(getNextToken, stringStream){
	using namespace std;
	
	stringstream ss(STR(
		<VectorGraphic closed="true">
		<Point x="0" y="0"/>
		<Point x="10" y="0">
		</Point>
		<Point x="10" y="10"/>
		<Point x="0" y="10"/>
		</VectorGraphic>
	));
	
	std::string token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL(STR(VectorGraphic closed="true"), token);
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL(STR(Point x="0" y="0"/), token);
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL(STR(Point x="10" y="0"), token);
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL(STR(/Point), token);
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL(STR(Point x="10" y="10"/), token);
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL(STR(Point x="0" y="10"/), token);
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL(STR(/VectorGraphic), token);
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL("", token); 
}