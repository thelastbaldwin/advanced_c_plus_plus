#pragma once
#include "IBitmapEncoder.h"
#include "IBitmapDecoder.h"

namespace BitmapGraphics
{
    
    class CodecLibrary{
		void registerEncoder (HBitmapEncoder const& decoder);
		void registerDecoder (HBitmapDecoder const& decoder);
		
		// provide a mime type version and an
		// auto determination version of createDecoder
		HBitmapDecoder createDecoder (std::istream& sourceStream);
		HBitmapDecoder createDecoder (std::string const& mimeType,
									  std::istream& sourceStream);
		
		HBitmapEncoder createEncoder (std::string const& mimeType,
									  HBitmapIterator const& bitmapIterator);
    };
    
}
