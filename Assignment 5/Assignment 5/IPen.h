#pragma once

namespace Framework{
	class IPen
	{
	public:
		virtual void drawPoint(Point const& point) = 0;
	};
}