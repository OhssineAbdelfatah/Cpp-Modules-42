#include<iostream>
// #include<cstring>
#include"PhoneBook.hpp"
#include"Contacts.hpp"

int main()
{
    Contacts c1;
    std::cout << "Welcome to the 80s ,A crappy awesome phonebook >> " << std::endl;
    std::string buff;
    while(1)
    {
        std::cout << "Enter a command : (ADD / SEARCH / EXIT)" << std::endl;
        //if(!std::getline(std::cin,  buff))
          //  break;
        std::getline(std::cin,  buff);
        if(std::cin.eof())
            break;
        if(buff == "EXIT" || buff == "exit")
            break;
        else if(buff == "ADD" || buff == "add")
            c1.addContact();
        else if(buff == "SEARCH" || buff == "search")
            c1.printContact();
    }
    return 0;
}
