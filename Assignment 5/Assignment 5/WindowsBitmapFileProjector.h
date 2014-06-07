#pragma once

#include "IProjector.h"
#include "ICanvas.h"
#include "CodecLibrary.h"
#include <string>

namespace Framework{
	class WindowsBitmapFileProjector: public IProjector{
	public:
		//projector must know about the codec library in order to create an encoder from
		//the canvas passed to projectCanvas
		WindowsBitmapFileProjector(std::string filename, BitmapGraphics::CodecLibrary& _codecLibrary);
		void projectCanvas(const ICanvas& canvas);
	};
}
