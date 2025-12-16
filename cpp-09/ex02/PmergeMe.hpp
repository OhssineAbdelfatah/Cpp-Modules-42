#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>


class PmergeMe {
        
        
    private:
        std::vector<std::string> _seq;
        std::vector<int> _seqVec;
        std::vector<std::pair<int, int> > _seqVecPair;
        int nbrArr;
        int RemindedInt;

        class BadInputException : public std::exception {
            private :
                std::string _mssg;
            public :
                const char* what() const throw();
                BadInputException(std::string mssg);
                virtual ~BadInputException() throw();
        };
        
        void stroreSeqVect();
        void creatVectPairs();
        void SortVectPairs();


    public:
        PmergeMe();
        void MergeInsertVect(char**args ,int ac);
        void MergeInsertDque(char**args ,int ac);
        ~PmergeMe();

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        
};

#endif
