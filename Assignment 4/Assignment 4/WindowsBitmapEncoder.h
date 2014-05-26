#pragma once

#include "IBitmapEncoder.h"
#include "WindowsBitmapCommon.h"
#include "Bitmap.h"

namespace BitmapGraphics{
	class WindowsBitmapEncoder: public IBitmapEncoder{
		HBitmapEncoder clone(std::istream& sourceStream);
		void encodeToStream();
		std::string getMimeType() const;
	};
}
