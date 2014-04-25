#include "TestHarness.h"
#include "PlacedGraphic.h"
#include "XMLStreamer.h"

//stringification
#define STR(s) #s

using namespace std;
using namespace VG;

TEST(fromXMLInit, PlacedGraphic){
//	stringstream ss(STR(<PlacedGraphic x="700" y="0">
//		<VectorGraphic closed="true">
//		<Point x="0" y="10" />
//		<Point x="10" y="20" />
//		<Point x="20" y="30" />
//		<Point x="30" y="40" />
//		<Point x="40" y="50" />
//		</VectorGraphic>
//		</PlacedGraphic>
//	));
//	
//	XMLNode PlacedGraphicElement = XMLStreamer::parseXml(ss);
//	PlacedGraphic pg(PlacedGraphicElement);
//	
//	Point pgPoint = pg.getPlacementPoint();
//	CHECK_EQUAL(700, pgPoint.getX());
//	CHECK_EQUAL(0, pgPoint.getY());
//	
//	VectorGraphic vg = pg.getGraphic();
//	CHECK_EQUAL(true, vg.isClosed());
//	CHECK_EQUAL(5, vg.getPointCount());
}