#include "Fixed.hpp"
#include <iostream>
#include <cmath>


const int Fixed::fractional = 8;


//  Default constructor
Fixed::Fixed(): fixedPoint(0)
{
    std::cout << "Default constructor called" << std::endl ;
}

// Defaullt Deconstructeur 
Fixed::~Fixed()
{
    std::cout << "Defaullt Deconstructeur " << std::endl ;
}

// getRawBits member function
int Fixed::getRawBits( void ) const
{
    // std::cout << "getRawBits member function called" << std::endl ;
    return fixedPoint;
}

// setRawBits member function
void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl ;
    fixedPoint = raw ;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl ;
    if (this != &copy)
        this->setRawBits(copy.getRawBits());
    return *this;
}

// Copy constructor
Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl ;
    this->setRawBits(copy.getRawBits());
    return ;
}

// constructor takes float
Fixed::Fixed(const float param) : fixedPoint( roundf( param  * ( 1 << fractional )) )
{
    std::cout << "Constructor takes float called " << std::endl ;
}

// constructor takes integer
Fixed::Fixed(const int param): fixedPoint(param << fractional)
{
    std::cout << "Constructor takes integer called " << std::endl ;
}

// toFloat member function
float Fixed::toFloat( void ) const
{
    return (static_cast<float>(getRawBits()) / (1 << fractional));
}

// toInt member function 
int Fixed::toInt( void ) const
{
    return (getRawBits() >> fractional);
}

// overlaod of insertion operator (<<) for class Fixed
std::ostream& operator<<( std::ostream & os, Fixed const & i)
{
    os << i.toFloat();
    return os;
}

