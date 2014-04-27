//
//  XMLNode.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "XMLNode.h"
VG::XMLNode::XMLNode():name(""){}


VG::XMLNode::XMLNode(std::string _name):
	name(_name){};

VG::XMLNode::XMLNode(std::string _name, std::map<std::string, std::string> _attributes):
	name(_name),
	attributes(_attributes){};

bool VG::XMLNode::hasChildren(){
	return (children.size() > 0) ? true : false;
}

std::string VG::XMLNode::getName() const{
	return name;
}

void VG::XMLNode::addChild(std::shared_ptr<XMLNode> child) {
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

const std::map<std::string, std::string>& VG::XMLNode::getAllAttributes() const{
	return attributes;
}

const std::vector<std::shared_ptr<VG::XMLNode>>& VG::XMLNode::getAllChildren() const{
	return children;
}

bool VG::XMLNode::operator==(const XMLNode& rhs){
	return (getName() == rhs.getName());
}
bool VG::XMLNode::operator!=(const XMLNode& rhs){
	return !operator==(rhs);
};

std::ostream& operator<<(std::ostream& os, const VG::XMLNode& xmlNode){
	os << "<" << xmlNode.getName() << " ";
	
	for (auto attribute: xmlNode.getAllAttributes()){
		os << attribute.first << "=\"" << attribute.second << "\" ";
	}
	
	os << ">" << std::endl;
	
	for (auto child: xmlNode.getAllChildren()){
		os << *child;
	}
	
	os << "</" << xmlNode.getName() << " >" << std::endl;
	return os;
};
