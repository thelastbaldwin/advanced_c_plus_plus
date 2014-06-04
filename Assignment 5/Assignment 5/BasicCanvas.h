#pragma once

#include <iostream>
#include "ICanvas.h"

namespace Framework{
	class BasicCanvas: public ICanvas{
	public:
		void setPixelColor (const VG::Point&  location, BitmapGraphics::Color const& color);
		virtual BitmapGraphics::Color getPixelColor (const VG::Point& location) const;
		virtual int getWidth () const;
		virtual int getHeight () const;
		virtual BitmapGraphics::HBitmapIterator createBitmapIterator () const;
	};
}
