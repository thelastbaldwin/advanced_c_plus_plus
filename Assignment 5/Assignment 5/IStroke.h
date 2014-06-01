#pragma once
namespace Framework{
	class IStroke
	{
	public:
		virtual void setSize (int size) = 0;
		virtual int getSize () const = 0;
		virtual void setColor (Color const& color) = 0;
		virtual Color getColor () const = 0;
		virtual HPen createPen (HCanvas const& canvas) = 0;
	};
}