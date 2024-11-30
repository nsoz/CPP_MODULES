#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
    std::cout << "Animal default constructor called" << std::endl;
}

Animal::~Animal()
{
    std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal &cpy)
{
    this->type = cpy.type;
    std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &assignment)
{
    if (this != &assignment)
        this->type = assignment.type;
    std::cout << "Animal copy assignment operator called" << std::endl;
    return *this;
}

std::string Animal::getType() const
{
    return (type);
}

// void Animal::makeSound() const
// {
// 	std::cout << "Animal sound!" << std::endl;
// }
