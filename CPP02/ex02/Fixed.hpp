#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    private :
        int raw;
        static const int fractional_bits = 8;
    public :
        Fixed();
        Fixed(const Fixed& var);
        Fixed(const int intVal);
        Fixed(const float floatVal);
        Fixed& operator=(const Fixed& var);
        ~Fixed();
        
        float toFloat( void ) const;
        int toInt( void ) const;
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );       
        
        bool    operator>(const Fixed& other) const;
        bool    operator<(const Fixed& other) const;
        bool    operator>=(const Fixed& other) const;
        bool    operator<=(const Fixed& other) const;
        bool    operator==(const Fixed& other) const;
        bool    operator!=(const Fixed& other) const;

        Fixed   operator+(const Fixed& other) const;
        Fixed   operator-(const Fixed& other) const;
        Fixed   operator*(const Fixed& other) const;
        Fixed   operator/(const Fixed& other) const;

        Fixed&  operator++();
        Fixed  operator++(int i);
        Fixed&  operator--();
        Fixed  operator--(int i);

        static Fixed& min(Fixed& a, Fixed& b);
        static const Fixed& min(const Fixed& a, const Fixed& b);
        static Fixed& max(Fixed& a, Fixed& b);
        static const Fixed& max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream &os, Fixed const &fixed);

#endif