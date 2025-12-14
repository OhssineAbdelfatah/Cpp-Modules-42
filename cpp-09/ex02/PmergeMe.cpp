#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

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

PmergeMe::PmergeMe(char**args ,int ac):  nbrArr(ac-1){
    // Constructor implementation
    for(int i = 0; i < nbrArr; i++){
        // empty string checked here
        if(args && strlen(args[i]) == 0)
            continue;
        _seq.push_back(args[i]);
    }
    stroreSeq();
}



void PmergeMe::stroreSeq(){
    std::string set("0123456789+");
    std::vector<std::string>::iterator token = _seq.begin();
    for(; token != _seq.end() ; token++){
        size_t start = 0, end = 0;
        for(size_t i = 0 ; i < token->size() ; i++){
            if( ( start = token->find_first_not_of(' ', start))  == std::string::npos )
                throw PmergeMe::BadInputException("Empty String start");
            // std::cout << "start["<< start << "]";
            end = token->find_first_of(' ', start);
            if( end  == std::string::npos && start != token->size() -1)
                end = token->size();
            // std::cout << "end["<< end << "]" << std::endl;
            int size = end - start;
            std::string value = token->substr(start , size);
            std::cout << "value ["<< value <<"]"<< std::endl;
            if (value.find_first_not_of(set) != std::string::npos )
                throw PmergeMe::BadInputException("Bad input...");
            int ii;
            std::istringstream(value) >> ii;
            std::ostringstream test ;
            test << ii;

            if(test.str().size() != ((value[0] == '+') ? value.size() -1 : value.size()))
                throw PmergeMe::BadInputException("Number overflow");
            _seqVec.push_back(ii);
            start = end;
            if(( start = token->find_first_not_of(' ', start))  == std::string::npos ){
                std::cout << "Did i breaked !! " << std::endl;
                break;
            }
        }
    }

    std::cout << "Print SeqVector "<< std::endl;
    for(std::vector<int>::iterator it = _seqVec.begin() ; it != _seqVec.end() ; it++ )
        std::cout << " >> " << *it << std::endl;
}

