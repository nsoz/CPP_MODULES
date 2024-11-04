#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed
{
    private :
        int crude;
        static int fractional_bits = 8;
    public :
        Fixed(int var);
        Fixed(&Fixed var);
        
        ~Fixed();
    int getRawBits( void ) const;
    setRawBits( int const raw );
}