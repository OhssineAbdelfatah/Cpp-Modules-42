#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main( void ) {
    if ( bsp( Point(0, 0), Point(0, 0), Point(0, 0), Point(0, 15) ) == true ) 
    {
        std::cout << "Point is in the triangle" << std::endl;
    } else 
    {
        std::cout << "Point is not in the triangle" << std::endl;
    }
    return 0;
}