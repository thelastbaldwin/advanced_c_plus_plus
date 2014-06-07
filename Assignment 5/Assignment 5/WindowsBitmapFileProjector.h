#pragma once

#include "IProjector.h"
#include "BasicCanvasBitmapIterator.h"
#include "CodecLibrary.h"
#include "WindowsBitmapCommon.h"
#include "WindowsBitmapEncoder.h"
#include <string>

namespace Framework{
	class WindowsBitmapFileProjector: public IProjector{
	public:
		//projector must know about the codec library in order to create an encoder from
		//the canvas passed to projectCanvas
		WindowsBitmapFileProjector(std::string _filename, BitmapGraphics::CodecLibrary& _codecLibrary);
		void projectCanvas(const ICanvas& canvas);

	private:
		std::string filename;
		BitmapGraphics::CodecLibrary& codecLibrary;
	};
}
