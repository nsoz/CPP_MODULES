#include "Harl.hpp"

void	please_shut_up(Harl &harl, int i)
{
	while (i < 4)
	{
		if (i == 0)
			harl.complain("DEBUG");
		if (i == 1)
			harl.complain("INFO");
		if (i == 2)
			harl.complain("WARNING");
		if (i == 3)
			harl.complain("ERROR");
		i++;
	}
}

int	index_identifier(std::string str)
{
	if (str == "DEBUG")
		return (0);
	if (str == "INFO")
		return (1);
	if (str == "WARNING")
		return (2);
	if (str == "ERROR")
		return (3);
	return (-1);
}

int main(int ac, char **av)
{
	Harl harl;
	if (ac == 2)
	{
		int i = index_identifier((std::string)av[1]);
		switch (i)
		{
			case 0:
				please_shut_up(harl, 0);
				break ;
			case 1:
				please_shut_up(harl, 1);
				break ;
			case 2:
				please_shut_up(harl, 2);
				break ;
			case 3:
				please_shut_up(harl, 3);
				break ;
        	default:
            	std::cout << "[Probably complaining about insignificant problems]" << std::endl;
		}
	}
	else
		std::cout << "correct number of data was not entered" << std::endl;
}
