//
//  Parse.h
//  Assignment 1
//
//  Created by Steve Minor on 4/10/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_1__Parse__
#define __Assignment_1__Parse__

#include <iostream>
#include <string>
#include <sstream>

namespace Parse{
	std::stringstream& eat(std::stringstream& ss, std::string edibles);
	std::string trim(const std::string& input, std::string trimables);
}

#endif /* defined(__Assignment_1__Parse__) */
