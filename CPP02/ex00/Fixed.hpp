#ifndef FIXED_HPP
#define FIXED_HPP

#include <string>
#include <iostream>

class Fixed
{
    private :
        int crude;
        static const int fractional_bits = 8;
    public :
        Fixed();
        Fixed(const Fixed& var);
        Fixed& operator=(const Fixed& var);
        ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif