#include<iostream>
// #include<cstring>
#include"PhoneBook.hpp"
#include"Contacts.hpp"

int main()
{
    Contacts c1;
    PhoneBook phoneOne;
    std::cout << "Welcome to the 80s ,A crappy awesome phonebook >> " << std::endl;
    std::string buff;
    // phone_one.contacts_number = 0;
    while(1)
    {
        std::cout << "Enter a command : (ADD / SEARCH / EXIT)" << std::endl;
        //if(!std::getline(std::cin,  buff))
          //  break;
        std::getline(std::cin,  buff);
        if(std::cin.eof()){
            std::cout << "end of file reached !! or you enter cntrl D " << std::endl;
            break;
        }
        if(buff == "EXIT" || buff == "exit")
            break;
        else if(buff == "ADD" || buff == "add"){
            // if (phone_one.getContactsNumber() < 8 && phone_one.getContactsNumber() >= 0 ) // getContactNumber()
            // {
            //     phone_one.getInst[phone_one.getContactsNumber()].addContact(); // c1.addContact();
            //     phone_one.getContactsNumber()++; // // setContacts_number(getContactNumber() + 1);
            // }
            // else{
            //     phone_one.getContactsNumber() = 0; // setContacts_number(0)
            //     phone_one.inst[phone_one.getContactsNumber()].addContact();
            // } 
            phoneOne.addContact();
        }
        else if(buff == "SEARCH" || buff == "search")
            phoneOne.printContact(); //c1.printContact();
    }
    return 0;
}
