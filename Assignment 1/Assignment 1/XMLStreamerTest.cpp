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
		//cout << e.what() << endl;
		CHECK(true);
	}
}

TEST(getAttributesTest, regex){
	using namespace std;
	using namespace VG;
	
	string tag = "Point favoritemovie=\"Dances with Wolves\" pocahontas=\"native_american\" x=\"0\" y=\"255\"";
	map<string, string> attributes = XMLStreamer::getAttributes(tag);
	
	auto iter = attributes.begin();
	CHECK_EQUAL(iter->second, "Dances with Wolves");
	++iter;
	CHECK_EQUAL(iter->second, "native_american");
	++iter;
	CHECK_EQUAL(iter->second, "0");
	++iter;
	CHECK_EQUAL(iter->second, "255");
}

TEST(noAttributesTest, regex){
	using namespace std;
	using namespace VG;
	
	string tag = "Point /";
	map<string, string> attributes = XMLStreamer::getAttributes(tag);
	
	CHECK(attributes.empty());
	
	tag = "/Point";
	attributes = XMLStreamer::getAttributes(tag);
	
	CHECK(attributes.empty());
	
	// wouldn't really be a valid tag in this system, because
	// we're not accounting for value between tags. 
	tag = "Point";
	attributes = XMLStreamer::getAttributes(tag);
	
	CHECK(attributes.empty());
}

TEST(pareseXMLTest, XMLStreamer){
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
	
	shared_ptr<XMLNode> topLevelElement(XMLStreamer::parseXml(ss));
	CHECK_EQUAL("VectorGraphic", topLevelElement->getName());
	CHECK_EQUAL("true", topLevelElement->getAttribute("closed"));
	CHECK(topLevelElement->hasChildren());
	vector<XMLNode> children = topLevelElement->getAllChildren();
	CHECK_EQUAL(4, children.size());
	
	XMLNode Point1 = children[0];
	CHECK_EQUAL("Point", Point1.getName());
	CHECK_EQUAL("0", Point1.getAttribute("x"));
	CHECK_EQUAL("0", Point1.getAttribute("y"));
	XMLNode Point2 = children[1];
	CHECK_EQUAL("Point", Point2.getName());
	CHECK_EQUAL("10", Point2.getAttribute("x"));
	CHECK_EQUAL("0", Point2.getAttribute("y"));
	XMLNode Point3 = children[2];
	CHECK_EQUAL("Point", Point3.getName());
	CHECK_EQUAL("10", Point3.getAttribute("x"));
	CHECK_EQUAL("10", Point3.getAttribute("y"));
	XMLNode Point4 = children[3];
	CHECK_EQUAL("Point", Point4.getName());
	CHECK_EQUAL("0", Point4.getAttribute("x"));
	CHECK_EQUAL("10", Point4.getAttribute("y"));
}