#include"Point.hpp"

Point::Point(): x(0),y(0)
{
    std::cout << "Default Point Constructure " << std::endl ;
}

Point::~Point(){
    std::cout << "Default Point Deconstructure " << std::endl ;
}

Point::Point(const float x, const float y){

}

Point(const Point& copy){

}

Point& operator=(const Point& copy){

}