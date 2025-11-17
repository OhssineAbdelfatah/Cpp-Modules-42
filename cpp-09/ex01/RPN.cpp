#include "RPN.hpp"

void RPN::printStack(){
    std::cout << "stack >>>>>>>>>>>>" << std::endl;
    for (MutantStack<int>::iterator it = digits.begin(); it != digits.end() ; it++)
        std::cout << ">>" << *it << std::endl;
    std::cout << "<<<<<<<<<<<<<<<<<<" << std::endl;
}

RPN::RPN(char *input) {
    data = std::string(input);
    // try{
        parseInput();
    // }catch(std::exception& e){
        // std::cout << e.what();
    // }
}

RPN::RPN(const std::string input) {
    data = input;
    // try{
        parseInput();
    // }catch(std::exception& e){
        // std::cout << e.what();
    // }
}
RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN& other) {
    *this = other;
}

RPN& RPN::operator=(const RPN& other) {
    if (this != &other) {
        digits = other.digits;
    }
    return *this;
}

const char* RPN::BadInputException::what() const throw(){return _mssg.c_str();}
RPN::BadInputException::BadInputException(std::string mssg) : _mssg(mssg){}
RPN::BadInputException::~BadInputException() throw(){}

void RPN::parseInput(){
    if(data.empty() || data.find_first_not_of(' ') == std::string::npos || data.size() < 5)
        throw RPN::BadInputException("ERROR");
    for(int i = 0 ; (size_t)i < data.size(); i++){
        if(data[i] != ' '){
            if(validELem(data, i))
                throw RPN::BadInputException("ERROR");
            if(data[i] >= 48 && data[i] <= 57)
                digits.push(data[i] - 48);
            else{
                if(digits.size() < 2)
                    throw RPN::BadInputException("ERROR");
                else {
                    int a = digits.top();
                    digits.pop();
                    int b = digits.top() ;
                    digits.pop();
                    switch (data[i])
                    {
                    case '*':
                        digits.push(b * a);
                        break;
                    case '/':
                        if(a == 0) throw RPN::BadInputException("ERROR"); 
                        digits.push(b / a);
                        break;
                    case '+':
                        digits.push(b + a);
                        break;
                    case '-':
                        digits.push(b - a);
                        break;
                    default:
                        break;
                    } 
                }
            }
                
        }
    }
    if(digits.size() != 1)
        throw RPN::BadInputException("ERROR");
    // std::cout << "Result of ("<< data <<") is " << digits.top() << std::endl;
    std::cout << digits.top() << "\n";
}

bool RPN::validELem(std::string str, int index){
    if(str[index] != '*' && str[index] != '/' && str[index] != '-' && str[index] != '+' && !(str[index] >= 48 && str[index] <= 57))
        throw RPN::BadInputException("ERROR");
    if(index > 0 && (size_t)index < str.size()){
        if( index > 0 && index < (int)str.size() -1 &&  (str[index - 1] != ' ' || str[index + 1] != ' ')){
            throw RPN::BadInputException("ERROR");
        }
    }
    return false;
}


