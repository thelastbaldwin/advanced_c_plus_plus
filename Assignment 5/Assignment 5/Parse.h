#pragma once

#include <iostream>
#include <string>
#include <sstream>

namespace Parse{
	void eat(std::stringstream& ss, std::string edibles);
	void trim(std::string& input, std::string trimables);
}
