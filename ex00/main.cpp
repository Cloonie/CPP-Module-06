#include "ScalarConverter.hpp"

int	main(int argc, char **argv)
{	
	if (argc != 2)
	{
		std::cerr << "Error: Please input one argument" << std::endl;
		return 0;
	}
	ScalarConverter::convert(argv[1]);
}