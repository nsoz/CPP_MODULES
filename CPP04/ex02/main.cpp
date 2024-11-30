#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const WrongAnimal* metas = new WrongAnimal();
const WrongAnimal* metatas = new WrongCat();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
j->makeSound();
std::cout << i->getType() << " " << std::endl;
i->makeSound();
std::cout << "~~wrong~~" << std::endl;
metas->makeSound();
metatas->makeSound();
std::cout << "~~wrong~~" << std::endl;
delete j;
delete i;
delete metas;
delete metatas;

return 0;
}