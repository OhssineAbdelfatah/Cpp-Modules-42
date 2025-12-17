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
        std::vector<std::string> _seq;
        std::vector<int> _seqVec;
        std::vector<std::pair<int, int> > _seqVecPair;
        std::vector<int> _vectMain;
        std::vector<int> _vectPend;
        std::vector<int> _indexes;
        std::vector<int> _jsIndexes;

        std::deque<std::string> _seqD;
        std::deque<int> _seqDeq;
        std::deque<std::pair<int, int> > _seqDeqPair;
        std::deque<int> _deqMain;
        std::deque<int> _deqPend;
        std::deque<int> _indexesDeq;
        std::deque<int> _jsIndexesDeq;

        
        void storeSeqVect();
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
        
        void storeSeqDeq();
        void creatDeqPairs();
        void SortDeqPairs();
        void MergeSortDeq(std::deque<std::pair<int ,int> >& , int , int);
        void MergeDeq(std::deque<std::pair<int ,int> >& ,int , int  , int );
        void generatMainPendDeq();
        void insertToMainDeq();
        int binarySearchDeq(std::deque<int> , int, int, int);
        void generateIndexesDeq();
        void jacobstalSequenceDeq();

        class BadInputException : public std::exception {
            private :
                std::string _mssg;
            public :
                const char* what() const throw();
                BadInputException(std::string mssg);
                virtual ~BadInputException() throw();
        };

    public:
        std::deque<int> getDeque() const ;
        std::vector<int> getVect() const ;
        std::vector<int> getVectSeq() const ;

        void printDeque(std::deque<int> );
        void printVector(std::vector<int> );
        PmergeMe();
        void MergeInsertVect(char**args ,int ac);
        void MergeInsertDque(char**args ,int ac);
        ~PmergeMe();

        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        
};

#endif
