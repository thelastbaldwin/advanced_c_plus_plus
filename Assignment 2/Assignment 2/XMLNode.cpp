//
//  XMLNode.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "XMLNode.h"
VG::XMLNode::XMLNode():name(""){}


VG::XMLNode::XMLNode(std::string _name, std::shared_ptr<XMLNode> _parent):
	name(_name),
	parent(_parent){
		if( _parent != NULL){
			_parent->addChild(*this);
		}
	};

VG::XMLNode::XMLNode(std::string _name, std::map<std::string, std::string> _attributes, std::shared_ptr<XMLNode> _parent):
	name(_name),
	attributes(_attributes),
	parent(_parent){
		if( _parent != NULL){
			_parent->addChild(*this);
		}
	};

bool VG::XMLNode::hasChildren(){
	return (children.size() > 0) ? true : false;
}

std::string VG::XMLNode::getName() const{
	return name;
}

void VG::XMLNode::addChild(VG::XMLNode& child) {
	children.push_back(child);
}

std::string VG::XMLNode::getAttribute(std::string key) const{
	auto iter = attributes.find(key);
	
	//contents of end()->second is undefined behavior
	if(iter != attributes.end()){
		return iter->second;
	}
	return std::string("");
}

std::vector<VG::XMLNode> VG::XMLNode::getAllChildren() const{
	return children;
}

std::shared_ptr<VG::XMLNode> VG::XMLNode::getParent() const{
	return parent;
}

bool VG::XMLNode::operator==(const XMLNode& rhs){
	return (getName() == rhs.getName());
}
bool VG::XMLNode::operator!=(const XMLNode& rhs){
	return !operator==(rhs);
};
