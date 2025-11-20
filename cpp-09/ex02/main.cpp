#include<iostream>
#include"PmergeMe.hpp"

int main(int ac , char *av[])
{
    if(ac  >  2 ){
        PmergeMe(std::string(av[1]), ac);
    }else 
        std::cerr << "No Input ..." << std::endl;
}