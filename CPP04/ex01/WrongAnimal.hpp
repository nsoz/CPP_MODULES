#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
public:
	WrongAnimal();
	WrongAnimal(WrongAnimal &copy);
	WrongAnimal &operator=(WrongAnimal &copy);
	~WrongAnimal();

	void makeSound() const;

protected:
	std::string type;
};

#endif