#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::~PmergeMe() {
    // Destructor implementation
}

PmergeMe::PmergeMe(const PmergeMe& other) {
    // Copy constructor implementation
    *this = other;
}

PmergeMe::PmergeMe(char**args ,int ac):  nbrArr(ac-1){
    // Constructor implementation
    for(int i = 0; i < nbrArr; i++){
        // empty string checked here
        if(args && strlen(args[i]) == 0)
            continue;
        _seq.push_back(args[i]);
    }
    stroreSeq();
    test(_seq[0]);

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
    std::string set("0123456789+");
    size_t start = 0, end = 0;
    for(size_t i = 0 ; i < token.size() ; i++){
        if( ( start = token.find_first_of(set, start))  == std::string::npos )
            throw PmergeMe::BadInputException("Empty String start");
        if( ( end = token.find_first_of(' ', start))  == std::string::npos )
            throw PmergeMe::BadInputException("Empty String end");
        int size = end - start;
        std::string value = token.substr(start , size);
        std::cout << "value ["<< value <<"]"<< std::endl;
        if (value.find_first_not_of(set) != std::string::npos )
        throw PmergeMe::BadInputException("Bad input...");
        int ii;
        std::istringstream(token) >> ii;
        _seqVec.push_back(ii);
        start = end;
        std::cout << "+++["<< start <<"] [" << token.size() << "]"<< std::endl;
        if( ( start = token.find_first_not_of(' ', start))  == std::string::npos )
            break;
    }
}

