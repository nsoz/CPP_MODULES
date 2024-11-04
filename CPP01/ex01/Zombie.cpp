#include "Zombie.hpp"

Zombie::Zombie()
{
}

void Zombie::set_name(std::string name)
{
    this->name = name;
}

void    Zombie::announce()
{
    std::cout << this->name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}