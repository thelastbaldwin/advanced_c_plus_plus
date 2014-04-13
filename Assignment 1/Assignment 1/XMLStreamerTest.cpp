#include "TestHarness.h"
#include "XMLStreamer.h"

#define STR(s) #s

TEST(isCommentTest, XMLStreamer){
	CHECK(VG::XMLStreamer::isComment("!-- I bet JSON is really fun --"));
	CHECK(VG::XMLStreamer::isComment("!-- lksjdfl.sdf789u3r9ddn --"));
	CHECK(VG::XMLStreamer::isComment("!-- lksjdfl.\n\n\n\t\tsdf789u3r9ddn --"));
}

TEST(isValidTest, XMLStreamer){
	CHECK(VG::XMLStreamer::isValid(STR(VectorGraphic closed="true")));
	CHECK(VG::XMLStreamer::isValid(STR(Point x="0" y="0_sdfsdf"/)));
	CHECK(VG::XMLStreamer::isValid(STR(Point x="10" y="0")));
	CHECK(VG::XMLStreamer::isValid(STR(Point favoritemovie="Dances with Wolves" pocahontas="native_american")));
	CHECK(VG::XMLStreamer::isValid(STR(/Point)));
	CHECK(VG::XMLStreamer::isValid(STR(Point x="10" y="10"/)));
	CHECK(VG::XMLStreamer::isValid(STR(Point x="0" y="10"/)));
	CHECK(VG::XMLStreamer::isValid(STR(/VectorGraphic)));
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

TEST(getNameTest, XMLStreamer){
	using namespace std;
	using namespace VG;
	
	stringstream ss(STR(
						<VectorGraphic closed="true">
						<Point x="0" y="0"/>
						<Point x="10" y="0">
						</Point>
						<Point x="10" y="10"/>
						<Point x="0" y="10"/>
						</VectorGraphic>
						));
	
	string token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL("VectorGraphic", VG::XMLStreamer::getTagName(token));

	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL("Point", VG::XMLStreamer::getTagName(token));
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL("Point", VG::XMLStreamer::getTagName(token));
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL("Point", VG::XMLStreamer::getTagName(token));
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL("Point", VG::XMLStreamer::getTagName(token));
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL("Point", VG::XMLStreamer::getTagName(token));
	token = VG::XMLStreamer::getNextToken(ss);
	CHECK_EQUAL("VectorGraphic", VG::XMLStreamer::getTagName(token));
		
	token = VG::XMLStreamer::getNextToken(ss);
	try {
		XMLStreamer::getTagName(token);
	}
	catch(const std::invalid_argument e){
		//cout << "exception encountered successfully" << endl;
		CHECK(true);
	}
	
}