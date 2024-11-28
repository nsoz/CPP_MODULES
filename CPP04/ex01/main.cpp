#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
const Animal* meta = new Animal();
const WrongAnimal* metas = new WrongAnimal();
const WrongAnimal* metatas = new WrongCat();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound();
j->makeSound();
meta->makeSound();
std::cout << "~~wrong~~" << std::endl;
metas->makeSound();
metatas->makeSound();
std::cout << "~~wrong~~" << std::endl;

delete meta;
delete j;
delete i;
delete metas;
delete metatas;

return 0;
}