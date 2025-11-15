#include "RPN.hpp"

RPN::RPN(char *input) {
    data = std::string(input);
}
RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        tokens = other.tokens;
    }
    return *this;
}

const char* RPN::BadInputException::what() const throw(){return _mssg.c_str();}
RPN::BadInputException::BadInputException(std::string mssg) : _mssg(mssg){}
RPN::BadInputException::~BadInputException() throw(){}

void RPN::parseInput(){
    int oprnd[2];
    int oprtr;
    if(data.empty() || data.find_first_not_of(' ') == std::string::npos )
        throw RPN::BadInputException("Empty string");
    int index;
    for(int i = 0 ; i < data.size(); i++){
        if(data[i] != ' '){
            if(validELem(data, i))
                throw RPN::BadInputException("Invalid Charachter");
            data.push_back(data[i]);
        }
    }
    
}

bool RPN::validELem(std::string str, int index){
    if(str[index] != '*' && str[index] != '/' && str[index] != '-' && str[index] != '+' && !::isdigit(str[index]))
        throw RPN::BadInputException("Invalid Charachter");
    if(index > 0 && index < str.size()){
        if(str[index - 1] != ' ' || str[index + 1] != ' ')
            throw RPN::BadInputException("Invalid Charachter");
    }
    return false;
}


