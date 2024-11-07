#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& var) : raw(var.raw)
{
     std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int intVal)
{
	raw = intVal << fractional_bits; // or value = intVal * 256;
}

Fixed::Fixed(const float floatVal)
{
	raw = roundf(floatVal * (float)(1 << fractional_bits)); // or value = roundf(floatVal * 256.0f);
}

Fixed&  Fixed::operator=(const  Fixed& var)
{
    if (this != &var)
        this->raw = var.raw;
    return (*this);
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

int Fixed::getRawBits( void ) const
{
    return (raw);
}

void Fixed::setRawBits( int const raw )
{
    this->raw = raw;
}

bool    Fixed::operator>(const Fixed& other) const
{
    return (this->raw > other.raw);
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->raw < other.raw);
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->raw >= other.raw);
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->raw <= other.raw);
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->raw == other.raw);
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->raw != other.raw);
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(raw + other.raw);
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(raw - other.raw);
}

Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(raw * other.raw);
}


Fixed Fixed::operator/(const Fixed &other) const
{
	if (other != 0)
		return (Fixed(this->toFloat() / other.toFloat()));
	else
	{
		std::cout << "cannot divide by 0 m8\n";
		exit(1);
	}
}


Fixed& Fixed::operator++()
{
    raw++;
    return (*this);
}

Fixed& Fixed::operator--()
{
    raw--;
    return (*this);
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this); 
    raw++;             
    return temp;      
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this); 
    raw--;             
    return temp;      
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
    return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
    return (a > b ? a : b);
}


std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}