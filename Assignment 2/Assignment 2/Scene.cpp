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

//Still need to write this!
VG::iXML& VG::Scene::fromXML(const std::shared_ptr<XMLNode> element){
	return *this;
}