#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contacts.hpp"

class PhoneBook {
    private :
        // Con contact[8];
        Contacts inst[8];
        int contactsNumber;

    public :
        PhoneBook();
        void addContact();
        void printContacts();
        void printContact(int index);
	    std::string validInput(std::string value);
        std::string formatColumn(std::string text);

        // void setInst(Contacts cont);
        // Contacts getInst(int index);
        // void setContactsNumber(int value);
        int getContactsNumber();
};

#endif 