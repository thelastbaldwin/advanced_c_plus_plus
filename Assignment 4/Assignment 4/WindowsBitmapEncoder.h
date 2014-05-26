#pragma once

#include "IBitmapEncoder.h"
#include "Bitmap.h"

namespace BitmapGraphics{
	class WindowsBitmapEncoder: public IBitmapEncoder{
		HBitmapEncoder clone();
		void encodeToStream();
		std::string getMimeType();
	};
}
