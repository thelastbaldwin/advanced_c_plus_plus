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
#include "XMLStreamer.h"
#include <vector>
#include <algorithm>

typedef std::vector<VG::Point> Points;

namespace VG{
	class VectorGraphic
	{
	public:		
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
		
		static VectorGraphic fromXML(std::shared_ptr<XMLNode> topLevelElement);
        static std::ostream& toXML(std::ostream& os, const VectorGraphic& vg);
	private:
		Points myPath;
		bool closed;
	};
}

#endif /* defined(__Assignment_1__VectorGraphic__) */
