#include "TestHarness.h"
#include "XMLStreamer.h"
#include "Scene.h"
#include <fstream>

//stringification
#define STR(s) #s

TEST(newFormatParse, XMLStreamer){
	using namespace std;
	using namespace VG;
	
	stringstream testXML(STR(<Scene width="800" height="600">
		 <Layer alias="sky">
		 <PlacedGraphic x="0" y="0">
		 <VectorGraphic closed="true">
		 <Point x="0" y="10" />
		 <!-- etc... -->
		 </VectorGraphic>
		 </PlacedGraphic>
		 <PlacedGraphic x="700" y="0">
		 <VectorGraphic closed="true">
		 <!-- etc... -->
		 </VectorGraphic>
		 </PlacedGraphic>
		 </Layer>
		 <Layer alias="mountains">
		 <PlacedGraphic x="0" y="0">
		 <VectorGraphic closed="false">
		 <!-- etc... -->
		 </VectorGraphic>
		 </PlacedGraphic>
		 </Layer>
		 <Layer alias="houses">
		 <!-- etc... -->
		 </Layer>
		 </Scene>));
	
	shared_ptr<XMLNode> parsedXML = XMLStreamer::parseXml(testXML);
	CHECK_EQUAL("Scene", parsedXML->getName());
	auto parsedXMLChildren = parsedXML->getAllChildren();
	CHECK_EQUAL(3, parsedXMLChildren.size());
	for (auto child : parsedXMLChildren){
		CHECK_EQUAL("Layer", child->getName());
	}
	auto sky = parsedXMLChildren[0];
	CHECK_EQUAL("sky", sky->getAttribute("alias"));
	auto skyChildren = sky->getAllChildren();
	CHECK_EQUAL(2, skyChildren.size());
	CHECK_EQUAL("0", skyChildren[0]->getAttribute("x"));
	CHECK_EQUAL("0", skyChildren[0]->getAttribute("y"));
}

TEST(sceneFromXML, Scene){
	using namespace std;
	using namespace VG;
	
	stringstream testXML(STR(<Scene width="800" height="600">
							 <Layer alias="sky">
							 <PlacedGraphic x="0" y="0">
							 <VectorGraphic closed="true">
							 <Point x="0" y="10" />
							 <!-- etc... -->
							 </VectorGraphic>
							 </PlacedGraphic>
							 <PlacedGraphic x="700" y="0">
							 <VectorGraphic closed="true">
							 <!-- etc... -->
							 </VectorGraphic>
							 </PlacedGraphic>
							 </Layer>
							 <Layer alias="mountains">
							 <PlacedGraphic x="0" y="0">
							 <VectorGraphic closed="false">
							 <!-- etc... -->
							 </VectorGraphic>
							 </PlacedGraphic>
							 </Layer>
							 <Layer alias="houses">
							 <!-- etc... -->
							 </Layer>
							 </Scene>));
	
	shared_ptr<XMLNode> parsedXML = XMLStreamer::parseXml(testXML);
	Scene myScene(parsedXML);
	CHECK_EQUAL(myScene.getWidth(), 800);
	CHECK_EQUAL(myScene.getHeight(), 600);
}

TEST(layerFromXML, Layer){
	using namespace std;
	using namespace VG;
	
	stringstream testXML(STR(<Layer alias="sky">
							 <PlacedGraphic x="0" y="0">
							 <VectorGraphic closed="true">
							 <Point x="0" y="10" />
							 <!-- etc... -->
							 </VectorGraphic>
							 </PlacedGraphic>
							 <PlacedGraphic x="700" y="0">
							 <VectorGraphic closed="true">
							 <!-- etc... -->
							 </VectorGraphic>
							 </PlacedGraphic>
							 </Layer>));
	Layer myLayer(XMLStreamer::parseXml(testXML));
	CHECK_EQUAL("sky", myLayer.getAlias());
	
	auto skyPGs = myLayer.getPlacedGraphics();
	CHECK_EQUAL(2, skyPGs.size());
}

TEST(placedGraphicFromXML, PlacedGraphic)
{
	using namespace std;
	using namespace VG;
	
	stringstream testXML(STR(<PlacedGraphic x="0" y="0">
							 <VectorGraphic closed="true">
							 <Point x="0" y="10" />
							 <!-- etc... -->
							 </VectorGraphic>
							 </PlacedGraphic>));
	
	PlacedGraphic myPG(XMLStreamer::parseXml(testXML));
	VectorGraphic myVG = myPG.getGraphic();
	CHECK(myVG.isClosed());
}


TEST(fromXMLFileTest, fstream){
    using namespace std;
    using namespace VG;
    
    fstream fs;
	fs.open("/Users/steveminor/Documents/C++/Advanced_C_Plus_Plus/Assignment 1/Assignment 1/VG1.xml", ios::in);
	if(!fs.is_open()){
		CHECK_FAIL("unable to open file");
	}
	std::shared_ptr<XMLNode> topLevelElement = XMLStreamer::parseXml(fs);
	VectorGraphic myVG;
	myVG.fromXML(topLevelElement);
	
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
	
	fs.close();
}

TEST(toXMLTest, fstream){
	using namespace std;
	using namespace VG;
	
	fstream fs;
	fs.open("/Users/steveminor/Documents/C++/Advanced_C_Plus_Plus/Assignment 2/VG2.xml", ios::out);
	
	VectorGraphic myVG;
	myVG.addPoint(Point(10, 10));
	myVG.addPoint(Point(0, 10));
	myVG.addPoint(Point(10, 0));
	myVG.addPoint(Point(0, 0));
	myVG.addPoint(Point(-5, -5));
	
	myVG.toXML(fs);
	fs.close();
	
	fs.open("/Users/steveminor/Documents/C++/Advanced_C_Plus_Plus/Assignment 2/VG2.xml", ios::in);
	std::shared_ptr<XMLNode> topLevelElement = XMLStreamer::parseXml(fs);
	myVG.fromXML(topLevelElement);
	
	CHECK_EQUAL(5, myVG.getPointCount());
	Point pt = myVG.getPoint(0);
	CHECK_EQUAL(10, pt.getX());
	CHECK_EQUAL(10, pt.getY());
	pt = myVG.getPoint(1);
	CHECK_EQUAL(0, pt.getX());
	CHECK_EQUAL(10, pt.getY());
	pt = myVG.getPoint(2);
	CHECK_EQUAL(10, pt.getX());
	CHECK_EQUAL(0, pt.getY());
	pt = myVG.getPoint(3);
	CHECK_EQUAL(0, pt.getX());
	CHECK_EQUAL(0, pt.getY());
	pt = myVG.getPoint(4);
	CHECK_EQUAL(-5, pt.getX());
	CHECK_EQUAL(-5, pt.getY());
	
	fs.close();
	
}