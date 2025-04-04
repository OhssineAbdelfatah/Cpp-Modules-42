#include <iostream>
#include "Fixed.hpp"

int main( void ) 
{
    Fixed a(5);
    Fixed b(6);
    // Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a + b << std::endl;
    // std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    // std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    // std::cout << b << std::endl;
    // std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}