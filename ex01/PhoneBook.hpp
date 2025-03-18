#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contacts.hpp"


class PhoneBook {
    private :
        // Con contact[8];
        Contacts inst[8];
        int contactsNumber;
        
        // if method is not used outside class base , then should be private
	    std::string validInput(std::string value);
        std::string formatColumn(std::string text);

    public :
        PhoneBook();
        void addContact();
        void printContacts();
        void printContact(int index);

        int getContactsNumber();
};

#endif 