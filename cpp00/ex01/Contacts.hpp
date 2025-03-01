#ifndef CONTACTS_H
#define CONTACTS_H
#include<iostream>
#include<string>

class Contacts {
    private :
        std::string firstName;
        std::string lastName; 
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;

    public :
        // Contacts();
        void printContact();
        void addContact();
        std::string getFirstName() const;
        void setFirstName(std::string fisrtName);

        std::string getLastName() const;
        void setLastName(std::string lastName);

        std::string getNickName() const;
        void setNickName(std::string nickName);
        
        std::string getPhoneNumber() const;
        void setPhoneNumber(std::string phoneNumber);

        std::string getDarkestSecret() const;
        void setDarkestSecret(std::string darkestSecret);

	    std::string validInput(std::string value);
    
};

#endif 
