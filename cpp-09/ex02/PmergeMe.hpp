#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<string>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<pair>

class PmergeMe {
    public:
        PmergeMe(char** ,int );
        ~PmergeMe();

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        void stroreSeq();
        
        
        
    private:
        std::vector<std::string> _seq;
        std::vector<int> _seqVec;
        int nbrArr;

        class BadInputException : public std::exception {
            private :
                std::string _mssg;
            public :
                const char* what() const throw();
                BadInputException(std::string mssg);
                virtual ~BadInputException() throw();
        };
        
        PmergeMe();
        void parseInput();
};

#endif
