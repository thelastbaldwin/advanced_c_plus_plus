//
//  main.cpp
//  Assignment 5
//
//  Created by Steve Minor on 6/1/14.
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


