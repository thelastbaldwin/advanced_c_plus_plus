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
	class XMLNode {
	public:
		XMLNode();
		XMLNode(std::string _name);
		XMLNode(std::string _name, std::map<std::string, std::string> _attributes);
		bool hasChildren();
		void setAttributes(std::map<std::string, std::string>& attr);
		std::string getName() const;
		std::string getAttribute(std::string key) const;
		const std::map<std::string, std::string>& getAllAttributes() const;
		void addChild(std::shared_ptr<XMLNode> child);
		void addChild(const XMLNode* child);
		const std::vector<std::shared_ptr<XMLNode>>& getAllChildren() const;
		bool operator==(const XMLNode& rhs);
		bool operator!=(const XMLNode& rhs);
	private:
		std::string name;
		std::map<std::string, std::string> attributes;
		std::vector<std::shared_ptr<XMLNode>> children;
	};
	
	typedef std::shared_ptr<XMLNode> HXMLNode;
}

std::ostream& operator<<(std::ostream& os, const VG::XMLNode& xmlNode);

#endif /* defined(__Assignment_1__XMLNode__) */
