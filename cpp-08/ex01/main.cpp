#include "Span.hpp"
#include <iostream>
#include <cstdlib>



void tryOverFlowNumbers(){
    int size = 15;
    Span sp(size);

    try{
        for(int i = size+1 ; i > 0 ; i-- )
            sp.addNumber(rand() );
    }
    catch(const Span::SpanOverflowException &e){
        std::cout << std::endl << e.what() << std::endl;
    }   

}

void tryGetSpanSingleElem(){
    int size = 1;
    Span sp(size);

    try{
        for(int i = size ; i > 0 ; i-- )
            sp.addNumber(rand() );
        std::cout << sp.shortestSpan() << std::endl;
    }
    catch(const Span::SpanSingleElemException &e){
        std::cout << std::endl << e.what() << std::endl;
    }   

}

void testAddNumbers(){
  std::vector<int> range;
    range.push_back(1);
    range.push_back(2);
    range.push_back(5);
    range.push_back(7);
    
    std::vector<int> range1;
    range1.push_back(1);
    range1.push_back(2);
    range1.push_back(5);
    range1.push_back(7);
    range.insert(range.end(), range1.begin(), range1.end());
    std::cout << "start print vector" << std::endl;
    for (std::vector<int>::iterator it = range.begin() ; it != range.end() ; it++ )
    std::cout <<*it << " " ;
    std::cout << "end print vector" << std::endl;
}

int main1()
{
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    return 0;
}

int main(){
    // tryOverFlowNumbers();
    // tryGetSpanSingleElem();
    // main1();
    testAddNumbers();
}