#include "Cat.hpp"

Cat::Cat()
{
    brain = new Brain();
    this->type = "Cat";
    std::cout << "Cat default constructor called" << std::endl;
}

Cat::~Cat()
{
    delete (this->brain);
    std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& cpy) : Animal(cpy)
{
    this->brain = new Brain(*cpy.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& assignment)
{
    if (this != &assignment)
    {
        this->type = assignment.type;
        delete (this->brain);
        this->brain = new Brain(*assignment.brain);
    }
    std::cout << "Cat copy assignment operator called" << std::endl;
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "meow meow" << std::endl;
}