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

VG::Scene::Scene():width(0), height(0){
	checkBounds();
};

VG::Scene::Scene(const std::shared_ptr<VG::XMLNode> element){
	this->fromXML(element);
	checkBounds();
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

void VG::Scene::checkBounds(){
	std::for_each(layers.begin(), layers.end(), [&](VG::Layer layer){
		std::pair<int, int> layerBounds = layer.getBounds();
		if( layerBounds.first > getWidth() || layerBounds.second > getHeight()){
			throw std::out_of_range("Layers within scene exceed bounds");
		}
	});
}