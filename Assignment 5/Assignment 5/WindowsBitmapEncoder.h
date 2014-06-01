#pragma once

#include "IBitmapEncoder.h"
#include "WindowsBitmapCommon.h"
#include "WindowsBitmapHeader.h"
#include "Bitmap.h"

namespace BitmapGraphics{
	class WindowsBitmapEncoder: public IBitmapEncoder{
	public:
		WindowsBitmapEncoder();
		
		HBitmapEncoder clone(HBitmapIterator& bitmapIter);
		void encodeToStream(std::ostream& destinationStream);
		std::string getMimeType() const;
	private:
		//need to verify this before writing encodeToStream;
		HBitmapIterator myIterator;
		WindowsBitmapEncoder(HBitmapIterator& bitmapIterator);
	};
}
