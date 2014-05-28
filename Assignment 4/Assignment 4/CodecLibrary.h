#pragma once
#include "IBitmapEncoder.h"
#include "IBitmapDecoder.h"
#include <string>
#include <map>

namespace BitmapGraphics
{
    
    class CodecLibrary{
	public:		
		void registerEncoder (HBitmapEncoder const& encoder);
		void registerDecoder (HBitmapDecoder const& decoder);
		
		// provide a mime type version and an
		// auto determination version of createDecoder
		HBitmapDecoder createDecoder (std::istream& sourceStream);
		HBitmapDecoder createDecoder (const std::string& mimeType,
									  std::istream& sourceStream);
		
		HBitmapEncoder createEncoder (const std::string& mimeType,
									  HBitmapIterator& bitmapIterator);
	private:
		
		typedef std::pair<std::string, HBitmapDecoder> decoderPair;
		typedef std::pair<std::string, HBitmapEncoder> encoderPair;
		
		std::map<std::string, HBitmapEncoder> myEncoders;
		std::map<std::string, HBitmapDecoder> myDecoders;
    };
    
}
