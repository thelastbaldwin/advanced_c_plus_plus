//
//  VerifyEquality.h
//  Assignment 3
//
//  Created by Steve Minor on 5/8/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#pragma once

#include <iostream>
#include <string>
#include <sstream>

template<typename T>
void verifyEquality(const T& expected, const T& actual, std::string type){
    if (expected != actual){
        std::stringstream ss;
        ss << "Expected " << type << " to equal " << expected << ", but was " << actual;
        throw std::runtime_error(ss.str());
    }
}
