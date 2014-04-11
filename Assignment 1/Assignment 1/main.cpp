//
//  main.cpp
//  Assignment 1
//
//  Created by Steve Minor on 4/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#include "TestHarness.h"
#include <iostream>

int main(int argc, const char * argv[])
{

	TestResult tr;
    TestRegistry::runAllTests(tr);
    return 0;
}

