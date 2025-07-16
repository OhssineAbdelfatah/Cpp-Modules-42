#include"Point.hpp"

Point::Point(): x(0),y(0)
{
    std::cout << "Default Point Constructure " << std::endl ;
}

Point::~Point(){
    std::cout << "Default Point Deconstructure " << std::endl ;
}

Point::Point(const float xx, const float yy): x(xx),y(yy)
{
    std::cout << "Constructure Paramterized Float called !!" << std::endl;
}

Point::Point(const Point& copy): x(copy.x), y(copy.y)
{
    std::cout << "Copy Constructure Point class called !!" << std::endl;
}

Point& Point::operator=(const Point& copy)
{
    if( this != &copy )
    {
        (Fixed) this->x = copy.x ;
        (Fixed) this->y = copy.y ;
    }
    return *this;
}

Fixed Point::getX(void) const
{
    return x;
}

Fixed Point::getY(void) const
{
    return y;
}