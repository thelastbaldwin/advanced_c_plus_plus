//
//  XMLStreamer.h
//  Assignment 1
//
//  Created by Steve Minor on 4/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_1__XMLStreamer__
#define __Assignment_1__XMLStreamer__

#include <iostream>
#include <regex>
#include <stack>
#include "Parse.h"
#include "XMLNode.h"
#include <exception>

namespace VG{
	class XMLStreamer{
	public:
		static std::string getNextToken(std::stringstream& xmlStream);
		static std::string getTagName(const std::string& tag);
		static std::map<std::string, std::string> getAttributes(std::string tag);
		static bool isValid(const std::string& tag);
		static bool isComment(const std::string& tag); //need for assignment 2
		static bool isClosingTag(const std::string& tag);
		static bool isSelfClosingTag(const std::string& tag);
		static std::shared_ptr<XMLNode> parseXml(std::stringstream& xmlStream); //returns parent node
	};
}

#endif /* defined(__Assignment_1__XMLStreamer__) */
