#include <iostream>
#include <sstream>
#include"PhoneBook.hpp"
#include"Contacts.hpp"

int main()
{
    PhoneBook phoneOne;
    std::cout << "Welcome to the 80s ,A crappy awesome phonebook >> " << std::endl;
    std::string buff;
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
        else if(buff == "ADD" )
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
                std::stringstream oss; 
                oss << std::atoi(buff.c_str()); 
                if(oss.str().length() != buff.length() || std::atoi(buff.c_str()) > 8 || std::atoi(buff.c_str()) <=0 || std::atoi(buff.c_str()) > phoneOne.getContactsNumber() )
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
