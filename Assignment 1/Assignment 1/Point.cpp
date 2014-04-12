//
//  Point.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "Point.h"

VG::Point::Point(int _x, int _y):x(_x),y(_y){};
VG::Point::Point(const Point& other):x(other.x), y(other.y){};


VG::Point& VG::Point::operator=(const Point& rhs){
	x = rhs.x;
	y = rhs.y;
	
	return *this;
};

bool VG::Point::operator==(const Point& rhs){
	if(getX() == rhs.getX() && getY() == rhs.getY()){
		return true;
	}
	return false;
};

bool VG::Point::operator!=(const Point& rhs){
	return !operator==(rhs);
};

int VG::Point::getX() const{ return x;}
int VG::Point::getY() const{ return y;}

void VG::Point::setX(int _x){ x = _x;}
void VG::Point::setY(int _y){ y = _y;}
