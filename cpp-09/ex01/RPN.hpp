#ifndef RPN_HPP
#define RPN_HPP

#include<stack>
#include<string>
#include<iostream>
#include<algorithm>
#include"MutantStack.hpp"
int main1() ;
class RPN {
private:
    MutantStack<int> digits;
    std::string data;
public:
    RPN();
    RPN(char *);
    RPN(const std::string);
    ~RPN();
    RPN(const RPN& other);
    RPN& operator=(const RPN& other);

    class BadInputException : public std::exception {
        private :
            std::string _mssg;
        public :
            const char* what() const throw();
            BadInputException(std::string mssg);
            virtual ~BadInputException() throw();
    };


    void parseInput();
    bool validELem(std::string , int);
    void printStack();

};

#endif // RPN_HPP
