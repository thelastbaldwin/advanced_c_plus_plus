//
//  XMLStreamer.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//
#include "XMLStreamer.h"

#define STR(s) #s

std::string VG::XMLStreamer::getNextToken(std::iostream& xmlStream){
	std::string token;
	
	std::getline(xmlStream, token, '>');
	Parse::trim(token, " \t\n<");
	
	return token;
}

std::string VG::XMLStreamer::getTagName(const std::string &tag) {
	std::regex firstWordRegex("\\w+");
	std::smatch firstWordMatch;
	//returns bool
	bool found = std::regex_search(tag, firstWordMatch, firstWordRegex);
	if (found){
		return firstWordMatch.str();
	}
	//throw exception
	throw std::invalid_argument("Tag does not contain a name.");
}

std::map<std::string, std::string> VG::XMLStreamer::getAttributes(std::string tag){
	using namespace std;
	typedef pair<string, string> keyValue;

	regex attributeRegex("([a-zA-Z09-_]+)=\"([a-zA-Z0-9-_\\s]+)\"");
	smatch attributeMatch;
	map<string, string> attributes;

	while(regex_search(tag, attributeMatch,
					   attributeRegex)){
		attributes.insert(keyValue(attributeMatch[1], attributeMatch[2]));
		tag.erase(tag.find(attributeMatch.str()), attributeMatch.str().length());
	}
	
	return attributes;
}

bool VG::XMLStreamer::isValid(const std::string &tag) {
	// optional opening or closing /
	// mandatory name
	// optional list of attributes
	std::regex XMLRegex("\\/?(\\w+)\\s?((?:\\w+=\"[\\s\\w-]+\"\\s?)+)?\\/?");
	
	return std::regex_match(tag, XMLRegex);
}

bool VG::XMLStreamer::isComment(const std::string &tag){
	std::regex commentRegex("^!--[\\s\\w!.,]+--$");
	
	return std::regex_match(tag, commentRegex);
}

bool VG::XMLStreamer::isClosingTag(const std::string &tag){
	if(!tag.empty()){
		return tag.front() == '/';
	}
	return false;
}

bool VG::XMLStreamer::isSelfClosingTag(const std::string &tag){
	if(!tag.empty()){
		return tag.back() == '/';
	}
	return false;
}

VG::XMLNode VG::XMLStreamer::parseXml(std::iostream &xmlStream){
	std::stack<std::shared_ptr<XMLNode>> openTags;
	std::shared_ptr<XMLNode> topLevelElement;
	std::shared_ptr<XMLNode> currentElement;
	std::string currentElementString = XMLStreamer::getNextToken(xmlStream);
	std::string currentTagName;
	std::map<std::string, std::string> currentTagAttributes;
	
	do{
		if (isComment(currentElementString)) {
			// cannot persist comments between saves
			currentElementString = XMLStreamer::getNextToken(xmlStream);
			continue;
		}
		
		bool isClosingTag = XMLStreamer::isClosingTag(currentElementString);
		bool isSelfClosingTag = XMLStreamer::isSelfClosingTag(currentElementString);
		bool isOpenTag = !isClosingTag && !isSelfClosingTag;
		
		if (!isValid(currentElementString)) {
			throw std::invalid_argument("Invalid tag encountered: " + currentElementString);
		}
		else if (isOpenTag){
			currentTagName = getTagName(currentElementString);
			currentTagAttributes = getAttributes(currentElementString);
			if (openTags.empty()){
				//this is the top level element condition
				topLevelElement = std::make_shared<XMLNode>(XMLNode(currentTagName, currentTagAttributes));
				openTags.push(topLevelElement);
			}else{
				currentElement = std::make_shared<XMLNode>(XMLNode(currentTagName, currentTagAttributes, openTags.top()));
				openTags.push(currentElement);
			}
		
		}
		else if (isClosingTag) {
			if (openTags.empty()) {
				throw std::invalid_argument("Mismatched tags in source");
			}
			else if (getTagName(currentElementString) == openTags.top()->getName()){
				openTags.pop();
				
			}else{
				throw std::invalid_argument("Mismatched tags in source");
			}
		
		}
		else if (isSelfClosingTag) {
			currentTagName = getTagName(currentElementString);
			currentTagAttributes = getAttributes(currentElementString);
			
			if (openTags.empty()) {
				//edge case of self closing tag without parent. Assume top level element
				topLevelElement = std::make_shared<XMLNode>(XMLNode(currentTagName, currentTagAttributes));
			}else{
				currentElement = std::make_shared<XMLNode>(XMLNode(currentTagName, currentTagAttributes, openTags.top()));
			}
		
		}
		currentElementString = XMLStreamer::getNextToken(xmlStream);		
	}
	while (currentElementString != "");
	
	if (!openTags.empty()) {
		throw std::invalid_argument("Mismatched tags in source");
	}
	
	return *topLevelElement;
}
