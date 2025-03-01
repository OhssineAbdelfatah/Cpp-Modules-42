#include<iostream>
// #include<cstring>
#include"PhoneBook.hpp"
#include"Contacts.hpp"

int main()
{
    Contacts c1;
    Phonebook phone_one;
    
    std::cout << "Welcome to the 80s ,A crappy awesome phonebook >> " << std::endl;
    std::string buff;
    phone_one.contacts_number = 0;
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
            if (phone_one.contacts_number < 8 && phone_one.contacts_number >= 0 ) // getContactNumber()
            {
                phone_one.inst[phone_one.contacts_number].addContact(); // c1.addContact();
                phone_one.contacts_number++; // // setContacts_number(getContactNumber() + 1);
            }
            else{
                phone_one.contacts_number = 0; // setContacts_number(0)
                phone_one.inst[phone_one.contacts_number].addContact();
            } 

        }
        else if(buff == "SEARCH" || buff == "search")
            phone_one.inst[1].printContact(); //c1.printContact();
    }
    return 0;
}
