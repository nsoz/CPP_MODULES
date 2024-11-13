/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:47:52 by fgunay            #+#    #+#             */
/*   Updated: 2024/08/11 18:47:54 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
    *this = copy;
	//this->operator=(copy);
}

Fixed &Fixed::operator=(Fixed const &number)
{
	std::cout << "Copy assignment operator called" << std::endl;

	this->value = number.getRawBits();

	return *this;
}

Fixed::Fixed(const int intVal)
{
	std::cout << "Int constructor called" << std::endl;
	value = intVal << bits; // or value = intVal * 256;
}

Fixed::Fixed(const float floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	value = (floatVal * (float)(1 << bits)); // or value = roundf(floatVal * 256.0f));
}

int Fixed::toInt() const
{
	return (value >> bits); // or value / 256
}

float Fixed::toFloat() const
{
	return ((float)value / (1 << bits)); // or (float) / 256
}

std::ostream &operator<<(std::ostream &os, Fixed const &fixed)
{
	os << fixed.toFloat();
	return os;
}

int Fixed::getRawBits() const
{
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
