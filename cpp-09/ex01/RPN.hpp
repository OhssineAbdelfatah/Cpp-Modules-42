#ifndef RPN_HPP
#define RPN_HPP

#include<list>
#include<string>

class RPN {
private:
    std::list<char> tokens;

public:
    RPN();
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

};

#endif // RPN_HPP
