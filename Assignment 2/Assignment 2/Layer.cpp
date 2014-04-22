//
//  Layer.cpp
//  Assignment 2
//
//  Created by Steve Minor on 4/19/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "Layer.h"

VG::Layer::Layer():alias(""){};
VG::Layer::Layer(std::string _alias):alias(_alias){};

void VG::Layer::addPlacedGraphic(const VG::PlacedGraphic &pg){
	graphics.push_back(pg);
}