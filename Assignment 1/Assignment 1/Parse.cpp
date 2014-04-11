//
//  Parse.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/10/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "Parse.h"

std::stringstream& Parse::eat(std::stringstream& ss, std::string edibles){

	while(edibles.find(ss.peek()) != std::string::npos){
		ss.ignore();
	}
	return ss;
};

std::string Parse::trim(const std::string &input, std::string trimables){
	size_t frontPos = 0;
	size_t backPos = input.length()-1;
	
	size_t stringIndex = frontPos;
	while(trimables.find(input[stringIndex]) != std::string::npos){
		++stringIndex;
		frontPos = stringIndex;
	}
	
	stringIndex = backPos;
	while(trimables.find(input[stringIndex]) != std::string::npos){
		--stringIndex;
		backPos = stringIndex;
	}
	
	return input.substr(frontPos, backPos - frontPos + 1);
};

