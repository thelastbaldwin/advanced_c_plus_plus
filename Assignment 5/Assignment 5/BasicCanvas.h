#pragma once

#include <iostream>
#include <map>
#include "ICanvas.h"
#include "IBitmapIterator.h"

namespace Framework{
	class BasicCanvas: public ICanvas{
	public:
		BasicCanvas(const int& _width=0, const int& _height=0);
		
		void setPixelColor (const VG::Point& location, const BitmapGraphics::Color& color);
		BitmapGraphics::Color getPixelColor (const VG::Point& location) const;
		int getWidth () const;
		int getHeight () const;
		BitmapGraphics::HBitmapIterator createBitmapIterator() const;
		
		const std::map<VG::Point, BitmapGraphics::Color>& getPixelMap() const;
		
	private:
		std::map<VG::Point, BitmapGraphics::Color> myPixels;
		int width;
		int height;
	};
}
