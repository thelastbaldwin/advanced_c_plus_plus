#pragma once
#include "ICanvas.h"

namespace Framework{
	class IProjector
	{
	public:
		virtual void projectCanvas (const ICanvas& canvas) = 0;
	};
}

