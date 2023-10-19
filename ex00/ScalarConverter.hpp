#pragma once

#include <iostream>

static class ScalarConverter
{
	private:

	public:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &ref);
		ScalarConverter& operator=(const ScalarConverter &ref);

		char	toChar();
		int		toInt();
		float	toFloat();
		double	toDouble();
		void	convert(std::string str);
}