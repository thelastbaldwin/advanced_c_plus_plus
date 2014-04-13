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