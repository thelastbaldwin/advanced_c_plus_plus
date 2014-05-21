//
//  RangedNumber.h
//  Assignment 4
//
//  Created by Steve Minor on 5/20/14.
//  Copyright (c) 2014 Steve Minor. All rights reserved.
//

#ifndef __Assignment_4__RangedNumber__
#define __Assignment_4__RangedNumber__

#include <iostream>

template <class Number, Number lowerLimit, Number upperLimit>
class ranged_number {
public:
	// operators and methods to make the class behave
	// just like an actual number, with the addition of
	// restricting the range	
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
	
	ranged_number& operator=(const Number& other){
		number = other;
		checkBounds();
		return *this;
	}

	friend bool operator ==(const ranged_number<Number, lowerLimit, upperLimit>& lhs, const Number& rhs){ return lhs.getNumber() == rhs; };
	friend bool operator !=(const ranged_number<Number, lowerLimit, upperLimit>& lhs, const Number& rhs){ return lhs.getNumber() != rhs; };
	friend bool operator ==(const Number& lhs, const ranged_number<Number, lowerLimit, upperLimit>& rhs){ return lhs == rhs.getNumber(); };
	friend bool operator !=(const Number& lhs, const ranged_number<Number, lowerLimit, upperLimit>& rhs){ return lhs != rhs.getNumber(); };
	
	ranged_number& operator+(const Number& other){
		number = number + other;
		checkBounds();
		return *this;
	}
	ranged_number& operator-(const Number& other){
		number = number - other;
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
	

#endif /* defined(__Assignment_4__RangedNumber__) */
