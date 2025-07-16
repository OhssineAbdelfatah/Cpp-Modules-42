#include "Fixed.hpp"
#include <iostream>


Fixed::Fixed()
{
    _fixedPoint = 0 ;
    std::cout << "Default constructor called" << std::endl ;
}

// destructeur
Fixed::~Fixed()
{
    std::cout << "Defaullt Deconstructeur " << std::endl ;
}

int Fixed::getRawBits( void ) const
{
    std::cout << "getRawBits member function called" << std::endl ;
    return _fixedPoint;
}

void Fixed::setRawBits( int const raw )
{
    // std::cout << "setRawBits member function called" << std::endl ;
   _fixedPoint = raw ;
}

void Fixed::operator=(const Fixed& copy)
{
    std::cout << "Copy assignment operator called" << std::endl ;
    this->setRawBits(copy.getRawBits());
}

Fixed::Fixed(const Fixed& copy)
{
    std::cout << "Copy constructor called" << std::endl ;
    this->setRawBits(copy.getRawBits());
    return ;
}
