#include "Span.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

Span::Span(unsigned int N) :N(N){
    // Constructor implementation
    std::cout << "new Span("<< N <<") created !" << std::endl;
}

Span::~Span() {
    // Destructor implementation
    std::cout << "Span deleted !" << std::endl;
}

Span::Span(const Span& other) {
    // Copy constructor implementation
    std::cout << "Creat Span("<< other.N <<") using Copy Constructor" << std::endl;
    *this = other;
}

Span& Span::operator=(const Span& other) {
    // Copy assignment operator implementation
    std::cout << "Copy Assignment Span Called !" << std::endl;
    if (this != &other) {
        // Perform deep copy
        this->N = other.N;
        this->mySpan = other.mySpan;
    }
    return *this;
}

void Span::addNumber(int num){
    if(this->mySpan.size() + 1 > this->N)
        throw Span::SpanOverflowException();
    this->mySpan.push_back(num);
}

const char* Span::SpanOverflowException::what() const throw(){
    return ("you can not add numbers anymore !!");
}

const char* Span::SpanSingleElemException::what() const throw(){
    return ("The span can not be calculated , there is only one element !!");
}

int Span::shortestSpan(){
    if(mySpan.size() < 2)
        throw Span::SpanSingleElemException();     
    std::vector<int>::iterator it1 = this->mySpan.begin();
    std::vector<int>::iterator it2 = this->mySpan.begin(); 
    std::sort(this->mySpan.begin(), this->mySpan.end());
    int minDiff = *(--mySpan.end());
    for (it2++ ; it2 != this->mySpan.end(); it2++,it1++ ){
        if(minDiff > (*it2 - *it1))
        minDiff = (*it2 - *it1);
    }
    return minDiff;
}

int Span::longestSpan(){
    if(mySpan.size() < 2)
        throw Span::SpanSingleElemException();  
    std::sort(this->mySpan.begin(), this->mySpan.end());
    return (*(--this->mySpan.end()) - *(this->mySpan.begin()));
}

