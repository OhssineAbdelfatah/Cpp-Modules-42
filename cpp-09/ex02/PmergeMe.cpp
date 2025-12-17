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

void PmergeMe::stroreSeqVect(){
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
            // std::cout << "value ["<< value <<"]"<< std::endl;
            if (value.find_first_not_of(set) != std::string::npos )
                throw PmergeMe::BadInputException("Bad input...");
            int ii;
            std::istringstream(value) >> ii;
            std::ostringstream test ;
            test << ii;
            if(ii != 0){
                value = value.substr(value.find_first_not_of('0'));
                if(test.str().size() != ((value[0] == '+') ? value.size() -1 : value.size()))
                    throw PmergeMe::BadInputException("Number overflow");
            }
            _seqVec.push_back(ii);
            start = end;
            if(( start = token->find_first_not_of(' ', start))  == std::string::npos ){
                // std::cout << "Did i breaked !! " << std::endl;
                break;
            }
        }
    }

    // std::cout << "Print SeqVector "<< std::endl;
    // for(std::vector<int>::iterator it = _seqVec.begin() ; it != _seqVec.end() ; it++ )
    //     // std::cout << " >> " << *it << std::endl;
}

void PmergeMe::printVector(std::vector<int>& vect){
    std::vector<int>::iterator it = vect.begin();
    for ( ; it != vect.end() ; it++)
        std::cout << *it << " ";
    std::cout << std::endl;

}

void PmergeMe::MergeInsertVect(char**args ,int ac){
    for(int i = 0; i < ac-1; i++){
    // empty string checked here
        if(args && strlen(args[i]) == 0)
            continue;
        _seq.push_back(args[i]);
    }
    stroreSeqVect();
    std::cout << "Before ..." << std::endl;
    printVector(_seqVec);
    
    creatVectPairs();
    SortVectPairs();
    MergeSort(_seqVecPair, 0 , _seqVecPair.size()-1);

    // debug
    // std::vector<std::pair<int , int > >::iterator it1 = _seqVecPair.begin();
    // for ( ; it1 != _seqVecPair.end() ; it1++)
    //     std::cout << it1->first  << ":v:" << it1->second << std::endl;;
    // std::cout << std::endl;
    // debug

    generatMainPend();
    insertToMain();
    std::cout << "After ..." << std::endl;
    printVector(_vectMain);
}

int PmergeMe::jacobstalIndex(int index){
    if(index == 0)
        return 0;
    if (index == 1)
        return 1;
    return (jacobstalIndex(index -1) + 2 * jacobstalIndex(index - 2));
}

void PmergeMe::jacobstalSequence(){
    int index = 3;
    int size = _vectPend.size();
    int jacobStalIndex;
    while( (jacobStalIndex = jacobstalIndex(index)) < size - 1 ){
        _jsIndexes.push_back(jacobStalIndex);
        index++;
    }   

}

void PmergeMe::generateIndexes(){
    if(_vectPend.empty())
        return ;
    jacobstalSequence();

    // std::cout << " jacobstal " << std::endl;
	// std::vector<int>::iterator itt = _jsIndexes.begin();
    // for ( ; itt != _jsIndexes.end() ; itt++)
    //     std::cout << *itt << " ";
    // std::cout << std::endl;

    size_t i = 0;
    size_t val = 1;
    int pos;
    int lastPos = 1;
    while(i < _jsIndexes.size()){
        val = _jsIndexes.at(i);
        _indexes.push_back(val);
        pos = val - 1;
        while(pos > lastPos){
            _indexes.push_back(pos);
            pos--;
        }
        lastPos = val;
        i++;
    }
    while (val++ < this->_vectPend.size())
		this->_indexes.push_back(val);
}

int PmergeMe::binarySearch(std::vector<int> array, int target , int start , int end){
    int middle;

    while(start <= end){
        middle = start + (end - start ) / 2;
        if( target == array.at(middle) )
            return middle;
        if ( target > array.at(middle) )
            start = middle + 1;
        else 
            end = middle - 1;
    }
    if (target > array.at(middle))
		return ( middle + 1 );
	else
		return ( middle );
}

void PmergeMe::insertToMain(){
    generateIndexes();

    // std::cout << " Positions " << std::endl;
	// std::vector<int>::iterator itt = _indexes.begin();
    // for ( ; itt != _indexes.end() ; itt++)
    //     std::cout << *itt << " ";
    // std::cout << std::endl;

    std::vector<int>::iterator it;
    int target;
    int count = 0 ;
    int lastPos ;
    int pos  ;
    for ( it = _indexes.begin() ; it != _indexes.end() ; it++){
        target = _vectPend.at( *it - 1 );
        lastPos = *it + count;
        pos = binarySearch(_vectMain, target , 0 , lastPos);
        _vectMain.insert(_vectMain.begin() + pos , target);
    }
    
    if(_seqVec.size() % 2 != 0){
        target = _seqVec.at(_seqVec.size() - 1);
        pos = binarySearch(_vectMain, target , 0 , _vectMain.size() - 1 );
        _vectMain.insert(_vectMain.begin() + pos , target);
    } 
}

