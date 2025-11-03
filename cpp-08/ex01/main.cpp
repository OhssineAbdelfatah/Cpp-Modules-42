#include "Span.hpp"
#include <iostream>
#include <cstdlib>



void tryOverFlowNumbers(){
    int size = 15;
    Span sp(size);

    try{
        for(int i = 0 ; i < size ; i++ )
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


void addRange(){
    Span sp(10);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(90);
    sp.addNumber(11);

    std::vector<int> rng;
    rng.push_back(111);
    rng.push_back(111);
    rng.push_back(110);
    rng.push_back(1110);
    rng.push_back(11101);
    try{
        sp.addNumbers(rng.begin(), rng.end());
    }catch (std::exception &e)
    {
        std::cout << std::endl << e.what() << std::endl;
    }
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
    tryOverFlowNumbers();
    tryGetSpanSingleElem();
    main1();
    addRange();
}