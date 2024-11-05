#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private :
        int raw;
        static const int fractional_bits = 8;
    public :
        Fixed();
        Fixed(const Fixed& var);
        Fixed& operator=(const Fixed& var);
        Fixed(int num);
        Fixed(float num);
        ~Fixed();
        float toFloat( void ) const;
        int toInt( void ) const;
        int getRawBits() const;
        void    setRawBits(int raw);
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif