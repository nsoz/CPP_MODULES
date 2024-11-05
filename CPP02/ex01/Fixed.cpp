#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& var) : raw(var.raw)
{
     std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& var)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (&var != this)
        this->raw = var.raw;
    return (*this);
}

Fixed::Fixed(int num)
{
    std::cout << "Int constructor called" << std::endl;
    raw = num << fractional_bits;
}

Fixed::Fixed(float num) // CHECK THİS FUNC (ROUNDF)
{
    raw = (num * (float)(1 << fractional_bits));
    std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat( void ) const
{
    return ((float)raw / (1 << fractional_bits));
}

int Fixed::toInt( void ) const
{
    return (raw >> fractional_bits);
}

int Fixed::getRawBits() const
{
    return(this->raw);
}

void    Fixed::setRawBits(int raw)
{
    this->raw = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}