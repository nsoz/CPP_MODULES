#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"


class Dog : public Animal
{
    public :
        Dog();
        virtual ~Dog();
        Dog(const Dog &cpy);
        Dog& operator=(const Dog &assignment);

        void makeSound() const;
    private :
        Brain *brain;
};

#endif
