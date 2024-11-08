 #include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap1("ClapTrap1");
    ClapTrap claptrap2("ClapTrap2");

    claptrap1.attack("Target1"); 
    claptrap1.takeDamage(5);
    claptrap1.beRepaired(3);

    return 0;
}
