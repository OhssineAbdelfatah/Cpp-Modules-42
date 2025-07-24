#include "Span.hpp"
#include <iostream>
#include <set>

Span::Span(unsigned int N) {
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
    this->mySpan.insert(num);
    // if(this->mySpan.size() + 1 > this->N){
    for(std::set<int>::iterator it = mySpan.begin(); it != mySpan.end() ; it++)
        std::cout << *it << std::endl;
    // }
}

const char* Span::SpanOverflowException::wath() const throw(){
    return ("you can not add numbers anymore !!");
}

int Span::shortestSpan(){
    // create and throw exception if there is only 1 number
    std::set<int> diffs;
    std::set<int>::iterator it1 = this->mySpan.begin(); 
    std::set<int>::iterator it2 = this->mySpan.begin(); 
    for (it2++ ; it2 != this->mySpan.end(); it2++,it1++ )
        diffs.insert(*it2 - *it1);

    return *(diffs.begin());
}

int Span::longestSpan(){
    return (*(this->mySpan.end()) - *(this->mySpan.begin()));
    // hona takmeno ala3ba
}