#include<iostream>
# include <algorithm>
# include <vector>
# include <list>
#include"Easyfind.hpp"


// concepts 
/*
vectors 
iterators
list

*/

int main()
{
    std::vector<int> c1;

    for(int i = 0; i < 10 ; i++)
        c1.push_back(i*3);

    for ( std::vector<int>::iterator it = c1.begin(); it != c1.end(); ++it )
        std::cout << "list "<< *it << std::endl;

    try{
        std::cout << easyfind(c1, 2) << std::endl;
    }catch(std::exception &e){
        std::cerr << e.what() << " value not found "<< std::endl;
    }
    
    try{
        std::cout << "value found " << easyfind(c1, 0) << std::endl;
    }catch(std::exception &e){
        std::cerr << e.what() << " value not found "<< std::endl;
    }

    std::list<int> myList;
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);
    myList.push_back(40);

    for ( std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it)
        std::cout << "list "<< *it << std::endl;
    
    try{
        std::cout << "value found "<< easyfind(myList, 2) << std::endl;
    }catch(std::exception &e){
        std::cerr << e.what() << " value not found "<< std::endl;
    }
    
    try{
        std::cout << "value found " << easyfind(myList, 10) << std::endl;
    }catch(std::exception &e){
        std::cerr << e.what() << " value not found "<< std::endl;
    }
} 