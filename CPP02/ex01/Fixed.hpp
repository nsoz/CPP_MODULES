/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:47:58 by fgunay            #+#    #+#             */
/*   Updated: 2024/08/11 18:47:59 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int value;
	static const int bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &number);
    Fixed(const int intVal);
	Fixed(const float floatVal);

public:
	int getRawBits(void) const;
	void setRawBits(int const raw);
    float toFloat(void) const;
	int toInt(void) const;
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);
