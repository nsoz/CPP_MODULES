#include "Dog.hpp"

Dog::Dog()
{
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &cpy)
{
    this->type = cpy.type;
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &assignment)
{
    if (this != &assignment)
        this->type = assignment.type;
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}


void Dog::makeSound() const
{
	std::cout << "bark bark" << std::endl;
}
