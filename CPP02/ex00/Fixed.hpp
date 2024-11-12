/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgunay <42istanbul.com.tr>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/11 18:19:32 by fgunay            #+#    #+#             */
/*   Updated: 2024/08/11 18:19:33 by fgunay           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
private:
	int fixedPointNumber;
	static const int bits = 8;

public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &number);

public:
	int getRawBits(void) const;
	void setRawBits(int const raw);
};
