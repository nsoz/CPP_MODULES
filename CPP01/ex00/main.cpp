#include "Zombie.hpp"

int main()
{
    Zombie *myZombie;
    myZombie = newZombie("Foo");
    myZombie->announce();
    delete (myZombie);
    randomChump("Bar");
    return (0);
}