#include<iostream>
#include"Iter.hpp"

void printelem(int& i){
    std:: cout << i << std::endl;
}

void printWord(std::string& i){
    std:: cout << i << std::endl;
}   


int main(  )
{
    std::string array[] = {"abde", "ohss","zaka" ,"lina"};
    int arrayint[] = { 5 ,22, 44 , 68};

    iter(arrayint, sizeof(arrayint)/sizeof(arrayint[0]) , printelem);
}