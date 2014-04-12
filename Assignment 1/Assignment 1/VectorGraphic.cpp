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
	myPath.erase(std::remove(myPath.begin(), myPath.end(), index));
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
	return 0;
}

int VG::VectorGraphic::getHeight() const{
	return 0;
}

int VG::VectorGraphic::getPointCount() const{
	return int(myPath.size());
}

VG::Point VG::VectorGraphic::getPoint(int index) const{
	return myPath[index];
}