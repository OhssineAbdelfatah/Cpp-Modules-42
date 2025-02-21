#include<iostream>
// #include<cstring>
#include"PhoneBook.hpp"

int main()
{
    PhoneBook book;
    while(1)
    {
        std::string buff;

        std::cin >> buff;
        if(buff == "EXIT")
            break;
        else if(buff == "ADD")
            book::add_reocrd();
        std::cout << buff << std::endl;
    }
    return 0;
}