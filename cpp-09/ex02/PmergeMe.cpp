#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(char**args ,int ac):  nbrArr(ac){
    // Constructor implementation
    for(int i = 1; i < nbrArr; i++)
        _seq.push_back(args[i]);
    stroreSeq();
}

PmergeMe::~PmergeMe() {
    // Destructor implementation
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    // Copy constructor implementation
}

const char* PmergeMe::BadInputException::what() const throw(){return _mssg.c_str();}
PmergeMe::BadInputException::BadInputException(std::string mssg) : _mssg(mssg){}
PmergeMe::BadInputException::~BadInputException() {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    // Copy assignment operator implementation
    if (this != &other) {
        // Perform deep copy
    }
    return *this;
}

void PmergeMe::stroreSeq(){
    
}

void PmergeMe::parseInput(){
    for(std::vector<std::string>::iterator it = _seq.begin(); it != _seq.end(); it++){
        if(it->empty() || it->find_first_not_of(' ') == std::string::npos )
            throw PmergeMe::BadInputException("ERROR");
        for(int i = 0 ; (size_t)i < it->size(); i++){
            ;
        }
    }
}

