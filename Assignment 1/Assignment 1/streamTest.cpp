#include "TestHarness.h"
#include "XMLStreamer.h"
#include "Point.h"
#include <fstream>

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

TEST(getNameTest, regex){
	std::regex firstWordRegex("\\w+");
	std::smatch firstWordMatch;
	//returns bool
	std::regex_search(std::string("<VectorGraphic closed=\"true\">"), firstWordMatch, firstWordRegex);
	CHECK_EQUAL(firstWordMatch.str(), "VectorGraphic");
}

TEST(hasAttributesTest, regex){
	using namespace std;
	//if the tag has attributes, how to get all matching sets?
	// a single regex can't know how many groups to capture
	regex attributeRegex("(([a-zA-Z09-_]+)=\"([a-zA-Z0-9_\\s]+)\")");	
	smatch attributeMatch;

	bool found = regex_search(std::string("Point favoritemovie=\"Dances with Wolves\" pocahontas=\"native_american\" x=\"0\" y=\"255\""),
							  attributeMatch,
							  attributeRegex);
	if(!found){
		CHECK_FAIL("Unable to find attributes");
	}
}

TEST(readFileTest, fstream){
    using namespace std;
    using namespace VG;
    
    fstream fs;
    fs.open("/Users/steveminor/Documents/C++/Advanced_C_Plus_Plus/Assignment 1/Assignment 1/VG1.xml", ios::in);
    CHECK(fs.is_open());
	string line;
	getline(fs,line);
	CHECK_EQUAL(STR(<VectorGraphic closed="true">), line);
	fs.close();
}



