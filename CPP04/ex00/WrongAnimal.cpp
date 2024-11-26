#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal Default Constructor Called!" << std::endl;
	this->type = "Wrong Animal!";
}

WrongAnimal::WrongAnimal(WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor Called!" << std::endl;
	*this = copy;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &other)
{
	std::cout << "WrongAnimal Copy Assignment Operator Called!" << std::endl;
	this->type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal Destructor Called!" << std::endl;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Wrong animal sound!" << std::endl;
}

