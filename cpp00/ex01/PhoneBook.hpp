#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#include"Contacts.hpp"


class Phonebook {
    private :
        // Con contact[8];
        Contacts inst[8];
        int contactsNumber;

    public :
    Contacts[8] getInst();
    void getInst(Contacts inst);
    int getContactsNumber();
    void setContactsNumber(int value);
    //     int getBookSize() const;
    //     void setBookSize(int size);
};

#endif 