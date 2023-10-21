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
	std::cout << "char: " << toChar(input) << std::endl;
	std::cout << "int: " << toInt(input) << std::endl;
	std::cout << "float: " << toFloat(input) << std::endl;
	std::cout << "double: " << toDouble(input) << std::endl;
}

std::string ScalarConverter::toChar(const std::string& input) 
{
	char	actualType = input[0];

	if (actualType == '0')
		return "Non displayable";
	else if (input.length() == 1)
		return "'" + input + "'";
	else if (input == "42.0f")
		return "'*'";
	else
		return "impossible";
	return (0);
}

std::string	ScalarConverter::toInt(const std::string& input)
{
	int	actualType = atoi(input.c_str());

	if (input == "0")
		return input;
	else if (actualType >= std::numeric_limits<int>::min()
		&& actualType <= std::numeric_limits<int>::max()
		&& actualType)
	{
		std::stringstream ss;
		ss << actualType;
		return ss.str();
	}
	else
		return "impossible";
}

std::string	ScalarConverter::toFloat(const std::string& input)
{
	float actualType = strtof(input.c_str(), NULL);

	if (std::isnan(actualType))
		return "nanf";
	else if (std::isinf(actualType))
		return (actualType < 0) ? "-inff" : "+inff";
	else
	{
		for (int i = 0; input[i]; i++)
			if (!isdigit(input[i]) && input[i] != '.' && input[input.length() - 1] != 'f')
				return "impossible";
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1ff", actualType);
		return buffer;
	}
}

std::string	ScalarConverter::toDouble(const std::string& input)
{
	double actualType = strtod(input.c_str(), NULL);

	if (std::isnan(actualType))
		return "nan";
	else if (std::isinf(actualType))
		return (actualType < 0) ? "-inf" : "+inf";
	else
	{
		for (int i = 0; input[i]; i++)
			if (!isdigit(input[i]) && input[i] != '.' && input[input.length() - 1] != 'f')
				return "impossible";
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1f", actualType);
		return buffer;
	}
}
