//
//  Layer.cpp
//  Assignment 2
//
//  Created by Steve Minor on 4/19/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "Layer.h"

VG::Layer::Layer():alias(""){};
VG::Layer::Layer(const XMLNode& element){
	this->fromXML(element);
};
VG::Layer::Layer(std::string _alias):alias(_alias){};

void VG::Layer::addPlacedGraphic(const VG::PlacedGraphic &pg){
	graphics.push_back(pg);
}

std::list<VG::PlacedGraphic> VG::Layer::getPlacedGraphics(){
	return graphics;
}

std::string VG::Layer::getAlias(){
	return alias;
}

std::ostream& VG::Layer::toXML(std::ostream& os){
	os << "<Layer alias=\"" << getAlias() << "\">" << std::endl;
	
	for(auto iter: graphics){
		os << "\t";
		iter.toXML(os);
	}
	
	return os;
}

VG::iXML& VG::Layer::fromXML(const VG::XMLNode &element){
	alias = element.getAttribute("alias");
	std::vector<XMLNode> children = element.getAllChildren();
	
	for(auto iter: children){
		PlacedGraphic pg(iter);
		addPlacedGraphic(pg);
	}
	return *this;
}