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
#include "Parse.h"

namespace VG{
	class XMLStreamer{
	public:
		static std::string getNextToken(std::stringstream& xmlStream);
	};
}

#endif /* defined(__Assignment_1__XMLStreamer__) */
