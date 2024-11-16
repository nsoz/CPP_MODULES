#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
class FragTrap : public ClapTrap
{
    public :
        FragTrap();
        FragTrap(const FragTrap &cpy);
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap &operator=(const FragTrap &copy);
        void highFivesGuys(void);

};

#endif