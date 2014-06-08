#include "XMLStreamer.h"
#include "XMLNode.h"
#include "Scene.h"
//#include "SceneReader.h"
#include "BasicCanvas.h"
#include "WindowsBitmapFileProjector.h"
#include "WindowsBitmapDecoder.h"
#include "WindowsBitmapEncoder.h"
#include "CodecLibrary.h"
#include "TestHarness.h"

#define STR(a) #a

namespace
{
    class CodecLibrarySetup
    {
    public:
        CodecLibrarySetup()
        {
            myCodecLibrary.registerEncoder(BitmapGraphics::HBitmapEncoder(new BitmapGraphics::WindowsBitmapEncoder));
            myCodecLibrary.registerDecoder(BitmapGraphics::HBitmapDecoder(new BitmapGraphics::WindowsBitmapDecoder));
        }

        operator BitmapGraphics::CodecLibrary&()
        {
            return myCodecLibrary;
        }

    private:
		BitmapGraphics::CodecLibrary myCodecLibrary;

    };
}

const char* const TestXml = STR(
								<Scene width="800" height="600">
								<Layer alias="sky">
								<PlacedGraphic x="0" y="0">
								<VectorGraphic closed="true">
								<Point x="1" y="2" />
								<!-- Comment -->
								<Point x="3" y="4" />
								<Point x="5" y="6" />
								</VectorGraphic>
								</PlacedGraphic>
								<!-- Comment -->
								<PlacedGraphic x="700" y="0">
								<VectorGraphic closed="false">
								<Point x="7" y="8" />
								<Point x="9" y="10" />
								<Point x="11" y="12" />
								</VectorGraphic>
								</PlacedGraphic>
								</Layer>
								<Layer alias="mountains">
								<PlacedGraphic x="250" y="250">
								<VectorGraphic closed="false">
								<Point x="13" y="14" />
								<Point x="15" y="19" />
								<Point x="17" y="18" />
								<!-- etc... -->
								</VectorGraphic>
								</PlacedGraphic>
								</Layer>
								</Scene>);

const char* const sceneXml = STR(
								 <Scene width="800" height="800" color="EFEFEF">
								 <Layer alias="bottom">
								 <PlacedGraphic x="0" y="0">
								 <VectorGraphic closed="true">
								 <Stroke tip="slash" size="7" color="FF0000" />
								 <Point x="100" y="500" />
								 <Point x="100" y="100" />
								 <Point x="500" y="600" />
								 </VectorGraphic>
								 </PlacedGraphic>
								 <PlacedGraphic x="400" y="300">
								 <VectorGraphic closed="true">
								 <Stroke tip="square" size="5" color="00FF00" />
								 <Point x="0" y="0" />
								 <Point x="0" y="100" />
								 <Point x="100" y="100" />
								 <Point x="100" y="0" />
								 </VectorGraphic>
								 </PlacedGraphic>
								 </Layer>
								 <Layer alias="top">
								 <PlacedGraphic x="250" y="250">
								 <VectorGraphic closed="false">
								 <Stroke tip="square" size="3" color="0000FF" />
								 <Point x="0" y="0" />
								 <Point x="0" y="100" />
								 <Point x="100" y="100" />
								 <Point x="100" y="0" />
								 </VectorGraphic>
								 </PlacedGraphic>
								 </Layer>
								 </Scene>);


using namespace BitmapGraphics;

TEST(pointComparison, Point){
	using namespace VG;
	CHECK(Point(5, 5) < Point(6, 6));
	CHECK(!(Point(5, 5) > Point(5, 5)));
	CHECK(!(Point(5, 5) < Point(5, 5)));
	CHECK(Point(6, 6) > Point(5, 5));
	CHECK(Point(0, 180) < Point(0, 181));
	CHECK(Point(200, 180) < Point(200, 181));
	CHECK(Point(10, 0) > Point(5, 0));
	CHECK(Point(4, 3) > Point(5, 0));
	CHECK(Point(10, 10) > Point(10, 9));
}

TEST(RGBfromHex, Color){
	std::string testColor("FF0000");
	
	BitmapGraphics::Color colorFromHex = BitmapGraphics::Color::fromHex(testColor);

	CHECK_EQUAL(255, colorFromHex.getRed().toInt());
	CHECK_EQUAL(0, colorFromHex.getGreen().toInt());
	CHECK_EQUAL(0, colorFromHex.getBlue().toInt());
	
	std::string testColor2("FFFFFF");
	
	BitmapGraphics::Color colorFromHex2 = BitmapGraphics::Color::fromHex(testColor2);
	
	CHECK_EQUAL(255, colorFromHex2.getRed().toInt());
	CHECK_EQUAL(255, colorFromHex2.getGreen().toInt());
	CHECK_EQUAL(255, colorFromHex2.getBlue().toInt());
}

TEST(SceneColor, XMLStreamer){
	std::stringstream xmlStream(TestXml);
	
	VG::HXMLNode root = VG::XMLStreamer::parseXml(xmlStream);
	VG::Scene myScene(root);
	
	CHECK_EQUAL(0, myScene.getBackgroundColor().getRed().toInt());
	CHECK_EQUAL(0, myScene.getBackgroundColor().getGreen().toInt());
	CHECK_EQUAL(0, myScene.getBackgroundColor().getBlue().toInt());
	
	std::stringstream xmlStream2(STR(<Scene width="800" height="800" color="EFEFEF"></Scene>));
	VG::HXMLNode root2 = VG::XMLStreamer::parseXml(xmlStream2);
	VG::Scene myScene2(root2);
	
	CHECK_EQUAL(239, myScene2.getBackgroundColor().getRed().toInt());
	CHECK_EQUAL(239, myScene2.getBackgroundColor().getGreen().toInt());
	CHECK_EQUAL(239, myScene2.getBackgroundColor().getBlue().toInt());
}

