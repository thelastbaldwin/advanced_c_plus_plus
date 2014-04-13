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
	class XMLNode{
	public:
		XMLNode(std::string _name, XMLNode* _parent = NULL);
		XMLNode(std::string _name, std::map<std::string, std::string> _attributes, XMLNode* _parent = NULL);
		bool hasChildren();
		void setAttributes(std::map<std::string, std::string> attr);
		std::string getName();
		std::string getAttribute(std::string key);
		void close();
	private:
		std::string name;
		std::map<std::string, std::string> attributes;
		std::vector<XMLNode> children;
		std::shared_ptr<XMLNode> parent;
		bool isClosed;
	};
}

#endif /* defined(__Assignment_1__XMLNode__) */
