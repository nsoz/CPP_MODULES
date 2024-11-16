#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ): name("ClapTrap"), hit_points(10), energy_points(10), attack_damage(0)
{
     std::cout << "Default constructor " << name << " has been created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& cpy) : name(cpy.name), energy_points(cpy.energy_points), attack_damage(cpy.attack_damage)
{
    std::cout << "ClapTrap copy constructor " <<  cpy.name << " called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << name << " has been created!" << std::endl;
}

 ClapTrap& ClapTrap::operator=(const ClapTrap &cpy)
 {
    if (this != &cpy)
    {
        this->name = cpy.name;
        std::cout << "ClapTrap: " << name << " assignment operator called!" << std::endl;
        this->hit_points = cpy.hit_points;
        this->energy_points = cpy.energy_points;
        this->attack_damage = cpy.attack_damage;
    }
    return (*this);
 }

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " has been destroyed!" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points <= 0)
        std::cout << "ClapTrap " << name << " has no hit points left and can't attack!"  << std::endl;
    else if (this->energy_points <= 0)
        std::cout << "ClapTrap " << name << " is out of energy and can't attack to " << target << "!" << std::endl;
    else
    {
        energy_points--;
        std::cout << "ClapTrap " << name << " attacks " << target << " causing " << attack_damage << " points of damage!" << std::endl;
    }
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hit_points == 0)
        std::cout << "ClapTrap " << name << " is already out of hit points and cannot take more damage!" << std::endl;
    else if (hit_points <= (int)amount)
    {
        hit_points = 0;
        std::cout << "ClapTrap " << name << " is destroyed" << std::endl;
    }
    else
    {
        hit_points -= amount;
        std::cout << "ClapTrap " << name << "'s current hit point is " << hit_points << std::endl;
    }
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energy_points > 0)
    {
        hit_points += amount;
        std::cout << "ClapTrap " << name << " repairs itself, restoring " << amount << " hit points! Current hit points: " << hit_points << "." << std::endl;
        energy_points--;
    }
    else
    {
        std::cout << "ClapTrap " << name << " has no energy left and cannot repair itself!" << std::endl;
    }
}

std::string ClapTrap::getName() const
{
    return (name);
}

int ClapTrap::getHitP() const
{
    return (hit_points);
}

int ClapTrap::getEnergyP() const
{
    return (energy_points);
}