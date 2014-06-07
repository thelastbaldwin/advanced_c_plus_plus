#pragma once

#include "Point.h"
#include "IBitmapIterator.h"

namespace Framework{
	class ICanvas
	{
	public:
		virtual void setPixelColor (const VG::Point& location, const BitmapGraphics::Color& color) = 0;
		virtual BitmapGraphics::Color getPixelColor (const VG::Point& location) const = 0;
		virtual int getWidth () const = 0;
		virtual int getHeight () const = 0;
		virtual BitmapGraphics::HBitmapIterator createBitmapIterator () = 0;
	};
}


