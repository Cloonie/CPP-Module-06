#pragma once

#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <cmath>
#include <cstdlib>
#include <string>
#include <cstdio>

class ScalarConverter
{
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter& operator=(const ScalarConverter &ref);
	public:
		static void	convert(const std::string& input);
		static std::string	toChar(const std::string& input);
		static std::string	toInt(const std::string& input);
		static std::string	toFloat(const std::string& input);
		static std::string	toDouble(const std::string& input);
		static std::string	getFloatString(float value);
};
