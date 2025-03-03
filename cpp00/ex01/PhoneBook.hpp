#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include "Contacts.hpp"

class PhoneBook {
    private :
        // Con contact[8];
        Contacts inst[8];
        int contactsNumber;

    public :
        // PhoneBook();
        void addContact();
        void printContact();
	    std::string validInput(std::string value);

        void setInst(Contacts cont);
        Contacts getInst(int index);
        void setContactsNumber(int value);
        int getContactsNumber();
};

#endif 