#include "Parse.h"

void Parse::eat(std::stringstream& ss, std::string edibles){
	while(edibles.find(ss.peek()) != std::string::npos){
		ss.ignore();
	}
};

void Parse::trim(std::string& input, std::string trimables){
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
	
	input = input.substr(frontPos, backPos - frontPos + 1);
};

