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
	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter& operator=(const ScalarConverter &ref);

		static void	convert(const std::string& input);

		static char		toChar(const std::string& input);
		static int		toInt(const std::string& input);
		static float	toFloat(const std::string& input);
		static double	toDouble(const std::string& input);
		static std::string getFloatString(float value);
};
