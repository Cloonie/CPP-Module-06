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

bool	isAllNum(const std::string& str)
{
	for (int i = 0; str[i]; i++)
	{
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != 'f')
			return false;
	}
	return true;
}

void	ScalarConverter::convert(const std::string& input)
{
	int	num = static_cast<int>(atoi(input.c_str()));

	if (isAllNum(input) && (!num || (num < 32 || num > 126)))
		std::cout << "char: Non displayable" << std::endl;
	else if (isAllNum(input) && num && num >= 32 && num <= 126)
		std::cout << "char: '" << static_cast<char>(num) << "'" << std::endl;
	else if (input.length() == 1)
		std::cout << "char: '" << input[0] << "'" << std::endl;
	else
		std::cout << "char: impossible" << std::endl;

	std::cout << "int: " << toInt(input) << std::endl;
	std::cout << "float: " << toFloat(input) << std::endl;
	std::cout << "double: " << toDouble(input) << std::endl;
}


std::string	ScalarConverter::toInt(const std::string& input)
{
	int	actualType = static_cast<int>(atoi(input.c_str()));
	char ascii = static_cast<char>(input[0]);

	if (actualType == 0 && input[0] == '0')
		return "0";
	else if (input.length() == 1 && (ascii < 48 || ascii > 57))
	{
		int ascii_dec = ascii;
		std::stringstream ss;
		ss << ascii_dec;
		return ss.str();
	}
	else if (input.length() == 1 && (actualType >= 32 && actualType <= 126))
	{
		int ascii = static_cast<int>(input[0]);
		std::stringstream ss;
		ss << ascii;
		return	ss.str();
	}
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
	float actualType = static_cast<float>(strtof(input.c_str(), NULL));
	char ascii = static_cast<char>(input[0]);

	if (std::isnan(actualType))
		return "nanf";
	else if (std::isinf(actualType))
		return (actualType < 0) ? "-inff" : "+inff";
	else if (input.length() == 1 && (ascii < 48 || ascii > 57))
	{
		float ascii_dec = ascii;
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1ff", ascii_dec);
		return buffer;
	}
	else if (actualType && (actualType >= 32 && actualType <= 126))
	{
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1ff", actualType);
		return buffer;
	}
	else
	{
		for (int i = 0; input[i]; i++)
			if (!isdigit(input[i]) && input[i] != '.'
				&& input[i] != '-' && input[i] != '+'
				&& input[input.length() - 1] != 'f')
				return "impossible";
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1ff", actualType);
		return buffer;
	}
}

std::string	ScalarConverter::toDouble(const std::string& input)
{
	double actualType = static_cast<double>(strtod(input.c_str(), NULL));
	char ascii = static_cast<char>(input[0]);

	if (std::isnan(actualType))
		return "nan";
	else if (std::isinf(actualType))
		return (actualType < 0) ? "-inf" : "+inf";
	else if (input.length() == 1 && (ascii < 48 || ascii > 57))
	{
		double ascii_dec = ascii;
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1f", ascii_dec);
		return buffer;
	}
	else if (input.length() == 1 && (actualType >= 32 && actualType <= 126))
	{
		double ascii = static_cast<double>(input[0]);
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1f", ascii);
		return buffer;
	}
	else
	{
		for (int i = 0; input[i]; i++)
			if (!isdigit(input[i]) && input[i] != '.'
				&& input[i] != '-' && input[i] != '+'
				&& input[input.length() - 1] != 'f')
				return "impossible";
		char buffer[32];
		snprintf(buffer, sizeof(buffer), "%.1f", actualType);
		return buffer;
	}
}
