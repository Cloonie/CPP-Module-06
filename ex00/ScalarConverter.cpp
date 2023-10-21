#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &ref) {
	*this = ref;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter &ref) {
	(void)ref;
	return (*this);
}

void	ScalarConverter::convert(const std::string& input)
{
	char charValue = toChar(input);
	int intValue = toInt(input);
	float floatValue = toFloat(input);
	double doubleValue = toDouble(input);

	if (charValue == '0')
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << charValue << "'" << std::endl;
	
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << getFloatString(floatValue) << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
}

char ScalarConverter::toChar(const std::string& input) 
{
	if (input.length() == 1) {
		return input[0];
	}
	return (0);
}

int	ScalarConverter::toInt(const std::string& input)
{
	return atoi(input.c_str());
}

float	ScalarConverter::toFloat(const std::string& input)
{
	return strtof(input.c_str(), NULL);
}

double	ScalarConverter::toDouble(const std::string& input)
{
	return strtod(input.c_str(), NULL);
}

std::string ScalarConverter::getFloatString(float value) {
	if (std::isnan(value)) {
		return "nanf";
	} else if (std::isinf(value)) {
		return (value < 0) ? "-inff" : "+inff";
	} else {
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1ff", value);
		return buffer;
	}
}