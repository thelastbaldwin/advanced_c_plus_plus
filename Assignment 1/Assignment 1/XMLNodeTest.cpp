#include "TestHarness.h"
#include "XMLNode.h"

TEST(nodeInitTest, XMLNode){
	using namespace std;
	using namespace VG;
	
	typedef pair<string, string> keyValue;
	map<string, string>dummyValues = {
		keyValue("x", "0"),
		keyValue("y", "10"),
	};
	
	map<string, string>parentDummyValues = {
		keyValue("closed", "true")
	};
	
	shared_ptr<XMLNode> parentNode(new XMLNode("VectorGraphic", parentDummyValues));
	shared_ptr<XMLNode> child1(new XMLNode("Point", dummyValues, parentNode));
	shared_ptr<XMLNode> child2(new XMLNode("Point", dummyValues, parentNode));
	
	CHECK(parentNode->hasChildren());
	auto children = parentNode->getAllChildren();
	CHECK_EQUAL(2, children.size());
	
	for(auto iter = children.begin(); iter != children.end(); ++iter) {
		CHECK_EQUAL("VectorGraphic", iter->getParent()->getName());
		CHECK_EQUAL("Point", iter->getName());
		CHECK_EQUAL("0", iter->getAttribute("x"));
		CHECK_EQUAL("10", iter->getAttribute("y"));
	}
}

TEST(nodePtrReassignment, XMLNode){
	using namespace std;
	using namespace VG;
	
	shared_ptr<XMLNode> villageBicycle;
	
	typedef pair<string, string> keyValue;
	map<string, string>dummyValues = {
		keyValue("x", "0"),
		keyValue("y", "10"),
	};
	
	map<string, string>dummyValues2 = {
		keyValue("x", "255"),
		keyValue("y", "99"),
	};
	
	villageBicycle = make_shared<XMLNode>(XMLNode(std::string("Point"), dummyValues));
	CHECK_EQUAL("Point", villageBicycle->getName());
	CHECK_EQUAL("10", villageBicycle->getAttribute("y"));
	CHECK_EQUAL("0", villageBicycle->getAttribute("x"));
	
	villageBicycle = make_shared<XMLNode>(XMLNode(std::string("VectorGraphic"), dummyValues2));
	CHECK_EQUAL("VectorGraphic", villageBicycle->getName());
	CHECK_EQUAL("99", villageBicycle->getAttribute("y"));
	CHECK_EQUAL("255", villageBicycle->getAttribute("x"));
	CHECK_EQUAL("", villageBicycle->getAttribute("bad key"));
}