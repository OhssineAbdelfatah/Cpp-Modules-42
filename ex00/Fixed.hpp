#ifndef FIXED_HPP
#define FIXED_HPP

class Fixed {
    private:
        int fixedPoint;
        static const int fractional;
    public :
    Fixed();
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
    
    // def between copyConstructer and copyAssignment
    // copy assignement
    void operator=(const Fixed& copy); 
    
    // copy construecture
    Fixed(const Fixed& copy);

};
#endif
