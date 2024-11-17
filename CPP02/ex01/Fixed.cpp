/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muoz <muoz@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:47:52 by fgunay            #+#    #+#             */
/*   Updated: 2024/11/17 17:38:36 by muoz             ###   ########.fr       */
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
	value = intVal << bits;
}

Fixed::Fixed(const float floatVal)
{
	std::cout << "Float constructor called" << std::endl;
	value = roundf(floatVal * (float)(1 << bits));
}

int Fixed::toInt() const
{
	return (value >> bits);
}

float Fixed::toFloat() const
{
	return ((float)value / (1 << bits));
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
