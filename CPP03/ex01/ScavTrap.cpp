#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
        std::cout << "Default constructor ScavTrap has been created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &cpy) : ClapTrap(cpy)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    this->name = name;
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
    std::cout << "ScavTrap constructor: " << name << " has been created!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &copy)
{
    if (this == &copy) 
        return *this;

    ClapTrap::operator=(copy);
    std::cout << "ScavTrap Copy Assignment operator Called" << std::endl;
    return *this;
}


ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap has been destroyed!" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->energy_points >= 1)
	{
		std::cout << "ScavTrap " << this->name << " attacks " << target << std::endl;
		this->energy_points--;
	}
	else
		std::cout << "ScavTrap " << this->name << " has no energy to attack." << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is now in Gate keeper mode." << std::endl;
}