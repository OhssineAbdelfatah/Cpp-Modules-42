#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    private:
        int _fixedPoint;
        static const int _fractional;
    public :
        Fixed();
        ~Fixed();
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        
        // copy assignement
        void operator=(const Fixed& copy); 
        
        // copy construecture
        Fixed(const Fixed& copy);
};
#endif
