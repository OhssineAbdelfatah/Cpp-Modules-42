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
            if( (*it)[i] != ' '){
                if(validELem(*it, i))
                    throw PmergeMe::BadInputException("ERROR");
            }
        }
    }
}

bool PmergeMe::validELem(std::string str, int index){
    if(str[index] != '*' && str[index] != '/' && str[index] != '-' && str[index] != '+' && !(str[index] >= 48 && str[index] <= 57))
        throw PmergeMe::BadInputException("ERROR");
    if(index > 0 && (size_t)index < str.size()){
        if( index > 0 && index < (int)str.size() -1 &&  (str[index - 1] != ' ' || str[index + 1] != ' ')){
            throw PmergeMe::BadInputException("ERROR");
        }
    }
    return false;
}

const char* PmergeMe::BadInputException::what() const throw(){return _mssg.c_str();}
PmergeMe::BadInputException::BadInputException(std::string mssg) : _mssg(mssg){}
