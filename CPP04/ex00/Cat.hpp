#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
    public :
        Cat();
        virtual ~Cat();
        Cat(const Cat& ccpy);
        Cat& operator=(const Cat& assignment);

        void makeSound() const;
};

#endif