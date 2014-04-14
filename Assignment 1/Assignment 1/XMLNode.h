//
//  XMLNode.h
//  Assignment 1
//
//  Created by Steve Minor on 4/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_1__XMLNode__
#define __Assignment_1__XMLNode__

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <memory>

namespace VG{
	// Always initialize using new and a shared pointer
	class XMLNode{
	public:
		XMLNode(std::string _name, std::shared_ptr<VG::XMLNode> _parent = NULL);
		XMLNode(std::string _name, std::map<std::string, std::string> _attributes, std::shared_ptr<XMLNode> = NULL);
		bool hasChildren();
		void setAttributes(std::map<std::string, std::string>& attr);
		std::string getName() const;
		std::string getAttribute(std::string key) const;
		std::vector<XMLNode> getAllChildren() const;
		std::shared_ptr<XMLNode> getParent() const;
		bool operator==(const XMLNode& rhs);
		bool operator!=(const XMLNode& rhs);
	private:
		std::string name;
		std::map<std::string, std::string> attributes;
		std::vector<XMLNode> children;
		std::shared_ptr<XMLNode> parent;
		void addChild(XMLNode& child);
	};
}

#endif /* defined(__Assignment_1__XMLNode__) */
