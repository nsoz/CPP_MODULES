#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
    private :
        std::string name;
        int hit_points;
        int energy_points;
        int attack_damage;
    public :
        ClapTrap();
        ClapTrap(const ClapTrap& cpy);
        ClapTrap &operator=(const ClapTrap &copy);
        ClapTrap(const std::string& name);
        ~ClapTrap();

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string getName() const;
        int getHitP() const;
        int getEnergyP() const;
};

#endif