//
//  Point.h
//  Assignment 1
//
//  Created by Steve Minor on 4/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_1__Point__
#define __Assignment_1__Point__

#include "XMLNode.h"
#include <iostream>
#include <sstream>

namespace VG{
	class Point{
	public:
		Point(int _x, int _y);
		Point(const Point& other);
		
		Point& operator=(const Point& rhs);
		
		bool operator==(const Point& rhs);
		bool operator!=(const Point& rhs);
		
		int getX() const;
		int getY() const;
		
		void setX(int _x);
		void setY(int _y);
		
		static std::ostream& toXML(std::ostream& os, const Point& point);
	private:
		int x, y;
	};
}

#endif /* defined(__Assignment_1__Point__) */
