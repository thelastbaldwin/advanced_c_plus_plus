//
//  main.cpp
//  Assignment 2
//
//  Created by Steve Minor on 4/19/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "TestHarness.h"
#include <iostream>

//stringification
#define STR(s) #s

int main(int argc, const char * argv[])
{
	
	TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}

