#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include<string>
#include<sstream>
#include<vector>
#include<deque>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<utility>


class PmergeMe {
        
        
    private:

        int nbrArr;
        std::vector<std::string> _seq;
        std::vector<int> _seqVec;
        std::vector<std::pair<int, int> > _seqVecPair;
        std::vector<int> _vectMain;
        std::vector<int> _vectPend;
        std::vector<int> _indexes;
        std::vector<int> _jsIndexes;

        std::deque<std::string> _seqD;
        std::vector<int> _seqDeq;
        std::vector<std::pair<int, int> > _seqDeqPair;
        std::vector<int> _deqMain;
        std::vector<int> _deqPend;

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
        void MergeSort(std::vector<std::pair<int ,int> >& , int , int);
        void Merge(std::vector<std::pair<int ,int> >& ,int , int  , int );
        void generatMainPend();
        void insertToMain();
        void generateIndexes();
        void jacobstalSequence();
        int jacobstalIndex(int index);
        int binarySearch(std::vector<int> , int, int, int);
        void printVector(std::vector<int>& vect);

        void stroreSeqDeq();
        void creatDeqPairs();
        void SortDeqPairs();
        void MergeSortDeq(std::Deque<std::pair<int ,int> >& , int , int);
        void MergeDeq(std::Deque<std::pair<int ,int> >& ,int , int  , int );
        void generatMainPendDeq();
        void insertToMainDeq();
        int binarySearchDeq(std::Deque<int> , int, int, int);
        void printDeque(std::Deque<int>& vect);





    public:
        PmergeMe();
        void MergeInsertVect(char**args ,int ac);
        void MergeInsertDque(char**args ,int ac);
        ~PmergeMe();

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        
};

#endif
