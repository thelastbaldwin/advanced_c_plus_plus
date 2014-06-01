#pragma once

namespace Framework{
	class ICanvas
	{
	public:
		virtual void setPixelColor (Point const& location, Color const& color) = 0;
		virtual Color getPixelColor (Point const& location) const = 0;
		virtual int getWidth () const = 0;
		virtual int getHeight () const = 0;
		virtual HBitmapIterator createBitmapIterator () const = 0;
	};
}


