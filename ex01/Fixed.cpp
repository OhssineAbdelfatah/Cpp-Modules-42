#include "Fixed.hpp"
#include <iostream>


//  Default constructor
Fixed::Fixed()
{
    fixedPoint = 0 ;
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
    std::cout << "getRawBits member function called" << std::endl ;
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
Fixed::Fixed(const float param)
{
    std::cout << "Constructor takes float called "  ;
    std::cout << param << std::endl;
}

// constructor takes integer
Fixed::Fixed(const int param)
{
    std::cout << "Constructor takes integer called "  ;
    std::cout << param << std::endl;
}

// toFloat member function
float Fixed::toFloat( void ) const
{
    return (3.14);
}

// toInt member function 
int Fixed::toInt( void ) const
{
    return 3;
}

// overlaod of insertion operator (<<) for class Fixed
std::ostream& Fixed::operator<<( std::ostream & os)
{
    os << "overload" << std::endl;
    os << "insertion" << std::endl;
    os << "operator" << std::endl;
    return os;
}

