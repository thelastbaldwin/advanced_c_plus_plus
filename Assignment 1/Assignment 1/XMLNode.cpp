//
//  XMLNode.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "XMLNode.h"

VG::XMLNode::XMLNode(std::string _name, XMLNode* _parent):
	name(_name),
	isClosed(false),
	parent(_parent){};

VG::XMLNode::XMLNode(std::string _name, std::map<std::string, std::string> _attributes, XMLNode* _parent):
	name(_name),
	isClosed(false),
	attributes(_attributes),
	parent(_parent){};

bool VG::XMLNode::hasChildren(){
	return (children.size() > 0) ? true : false;
}

std::string VG::XMLNode::getName(){
	return name;
}

std::string VG::XMLNode::getAttribute(std::string key){
	return attributes.find(key)->second;
}

void VG::XMLNode::close(){
	isClosed = true;
}
