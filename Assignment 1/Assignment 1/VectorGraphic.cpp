//
//  VectorGraphic.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "VectorGraphic.h"

void VG::VectorGraphic::addPoint(const Point &p){
	myPath.push_back(p);
}

void VG::VectorGraphic::removePoint(const Point &p){
	auto foundPoint = std::find(myPath.begin(), myPath.end(), p);
	
	if(foundPoint != myPath.end()){
		myPath.erase(foundPoint);
	}	
}

void VG::VectorGraphic::erasePoint(int index){
	myPath.erase(myPath.begin() + index);
}

void VG::VectorGraphic::openShape(){
	if(closed){
		closed = !closed;
	}
}

void VG::VectorGraphic::closeShape(){
	if(!closed){
		closed = !closed;
	}
}

bool VG::VectorGraphic::isOpen() const{
	return !closed;
}

bool VG::VectorGraphic::isClosed() const{
	return !isOpen();
}

int VG::VectorGraphic::getWidth() const{
	int width = 0;
	
	if(myPath.size() > 1){
		auto max = std::max_element(myPath.begin(), myPath.end(),
			[](const VG::Point& lhs, const VG::Point& rhs){
				return lhs.getX() < rhs.getX();
			});
		auto min = std::max_element(myPath.begin(), myPath.end(),
			[](const VG::Point& lhs, const VG::Point& rhs){
				return lhs.getX() > rhs.getX();
			});

		width = max->getX() - min->getX();
	}
	
	return width;
}

int VG::VectorGraphic::getHeight() const{
	int height = 0;
	
	if(myPath.size() > 1){
		auto max = std::max_element(myPath.begin(), myPath.end(),
			[](const VG::Point& lhs, const VG::Point& rhs){
				return lhs.getY() < rhs.getY();
			});
		auto min = std::max_element(myPath.begin(), myPath.end(),
			[](const VG::Point& lhs, const VG::Point& rhs){
				return lhs.getY() > rhs.getY();
			});
		
		height = max->getY() - min->getY();
	}
	
	return height;
}

int VG::VectorGraphic::getPointCount() const{
	return int(myPath.size());
}

VG::Point VG::VectorGraphic::getPoint(int index) const{
	return myPath[index];
}

VG::VectorGraphic VG::VectorGraphic::fromXML(std::shared_ptr<XMLNode> topLevelElement){
	VectorGraphic vg;
	std::stringstream ss;
	std::string name;
	bool closed;	
	
	ss << topLevelElement->getName();
	ss >> name;
	ss.clear();
	ss.str("");
	
	if(name != "VectorGraphic"){
		std::invalid_argument("Top level element is not VectorGraphic");
	}
	
	ss << topLevelElement->getAttribute("closed");
	ss >> closed;
	if (closed) {
		vg.closeShape();
	}
	ss.clear();
	ss.str("");
	
	auto children = topLevelElement->getAllChildren();
	for(auto iter = children.begin(); iter != children.end(); ++iter){
		//running into error converting string to int!
		int x, y;
		std::string xString = iter->getAttribute("x");
		
		ss.clear();
		ss.str("");
		ss << xString;
		ss >> x;
		
		ss.clear();
		ss.str("");
		ss << iter->getAttribute("y");
		ss >> y;
		vg.addPoint(Point(x, y));
	}
	
	return vg;
}