#include "Fixed.hpp"

Fixed::Fixed() : raw(0)
{
}

Fixed::Fixed(const Fixed& var) : raw(var.raw)
{
}

Fixed::Fixed(const int intVal)
{
	raw = intVal << fractional_bits;
}

Fixed::Fixed(const float floatVal)
{
	raw = roundf(floatVal * (float)(1 << fractional_bits));
}

Fixed&  Fixed::operator=(const  Fixed& var)
{
    if (this != &var)
        this->raw = var.getRawBits();
    return (*this);
}

Fixed::~Fixed()
{
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
    return (this->raw > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
    return (this->raw < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
    return (this->raw >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
    return (this->raw <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
    return (this->raw == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
    return (this->raw != other.getRawBits());
}

Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(raw + other.getRawBits());
}

Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(raw - other.getRawBits());
}

Fixed Fixed::operator*(const Fixed &fixed) const
{
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other != 0)
		return (Fixed(this->toFloat() / other.toFloat()));
	else
	{
		std::cout << "cannot divide by 0" << std::endl;
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