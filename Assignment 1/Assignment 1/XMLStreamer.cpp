//
//  XMLStreamer.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/12/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "XMLStreamer.h"

std::string VG::XMLStreamer::getNextToken(std::stringstream& xmlStream){
	std::string token;
	
	std::getline(xmlStream, token, '>');
	Parse::trim(token, " \t\n<>");
	
	return token;
}