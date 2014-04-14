#include "TestHarness.h"
#include "VectorGraphic.h"

#define STR(s) #s

TEST(emptyInitTest, VectorGraphic){
	using namespace std;
	using namespace VG;
	
	VectorGraphic myVG;
	CHECK(myVG.isOpen()); //member isClosed auto initalized to true
}

TEST(pointShuffle, VectorGraphic){
	using namespace std;
	using namespace VG;
	
	VectorGraphic myVG;
	Point p1(0, 100);
	Point p2(50, 100);
	Point p3(100, 0);
	Point p4(250, 900);
	
	myVG.addPoint(p1);
	myVG.addPoint(p1);
	myVG.addPoint(p1);
	myVG.addPoint(p1);
	
	CHECK_EQUAL(4, myVG.getPointCount());
	myVG.removePoint(p1); //removes first found
	CHECK_EQUAL(3, myVG.getPointCount());
	myVG.removePoint(Point(0, 100));
	CHECK_EQUAL(2, myVG.getPointCount());
	myVG.erasePoint(1);
	CHECK_EQUAL(1, myVG.getPointCount());
	myVG.erasePoint(0);
	CHECK_EQUAL(0, myVG.getPointCount());
	
	myVG.addPoint(p1);
	myVG.addPoint(p2);
	myVG.addPoint(p3);
	myVG.addPoint(p4);
	
	CHECK_EQUAL(100, myVG.getPoint(0).getY());
	CHECK_EQUAL(100, myVG.getPoint(1).getY());
	CHECK_EQUAL(0, myVG.getPoint(2).getY());
	CHECK_EQUAL(900, myVG.getPoint(3).getY());
}

TEST(getWidthTest, VectorGraphic){
	using namespace std;
	using namespace VG;
	
	VectorGraphic myVG;
	Point p1(0, 100);
	Point p2(50, 100);
	Point p3(100, 0);
	Point p4(250, 900);
	
	myVG.addPoint(p1);
	CHECK_EQUAL(0, myVG.getWidth());
	myVG.addPoint(p2);
	CHECK_EQUAL(50, myVG.getWidth());
	myVG.addPoint(p3);
	CHECK_EQUAL(100, myVG.getWidth());
	myVG.addPoint(p4);
	CHECK_EQUAL(250, myVG.getWidth());
}

TEST(getHeightTest, VectorGraphic){
	using namespace std;
	using namespace VG;
	
	VectorGraphic myVG;
	Point p1(0, 100);
	Point p2(50, 100);
	Point p3(100, 255);
	Point p4(250, 900);
	
	myVG.addPoint(p1);
	CHECK_EQUAL(0, myVG.getHeight());
	myVG.addPoint(p2);
	CHECK_EQUAL(0, myVG.getHeight());
	myVG.addPoint(p3);
	CHECK_EQUAL(155, myVG.getHeight());
	myVG.addPoint(p4);
	CHECK_EQUAL(800, myVG.getHeight());
}

TEST(fromXMLTest, VectorGraphic){
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
	
	shared_ptr<XMLNode> topLevelElement = (XMLStreamer::parseXml(ss));
	VectorGraphic myVG = VectorGraphic::fromXML(topLevelElement);

	CHECK_EQUAL(4, myVG.getPointCount());
	Point pt = myVG.getPoint(0);
	CHECK_EQUAL(0, pt.getX());
	CHECK_EQUAL(0, pt.getY());
	pt = myVG.getPoint(1);
	CHECK_EQUAL(10, pt.getX());
	CHECK_EQUAL(0, pt.getY());
	pt = myVG.getPoint(2);
	CHECK_EQUAL(10, pt.getX());
	CHECK_EQUAL(10, pt.getY());
	pt = myVG.getPoint(3);
	CHECK_EQUAL(0, pt.getX());
	CHECK_EQUAL(10, pt.getY());
}