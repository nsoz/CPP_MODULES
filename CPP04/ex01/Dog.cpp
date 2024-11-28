#include "Dog.hpp"

Dog::Dog()
{
    brain =new Brain();
    this->type = "Dog";
    std::cout << "Dog default constructor called" << std::endl;
}

Dog::~Dog()
{
    delete (this->brain);
    std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
    this->brain = new Brain(*cpy.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog &assignment)
{
    if (this != &assignment)
    {
        this->type = assignment.type;
        delete (this->brain);
        this->brain = new Brain(*assignment.brain);
    }
    std::cout << "Dog copy assignment operator called" << std::endl;
    return *this;
}


void Dog::makeSound() const
{
	std::cout << "bark bark" << std::endl;
}
