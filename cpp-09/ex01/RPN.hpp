#ifndef RPN_HPP
#define RPN_HPP

#include<list>
#include<string>
#include<iostream>
#include<algorithm>

class RPN {
private:
    std::list<char> tokens;
    std::string data;
public:
    RPN();
    RPN(char *);
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

};

#endif // RPN_HPP
