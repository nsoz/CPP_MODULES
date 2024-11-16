#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
    std::cout << "Default constructor FragTrap has been created!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &cpy) : ClapTrap(cpy)
{
    std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    // this->name = name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "FragTrap constructor: " << name << " has been created!" << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap has been destroyed!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy)
{
    std::cout << "FragTrap Copy Assignment operator Called" << std::endl;
    if (this == &copy)
        return *this;
    ClapTrap::operator=(copy);
    return *this;
}

void FragTrap::highFivesGuys()
{
    std::cout << name << " : hey ! give me high five" << std::endl;
}
