#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap
{
    public :
        ScavTrap();
        ScavTrap(const ScavTrap &cpy);
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap &operator=(const ScavTrap &copy);
        void attack(const std::string& target);
        void guardGate();
};

#endif