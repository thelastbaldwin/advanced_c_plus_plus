#include "CodecLibrary.h"

namespace BitmapGraphics{
	void CodecLibrary::registerEncoder(const HBitmapEncoder &encoder){
		myEncoders.insert(encoderPair(encoder->getMimeType(), encoder));
	}
	
	void CodecLibrary::registerDecoder(const HBitmapDecoder &decoder){
		myDecoders.insert(decoderPair(decoder->getMimeType(), decoder));
	}
	
	HBitmapDecoder CodecLibrary::createDecoder(const std::string& mimeType,
											   std::istream& sourceStream)
	{
		auto iter = myDecoders.find(mimeType);
		if (iter == myDecoders.end())
		{
			throw std::runtime_error("Decoder type has not been registered");
		}
		return iter->second->clone(sourceStream);
	}
	
	HBitmapDecoder CodecLibrary::createDecoder(std::istream& sourceStream){
		char str[100];
		sourceStream.getline(str, 100);
		std::string firstChunk(str);
		for(auto pair : myDecoders)
		{
			if (pair.second->isSupported(firstChunk))
			{
				sourceStream.clear();
				sourceStream.seekg(0);
				return createDecoder(pair.first, sourceStream);
			}
		}
		
		throw std::runtime_error("No matching decder found");
	}
	
	HBitmapEncoder CodecLibrary::createEncoder(const std::string& mimeType, HBitmapIterator& bitmapIterator){
		auto iter = myEncoders.find(mimeType);
		if (iter == myEncoders.end())
		{
			throw std::runtime_error("Encoder type has not been registered");
		}
		return iter->second->clone(bitmapIterator);
	}
}