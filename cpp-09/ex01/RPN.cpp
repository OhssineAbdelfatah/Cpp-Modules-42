#include "RPN.hpp"

RPN::RPN() {
    // Constructor implementation
}

RPN::~RPN() {
    // Destructor implementation
}

RPN::RPN(const RPN& other) {
    // Copy constructor implementation
}

RPN& RPN::operator=(const RPN& other) {
    // Copy assignment operator implementation
    if (this != &other) {
        // Perform deep copy
    }
    return *this;
}

const char* RPN::BadInputException::what() const throw(){return _mssg.c_str();}
RPN::BadInputException::BadInputException(std::string mssg) : _mssg(mssg){}
RPN::BadInputException::~BadInputException() throw(){}