#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook() : contactsNumber(0) {}

std::string PhoneBook::formatColumn(std::string text) {
    if (text.length() > 10) {
        return text.substr(0, 10 - 1) + ".";
    }
    return std::string(10 - text.length(), ' ') + text;
}

void PhoneBook::addContact()
{
    Contacts c1;
    std::string fn;
    std::cout << "First Name " << std::endl << "---->";
    std::getline(std::cin, fn);

    std::string ln;
    std::cout << "Last Name " << std::endl << "---->";
    std::getline(std::cin, ln);

    std::string nn;
    std::cout << "Nick Name " << std::endl << "---->";
    std::getline(std::cin, nn);

    std::string pn;
    std::cout << "phone Number " << std::endl << "---->";
    std::getline(std::cin, pn);

    std::string ds;
    std::cout << "darkest Secret " << std::endl << "---->";
    std::getline(std::cin, ds);

    if ( std::cin.eof() || validInput(fn).empty() || validInput(ln).empty() || validInput(nn).empty() || validInput(pn).empty() || validInput(ds).empty())
    {
        std::cout << "empty filed : contact ignored" << std::endl;
        return;
    }
    c1.setFirstName( validInput(fn));
    c1.setLastName( validInput(ln));
    c1.setNickName( validInput(nn));
    c1.setPhoneNumber( validInput(pn));
    c1.setDarkestSecret( validInput(ds));
    this->inst[this->contactsNumber % 8] = c1;
    this->contactsNumber++;
}

int PhoneBook::getContactsNumber()
{
    return contactsNumber;
}

void PhoneBook::printContact(int index)
{
    std::cout << "First Name : " << inst[index].getFirstName() << std::endl;
    std::cout << "Last Name : " << inst[index].getLastName() << std::endl;
    std::cout << "NickName : " << inst[index].getNickName() << std::endl;
    std::cout << "Phone Number : " << inst[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret : " << inst[index].getDarkestSecret() << std::endl << std::endl << std::endl;
}

void PhoneBook::printContacts()
{
    int i;
    int last;

    last = 8;
    if(this->contactsNumber < 8)
        last = this->contactsNumber;   
    i = 0;
    std::cout << "---------------------------------------------" << std::endl;
    std::cout << "|     index|first name| last name|  NickName|"   << std::endl;
    while (i < last)
    {
        std::cout << "|" << "         "<< i+1  << "|";
        std::cout << formatColumn(inst[i].getFirstName()) << "|";
        std::cout << formatColumn(inst[i].getLastName()) << "|";
        std::cout << formatColumn(inst[i].getNickName() ) << "|";
        std::cout << std::endl;
        i++;
    }
    std::cout << "---------------------------------------------" << std::endl;
}

std::string PhoneBook::validInput(std::string value)
{
    const std::string whiteSpace = " \n\r\t\f\v";
    std::string leftTrim;

    if (value.empty())
        return "";
    size_t start = value.find_first_not_of(whiteSpace);
    if (start == std::string::npos)
        return "";
    leftTrim = value.substr(start);
    std::string rightTrim = leftTrim.substr(0, leftTrim.find_last_not_of(whiteSpace) + 1);
    if (rightTrim.length() == 0)
        return "";
    return rightTrim;
}
