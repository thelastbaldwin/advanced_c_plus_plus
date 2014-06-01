//
//  RangedNumber.h
//  Assignment 4
//
//  Created by Steve Minor on 5/20/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#pragma once

#include "Byte.h"
#include <iostream>

template <typename Number, Number lowerLimit, Number upperLimit>
class ranged_number {
public:
	ranged_number(const Number n=0):number(n){
		checkBounds();
	};
	
	ranged_number(const ranged_number& other):number(other.number){
		checkBounds();
	};
	
	template <typename otherNumber>
	ranged_number& operator=(const otherNumber& other){
		number = other;
		checkBounds();
		return *this;
	}
	
	operator Number(){ checkBounds(); return number;}
	
	operator Binary::Byte(){ checkBounds(); return Binary::Byte(number);}
	
	ranged_number& operator=(const Number& other){
		number = other;
		checkBounds();
		return *this;
	}

	ranged_number& operator+=(const Number& rhs){
		number += rhs;
		checkBounds();
		return *this;
	}
	
	ranged_number& operator-=(const Number& rhs){
		number -= rhs;
		checkBounds();
		return *this;
	}
	
	ranged_number& operator++(){ number++; checkBounds(); return *this;}; //prefix (++Circle)
	
	//postfix
	ranged_number operator++(int){
		ranged_number oldValue = *this;
		number++;
		checkBounds();
		return oldValue;
	};
	
	ranged_number& operator--(){ number--; checkBounds(); return *this;}; //prefix (--Circle)
	
	//postfix
	ranged_number operator--(int){
		ranged_number oldValue = *this;
		number--;
		checkBounds();
		return oldValue;
	};
	
	Number getNumber() const{
		return number;
	}
		
private:
	void checkBounds(){
		if (number > upperLimit) {
			number = upperLimit;
		} else if (number < lowerLimit) {
			number = lowerLimit;
		}
	};
	Number number;
};

template <class Number, Number lowerLimit, Number upperLimit>
std::ostream& operator<<(std::ostream& os, const ranged_number<Number, lowerLimit, upperLimit>& rhs){
	os << rhs.getNumber();
	return os;
}
