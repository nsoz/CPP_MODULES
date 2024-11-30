#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat();
	WrongCat(WrongCat &copy);
	WrongCat &operator=(WrongCat &copy);
	~WrongCat();

public:
	void makeSound() const;
};


#endif