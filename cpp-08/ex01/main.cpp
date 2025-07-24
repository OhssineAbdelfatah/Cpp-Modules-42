#include "Span.hpp"
#include <iostream>
#include <set>

int main(){
    Span sp(15);

    sp.addNumber(1);
    sp.addNumber(5);
    sp.addNumber(26);
    sp.addNumber(158);
    sp.addNumber(-1);
    sp.addNumber(-100);
    sp.addNumber(98);
    sp.addNumber(578);
    sp.addNumber(0);
    sp.addNumber(3);
    sp.addNumber(2);
    sp.addNumber(10);
    sp.addNumber(115);
    sp.addNumber(6);
    sp.addNumber(9);
    sp.addNumber(8);


    std::cout << "Shortest span : " << sp.longestSpan() << std::endl ;
    std::cout << "LongestSpan span : " << sp.shortestSpan() << std::endl;
}