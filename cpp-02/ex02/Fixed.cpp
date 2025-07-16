#include "Fixed.hpp"
#include <iostream>
#include <cmath>


const int Fixed::fractional = 8;


//  Default constructor
Fixed::Fixed(): fixedPoint(0)
{
    // std::cout << "Default constructor called" << std::endl ;
}

// Defaullt Deconstructeur 
Fixed::~Fixed()
{
    // std::cout << "Defaullt Deconstructeur " << std::endl ;
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
    // std::cout << "Copy assignment operator called" << std::endl ;
    this->setRawBits(copy.getRawBits());
    return *this;
}

// Copy constructor
Fixed::Fixed(const Fixed& copy)
{
    // std::cout << "Copy constructor called" << std::endl ;
    this->setRawBits(copy.getRawBits());
    return ;
}

// constructor takes float
Fixed::Fixed(const float param) : fixedPoint( roundf( param  * ( 1 << fractional )) )
{
    // std::cout << "Constructor takes float called " << std::endl ;
}

// constructor takes integer
Fixed::Fixed(const int param): fixedPoint(param << fractional)
{
    // std::cout << "Constructor takes integer called " << std::endl ;
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


// overlaod aritmethic operators

Fixed Fixed::operator+(const Fixed& operand)
{
    return Fixed( this->toFloat() + operand.toFloat());
}

Fixed Fixed::operator-(const Fixed& operand)
{
    return Fixed( this->toFloat() - operand.toFloat());
}

Fixed Fixed::operator*(const Fixed& operand)
{
    return Fixed( this->toFloat() * operand.toFloat());
}

Fixed Fixed::operator/(const Fixed& operand)
{
    return Fixed( this->toFloat() / operand.toFloat());
}

// comparison operators overload

bool Fixed::operator>(const Fixed& op)
{
    return this->getRawBits() > op.getRawBits();
}

bool Fixed::operator>=(const Fixed& op)
{
    return this->getRawBits() >= op.getRawBits();
}

bool Fixed::operator<(const Fixed& op)
{
    return this->getRawBits() < op.getRawBits();
}

bool Fixed::operator<=(const Fixed& op)
{
    return this->getRawBits() <= op.getRawBits();
}

bool Fixed::operator==(const Fixed& op)
{
    return this->getRawBits() == op.getRawBits();
}

bool Fixed::operator!=(const Fixed& op)
{
    return this->getRawBits() != op.getRawBits();
}


// increment and decrement operators overload

// pre
Fixed Fixed::operator++()
{
    fixedPoint++;
    return *this;
}

// post
Fixed Fixed::operator++(int)
{
    Fixed temp(*this); 
    // do not use float constructer , the two ojects point to same memory
    // use copy constructer instead
    fixedPoint++;
    return temp;
}

// pre
Fixed Fixed::operator--()
{
    fixedPoint--;
    return *this;
}

// post
Fixed Fixed::operator--(int)
{
    Fixed temp(*this);

    fixedPoint--;
    return temp;
}


// min functions

Fixed& Fixed::min(Fixed& f1, Fixed& f2)
{
    if(f1 > f2 )
        return (f2);
    return (f1);
} 

const Fixed& Fixed::min(const Fixed& f1, const Fixed& f2)
{
    if(f1.getRawBits() > f2.getRawBits() )
        return (f2);
    return (f1);
}

// max functions
Fixed& Fixed::max(Fixed& f1, Fixed& f2)
{
    if(f1 < f2 )
        return (f2);
    return (f1);
} 

const Fixed& Fixed::max(const Fixed& f1,const Fixed& f2)
{
    if(f1.getRawBits() < f2.getRawBits() )
        return (f2);
    return (f1);
} 