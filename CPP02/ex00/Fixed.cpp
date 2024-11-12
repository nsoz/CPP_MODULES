/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:19:20 by fgunay            #+#    #+#             */
/*   Updated: 2024/08/11 18:19:21 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNumber(0)
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

	this->fixedPointNumber = number.getRawBits();

	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixedPointNumber);
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointNumber = raw;
}