void PmergeMe::generatMainPend(){

    _vectMain.push_back(_seqVecPair.at(0).second);
    size_t i = 0;
    for ( i = 0 ; i < _seqVecPair.size() ; i++)
    {
        _vectMain.push_back(_seqVecPair.at(i).first);
        _vectPend.push_back(_seqVecPair.at(i).second);
    }
    // std::cout << "vector pairs size"<<  _seqVecPair.size() <<  std::endl;;
    // std::vector<std::pair<int , int > >::iterator it1 = _seqVecPair.begin();
    // for ( ; it1 != _seqVecPair.end() ; it1++)
    //     std::cout << it1->first  << ":v:" << it1->second << std::endl;;
    // std::cout << std::endl;
    // std::cout << "Main"<< std::endl;
    // printVector(_vectMain);
    // std::cout << "Pend"<< std::endl;
    // printVector(_vectPend);
}


void PmergeMe::creatVectPairs(){
    size_t size = _seqVec.size() / 2;
    int i = 0;
    while(size){
        _seqVecPair.push_back(std::pair<int, int>(_seqVec[i], _seqVec[i+1]));
        i += 2;
        size--;
    }
}

void PmergeMe::SortVectPairs(){
    std::vector<std::pair<int , int> >::iterator it = _seqVecPair.begin();
    int tmp;
    for (; it != _seqVecPair.end(); it++)
    {
        if(it->first < it->second){
            tmp = it->first;
            it->first = it->second;
            it->second = tmp;
        }
        std::cout << "[" << it->first << " , " << it->second << "]"<< std::endl;
    }
}


void PmergeMe::MergeSort(std::vector<std::pair<int ,int> >& vectorPiars, int start, int end)
{
    if(start >= end){
        // std::cout << "Return  start " << start << " ,end " << end <<  std::endl;
        return ;
    }
    int mid = start + (end - start ) / 2;
    MergeSort(vectorPiars, start, mid);
    MergeSort(vectorPiars, mid + 1, end);
    Merge(vectorPiars, start , mid , end);
}

void    PmergeMe::Merge(std::vector<std::pair<int ,int> >& vectorPiars, int start, int mid , int end){
    size_t leftVectIndex = 0 ;
    size_t rightVectIndex = 0 ;
    size_t mergedVectorIndex = start ;

    std::cout << "start " << start << std::endl;
    std::vector<std::pair<int, int > > leftVector(vectorPiars.begin() , vectorPiars.begin() + mid + 1);
    std::vector<std::pair<int, int > > rightVector(vectorPiars.begin() + mid + 1 , vectorPiars.begin() + end + 1 );

    // // debug 
    // std::vector<std::pair<int , int > >::iterator it1 = leftVector.begin();
    // for ( ; it1 != leftVector.end() ; it1++)
    //     std::cout << it1->first  << "::" << it1->second;
    // std::cout << std::endl;
    
    // std::vector<std::pair<int , int > >::iterator it2 = rightVector.begin();
    // for ( ; it2 != rightVector.end() ; it2++)
    //     std::cout << it2->first  << ":" << it2->second;
    // std::cout << std::endl;
    // // debug 


    while(leftVectIndex < leftVector.size() && rightVectIndex < rightVector.size()){
        if(leftVector[leftVectIndex].first <= rightVector[rightVectIndex].first){
            vectorPiars[mergedVectorIndex] = leftVector[leftVectIndex];
            leftVectIndex++;            
        }else{
            vectorPiars[mergedVectorIndex] = rightVector[rightVectIndex];
            rightVectIndex++;            
        }
        mergedVectorIndex++;
    }
    std::cout << "***mergedIndex " << mergedVectorIndex << std::endl;
    while(leftVectIndex < leftVector.size()){
        std::cout << "leftIndex " << leftVectIndex << std::endl;
        vectorPiars[mergedVectorIndex] = leftVector[leftVectIndex];
        leftVectIndex++;
        // mergedVectorIndex++;
    }
    while(rightVectIndex < rightVector.size()){
        // std::cout << "***mergedIndex " << mergedVectorIndex << std::endl;
        std::cout << "rightIndex " << rightVectIndex << std::endl;
        vectorPiars[mergedVectorIndex] = rightVector[rightVectIndex];
        rightVectIndex++;
        mergedVectorIndex++;
    }
}



void MergeInsertDque(char**args ,int ac){
    (void)args;
    (void)ac;
}   