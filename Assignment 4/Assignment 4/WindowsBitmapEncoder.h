#pragma once

#include "IBitmapEncoder.h"
#include "WindowsBitmapCommon.h"
#include "Bitmap.h"

namespace BitmapGraphics{
	class WindowsBitmapEncoder: public IBitmapEncoder{
	public:
		WindowsBitmapEncoder();
		
		HBitmapEncoder clone(HBitmapIterator& bitmapIter);
		void encodeToStream(std::ostream& sourceStream);
		std::string getMimeType() const;
	private:
		WindowsBitmapEncoder(HBitmapIterator& bitmapIterator);
		HBitmap myBitmap;
	};
}
