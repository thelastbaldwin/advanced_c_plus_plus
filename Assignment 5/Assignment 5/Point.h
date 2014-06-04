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
#include "iXML.h"
#include <iostream>
#include <sstream>

namespace VG{
	class Point: public iXML{
	public:
		Point();
		Point(int _x, int _y);
		Point(const Point& other);
		
		Point& operator=(const Point& rhs);
		
		bool operator==(const Point& rhs);
		bool operator!=(const Point& rhs);
		
		bool operator<(const Point& rhs) const;
		bool operator>(const Point& rhs) const;
		
		int getX() const;
		int getY() const;
		
		void setX(int _x);
		void setY(int _y);
		
		iXML& fromXML(const std::shared_ptr<XMLNode> element);
        std::ostream& toXML(std::ostream& os);
	private:
		int x, y;
	};
}

#endif /* defined(__Assignment_1__Point__) */
