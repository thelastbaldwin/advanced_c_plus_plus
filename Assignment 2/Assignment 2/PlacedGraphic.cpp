//
//  PlacedGraphic.cpp
//  Assignment 2
//
//  Created by Steve Minor on 4/19/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "PlacedGraphic.h"

VG::PlacedGraphic::PlacedGraphic(){};

VG::PlacedGraphic::PlacedGraphic(const XMLNode& element){
	this->fromXML(element);
};

void VG::PlacedGraphic::setPlacementPoint(const VG::Point &placement){
	placementPoint = placement;
}

const VG::Point& VG::PlacedGraphic::getPlacementPoint() const{
	return placementPoint;
}

void VG::PlacedGraphic::setGraphic(const VG::VectorGraphic& vg){
	graphic = vg;
}

std::ostream& VG::PlacedGraphic::toXML(std::ostream &os){
	os << "<PlacedGraphic x=\"" << placementPoint.getX()
	<< "\" y=\"" << placementPoint.getY() << "\">" << std::endl;
	return os;
}

VG::iXML& VG::PlacedGraphic::fromXML(const VG::XMLNode &element){
	std::stringstream ss;
	int x, y;
	ss << element.getAttribute("x");
	ss >> x;
	ss.str("");
	ss.clear();
	
	ss << element.getAttribute("y");
	ss >> y;
	ss.str("");
	ss.clear();
	
	placementPoint.setX(x);
	placementPoint.setY(y);
	
	std::vector<VG::XMLNode> children = element.getAllChildren();
	// this feels a little dirty, but each placedGraphic should
	// only have a single child element
	graphic.fromXML(children[0]);
	
	return *this;
}
