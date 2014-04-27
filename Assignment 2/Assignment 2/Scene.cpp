//
//  Scene.cpp
//  Assignment 2
//
//  Created by Steve Minor on 4/19/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "Scene.h"

void VG::Scene::addLayer(const VG::Layer &l){
	layers.push_back(l);
}

VG::Scene::Scene():width(0), height(0){};

VG::Scene::Scene(const std::shared_ptr<VG::XMLNode> element){
	this->fromXML(element);
}

std::ostream& VG::Scene::toXML(std::ostream &os){
	return os;
}

VG::iXML& VG::Scene::fromXML(const std::shared_ptr<XMLNode> element){
	std::stringstream ss;
	int widthAttribute, heightAttribute;
	
	ss << element->getAttribute("width");
	ss >> widthAttribute;
	width = widthAttribute;
	
	ss.str("");
	ss.clear();
	
	ss << element->getAttribute("height");
	ss >> heightAttribute;
	height = heightAttribute;
	
	auto layerElements = element->getAllChildren();
	
	for (auto layer: layerElements){
		layers.push_back(Layer(layer));
	}	
	return *this;
}

bool VG::Scene::checkBounds(){
	//get all layers
	//get all placedGraphics
	//get all vectorGraphics
	//determine highest and lowest x and y coordinates
	//if x is <= width and y <= height, return true.
	//otherwise false
	return true;
}