TEST(basicCanvasIteratorInit, basicCanvasBitmapIterator){
	//testing contstructors
	using namespace Framework;
	
	BasicCanvas myCanvas(20, 20);
	BasicCanvasBitmapIterator testIter(myCanvas);
	HBitmapIterator canvasIterator2 = myCanvas.createBitmapIterator();
}

TEST(blueBitmapTest, scene){
	using namespace Framework;
	using namespace VG;
	
	std::stringstream xmlStream(STR(<Scene width="200" height="200" color="0000FF"></Scene>));
	VG::HXMLNode root = VG::XMLStreamer::parseXml(xmlStream);
	VG::Scene myScene(root);
	
	BasicCanvas myCanvas(myScene.getWidth(), myScene.getHeight());
	
	myScene.draw(myCanvas);
	auto pixelData = myCanvas.getPixelMap();
	CHECK_EQUAL(40000, pixelData.size());
	
	VG::Point myPoint(1, 20);
	for(auto pixelPair : pixelData){
		if(pixelPair.first == myPoint){
			CHECK(true);
			break;
		}
	}
	CHECK(pixelData.find(myPoint) != pixelData.end());
	
	for (int row = 0; row < myScene.getHeight(); ++row) {
		for (int column = 0; column < myScene.getWidth(); ++column) {
			BitmapGraphics::Color currentColor = myCanvas.getPixelColor(VG::Point(column, row));
			CHECK_EQUAL(0, currentColor.getRed().toInt());
			CHECK_EQUAL(0, currentColor.getGreen().toInt());
			CHECK_EQUAL(255, currentColor.getBlue().toInt());
		}
	}
	
	CodecLibrary codecLibrary = CodecLibrarySetup();
	HBitmapIterator canvasIterator = myCanvas.createBitmapIterator();
	
	WindowsBitmapFileProjector myProjector("blue.bmp", codecLibrary);
	myProjector.projectCanvas(myCanvas);
}

//TEST(ReadScene, SceneReader)
//{
//    std::stringstream xmlStream(TestXml);
//	
//	VG::HXMLNode root = VG::XMLStreamer::parseXml(xmlStream);
//	
//    VG::Scene s = VG::Scene(root);
//	
//    CHECK_EQUAL(800, s.getWidth());
//    CHECK_EQUAL(600, s.getHeight());
//	
//	//VG::LayerIterator? Scene.createIterator()?
//    Framework::Scene::LayerIterator pos;
//    int iLayer;
//    for (iLayer = 0, pos = s.begin(); pos != s.end(); ++iLayer, ++pos)
//    {
//        const Framework::Layer& layer = (*pos);
//        if (iLayer == 0)
//        {
//            // verify sky layer
//            CHECK_EQUAL("sky", layer.getAlias());
//            Framework::Layer::PlacedGraphicIterator graphic;
//            int iGraphic;
//            for (iGraphic = 0, graphic = layer.begin(); graphic != layer.end(); ++iGraphic, ++graphic)
//            {
//                if (iGraphic == 0)
//                {
//                    CHECK_EQUAL(VG::Point(0, 0), (*graphic).getPlacementPoint());
//                    const VG::VectorGraphic& vg = (*graphic).getGraphic();
//                    CHECK_EQUAL(true, vg.isClosed());
//                    CHECK_EQUAL(3, vg.getPointCount());
//                    CHECK_EQUAL(VG::Point(1, 2), vg.getPoint(0));
//                    CHECK_EQUAL(VG::Point(3, 4), vg.getPoint(1));
//                    CHECK_EQUAL(VG::Point(5, 6), vg.getPoint(2));
//					
//                }
//                else if (iGraphic == 1)
//                {
//                    CHECK_EQUAL(VG::Point(700, 0), (*graphic).getPlacementPoint());
//                    const VG::VectorGraphic& vg = (*graphic).getGraphic();
//                    CHECK_EQUAL(false, vg.isClosed());
//                }
//            }
//			
//            CHECK_EQUAL(2, iGraphic);
//        }
//        else if (iLayer == 1)
//        {
//            // verify mountains layer
//            CHECK_EQUAL("mountains", layer.getAlias());
//			
//            Framework::Layer::PlacedGraphicIterator graphic;
//            int iGraphic;
//            for (iGraphic = 0, graphic = layer.begin(); graphic != layer.end(); ++iGraphic, ++graphic)
//            {
//            }
//			
//            CHECK_EQUAL(1, iGraphic);
//        }
//    }
//	
//    // Expect 2 layers
//    CHECK_EQUAL(2, iLayer);
//}
//

//
//TEST(toBitmap, SceneReader)
//{
//    std::stringstream xmlStream(sceneXml);
//    
//    // Parse the XML into a DOM
//	VG::HXMLNode root = VG::XMLStreamer::parseXml(xmlStream);
//    
//    // Construct a vector graphic Scene from the DOM
//    VG::Scene s = VG::Scene(root);
//    
//    // Create an empty Canvas
//    Color backgroundColor(100, 100, 100);
//    HCanvas canvas(new BasicCanvas(scene.getWidth(), scene.getHeight(), backgroundColor));
//    
//    // Draw the Scene onto the Canvas
//    scene.draw(canvas);
//	
//    // Create a WindowsBitmapFileProjector and give it an output file name to create
//    // Also give it the CodecLibrary ("dependency injection").
//    CodecLibrarySetup codecLibrary;
//    HProjector projector(new WindowsBitmapFileProjector("output_scene.bmp", codecLibrary));
//    
//    // Project the Canvas into the bitmap file
//    projector->projectCanvas(canvas);
//}