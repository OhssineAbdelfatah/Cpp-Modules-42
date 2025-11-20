#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char**args ,int ac):  nbrArr(ac){
    // Constructor implementation
    for(int i = 1; i < nbrArr; i++)
        _seq.push_back(args[i]);
    stroreSeq();
    test(_seq[1]);

}

PmergeMe::~PmergeMe() {
    // Destructor implementation
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    // Copy constructor implementation
    *this = other;
}

const char* PmergeMe::BadInputException::what() const throw(){return _mssg.c_str();}
PmergeMe::BadInputException::BadInputException(std::string mssg) : _mssg(mssg){}
PmergeMe::BadInputException::~BadInputException() throw() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    // Copy assignment operator implementation
    if (this != &other) {
        // Perform deep copy
    }
    return *this;
}

void PmergeMe::stroreSeq(){
    ;
}

void PmergeMe::parseInput(){
    for(std::vector<std::string>::iterator it = _seq.begin(); it != _seq.end(); it++){
        if(it->empty() || it->find_first_not_of(' ') == std::string::npos )
            throw PmergeMe::BadInputException("ERROR");
        while(1){
            size_t start , end;
            if( ( start = it->find_first_of("0123456789+"))  == std::string::npos )
                throw PmergeMe::BadInputException("Empty String");
            if( ( end = it->find_last_of("0123456789+"))  == std::string::npos )
                throw PmergeMe::BadInputException("Empty String");
            std::string value = it->substr(start , end);
            std::cout << value << std::endl;
            start = end;
            if(start == it->size())
                break;
        }
    }
}

void PmergeMe::test(std::string token){
    if(token.empty() || token.find_first_not_of(' ') == std::string::npos )
            throw PmergeMe::BadInputException("ERROR");
        while(1){
            size_t start , end;
            if( ( start = token.find_first_of("0123456789+"))  == std::string::npos )
                throw PmergeMe::BadInputException("Empty String");
            if( ( end = token.find_last_of("0123456789+"))  == std::string::npos )
                throw PmergeMe::BadInputException("Empty String");
            std::string value = token.substr(start , end);
            std::cout << value << std::endl;
            start = end;
            if(start == token.size())
                break;
    }
}

