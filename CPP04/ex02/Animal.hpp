#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
    protected :
        std::string type;

    public :
        Animal();
        virtual ~Animal();
        Animal(const Animal &cpy);
        Animal& operator=(const Animal &assignment);
        
        std::string getType() const;

        virtual void makeSound() const = 0;
};


#endif