//
//  XMLStreamer.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//
#include "XMLStreamer.h"

#define STR(s) #s

std::string VG::XMLStreamer::getNextToken(std::stringstream& xmlStream){
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
	throw std::invalid_argument("Unable to find first word.");
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

bool VG::XMLStreamer::isValid(const std::string &tag) {
	// optional opening or closing /
	// mandatory name
	// optional list of attributes
	std::regex XMLRegex("\\/?(\\w+)\\s?((?:\\w+=\"[\\s\\w]+\"\\s?)+)?\\/?");
	
	return std::regex_match(tag, XMLRegex);
}

bool VG::XMLStreamer::isComment(const std::string &tag){
	std::regex commentRegex("^!--[\\s\\w!.,]+--$");
	
	return std::regex_match(tag, commentRegex);
}