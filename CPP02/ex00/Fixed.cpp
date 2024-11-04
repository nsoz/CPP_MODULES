#include "Fixed.hpp"

Fixed::Fixed() : crude(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& var) : crude(var.crude)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& var)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &var)
        this->crude = var.crude;
    return (*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (crude);
}


void Fixed::setRawBits( int const raw )
{
    crude = raw;
}