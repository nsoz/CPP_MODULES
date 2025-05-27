#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "use it like: ./convert yourValue" << std::endl;
	}
	else
	{
		ScalarConverter::checkValue(av[1]);
		ScalarConverter::convert(av[1]);
	}
	return (0);
}
