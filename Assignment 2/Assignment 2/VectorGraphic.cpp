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

VG::iXML& VG::VectorGraphic::fromXML(const std::shared_ptr<XMLNode> element){
	std::stringstream ss;
	std::string name;
	bool closed;	
	
	ss << element->getName();
	ss >> name;
	ss.clear();
	ss.str("");
	
	if(name != "VectorGraphic"){
		std::invalid_argument("Top level element is not VectorGraphic");
	}
	
	ss << std::boolalpha << element->getAttribute("closed");
	ss >> closed;
	if (closed) {
		closeShape();
	}else{
		openShape();
	}
	ss.clear();
	ss.str("");
	
	myPath.clear();
	auto children = element->getAllChildren();
	for(auto iter = children.begin(); iter != children.end(); ++iter){
		Point p;
		p.fromXML(*iter);
		addPoint(p);
	}
	
	return *this;
}

std::ostream& VG::VectorGraphic::toXML(std::ostream& os){
	os << "<VectorGraphic " << ((isClosed()) ? "closed=\"true\"" : "") << ">" << std::endl;
	for(auto iter=myPath.begin(); iter != myPath.end(); ++iter){
		os << "\t";
		iter->toXML(os);
	}
	os << "</VectorGraphic>" << std::endl;
	return os;
}