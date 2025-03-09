#include <iostream>
#include <sstream>
// #include<cstring>
#include"PhoneBook.hpp"
#include"Contacts.hpp"


void ll(){

    system("leaks -q phonebook");
}
int main()
{
    atexit(ll);
    Contacts c1;
    PhoneBook phoneOne;
    std::cout << "Welcome to the 80s ,A crappy awesome phonebook >> " << std::endl;
    std::string buff;
    // phone_one.contacts_number = 0;
    while(1)
    {
        std::cout << ">>Enter a command : (ADD / SEARCH / EXIT)" << std::endl  << "-->";
        std::getline(std::cin,  buff);
        if(std::cin.eof()){
            std::cout << "End of file reached !! or you enter cntrl D " << std::endl;
            break;
        }
        if(buff == "EXIT" )
            break;
        else if(!buff.compare("ADD" ))
            phoneOne.addContact();
        else if(buff == "SEARCH" )
        {
            if(phoneOne.getContactsNumber() == 0)
            {
                std::cout << "Empty PhoneBook add some Contacts" << std::endl;
                continue;
            }
            phoneOne.printContacts();
            while(1)
            {
                std::cout << "index ->  " ;
                std::cin >> buff;
                if(std::cin.eof())
                {
                    std::cout << "End of file reached !! back to main" << std::endl;
                    break;
                }
                
                std::ostringstream oss; 
                oss << std::atoi(buff.c_str()); 
                if(oss.str().length() != buff.length() || std::atoi(buff.c_str()) > 8 || std::atoi(buff.c_str()) <=0 || std::atoi(buff.c_str()) > phoneOne.getContactsNumber() %8)
                {
                    std::cout << "invalid index" << std::endl;
                    continue;
                }
                phoneOne.printContact(std::atoi(buff.c_str()) - 1 );
                break;
            }
            std::cin.ignore();
            continue;
        }
    }
    return 0;
}
