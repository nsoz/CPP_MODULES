#include "Cat.hpp"

Cat::Cat()
{
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& cpy)
{
    this->type = cpy.type;
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& assignment)
{
    if (this != &assignment)
        this->type = assignment.type;
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}