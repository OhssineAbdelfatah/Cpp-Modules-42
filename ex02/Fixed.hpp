#ifndef FIXED_HPP
#define FIXED_HPP
#include<iostream>

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
    Fixed& operator=(const Fixed& copy); 
    
    // copy construecture
    Fixed(const Fixed& copy);

    Fixed(const int param);
    Fixed(const float param);

    // that converts the fixed-point value to a floating-point value.
    float toFloat( void ) const;

    // that converts the fixed-point value to an integer value.
    int toInt( void ) const;
    
    // overload arithmetic operators + - / *
    Fixed operator+(const Fixed& operand);
    Fixed operator-(const Fixed& operand);
    Fixed operator*(const Fixed& operand);
    Fixed operator/(const Fixed& operand);

    bool operator>(const Fixed& op);
    bool operator>=(const Fixed& op);
    bool operator<(const Fixed& op);
    bool operator<=(const Fixed& op);
    bool operator==(const Fixed& op);
    bool operator!=(const Fixed& op);

    Fixed operator++();
    Fixed operator++(int);
    Fixed operator--();
    Fixed operator--(int);
   
};

std::ostream & operator<<( std::ostream & os, Fixed const & i);

#endif
