//
//  VectorGraphic.h
//  Assignment 1
//
//  Created by Steve Minor on 4/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_1__VectorGraphic__
#define __Assignment_1__VectorGraphic__

#include "Point.h"
#include <vector>

typedef std::vector<VG::Point> Points;

namespace VG{
	class VectorGraphic
	{
	public:
		VectorGraphic();
		~VectorGraphic();
		
		void addPoint(const Point& p);
		void removePoint(const Point& p);
		void erasePoint(int index);
		
		void openShape();
		void closeShape();
		
		bool isOpen() const;
		bool isClosed() const;
		
		int getWidth() const;
		int getHeight() const;
		
		int getPointCount() const;
		Point getPoint(int index) const;
		
	private:
		Points myPath;
	};
}

#endif /* defined(__Assignment_1__VectorGraphic__) */
