#include"Fixed.hpp"
#include"Point.hpp"

static Fixed Abs(Fixed x)
{
    if ( x < 0 )
    {
        // x.setRawBits(x.getRawBits() * -1);
        // return x;
        return x * -1;
    }    
    return x;    
}

// The shoelace formula for three points A(x1,y1)A(x1​,y1​), B(x2,y2)B(x2​,y2​), C(x3,y3)C(x3​,y3​) is:
// Area=1/2 ∣ x1*(y2−y3) + x2*(y3−y1) + x3*(y1−y2) ∣



static Fixed area(Point a, Point b, Point c)
{
    return (
        Abs(a.getX() * (b.getY() - c.getY())+
        b.getX() * (c.getY() - a.getY())+
        c.getX() * (a.getY() - b.getY())) / 2 
    );
}



bool bsp( Point const a, Point const b, Point const c, Point const point){
    Fixed area1 = area( a, b , point);
    Fixed area2 = area( a, c , point);
    Fixed area3 = area( b, c , point);
    Fixed areaTriangle = area( a, b ,c);

    if(area1 + area2 + area3 == areaTriangle)
        return true ;
    return false;
}