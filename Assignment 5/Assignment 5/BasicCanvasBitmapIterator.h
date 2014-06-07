//
//  BasicCanvasBitmapIterator.h
//  Assignment 5
//
//  Created by Steve Minor on 6/6/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#pragma once

#include "IBitmapIterator.h"
#include "BasicCanvas.h"

namespace Framework{
	class BasicCanvasBitmapIterator: public BitmapGraphics::IBitmapIterator{
	public:
		BasicCanvasBitmapIterator(const BasicCanvas& _canvas);
		
		void nextScanLine();
		bool isEndOfImage() const;
		void nextPixel();
		bool isEndOfScanLine() const;
		BitmapGraphics::Color getColor() const;

		int getBitmapWidth() const;
		int getBitmapHeight() const;
	private:
		const BasicCanvas& canvas;
		
		int width;
		int height;
		int xIndex;
		int yIndex;
	};
}
