#include "PhoneBook.hpp"
#include "Contacts.hpp"

// Constructor to initialize contactsNumber
PhoneBook::PhoneBook() : contactsNumber(0) {}

// Add a contact to the PhoneBook
// void PhoneBook::setInst(Contacts cont) {
//     if (contactsNumber < 8) { // Ensure we don't exceed the array size
//         inst[contactsNumber] = cont;
//         contactsNumber++; // Increment the contact count
//     } else {
//         // Handle the case when the PhoneBook is full
//         // You can throw an exception or print an error message
//         std::cerr << "PhoneBook is full! Cannot add more contacts." << std::endl;
//     }
// }

void PhoneBook::addContact()
{
    Contacts c1;
    std::string fn;
    std::cout << "First Name " << std::endl;
    std::getline(std::cin, fn);

    std::string ln;
    std::cout << "Last Name " << std::endl;
    std::getline(std::cin, ln);
    std::string nn;
    std::cout << "Nick Name " << std::endl;
    std::getline(std::cin, nn);

    std::string pn;
    std::cout << "phone Number " << std::endl;
    std::getline(std::cin, pn);

    std::string ds;
    std::cout << "darkest Secret " << std::endl;
    std::getline(std::cin, ds);

    // if(std::cin.eof() || !validInput(fn) || ln.empty() || nn.empty() || pn.empty() || ds.empty())
    //  if(std::cin.eof() || !validInput(fn) || !validInput(ln) ||  !validInput(nn) ||  !validInput(pn) || !validInput(ds))
    if (std::cin.eof() || validInput(fn).empty() || validInput(ln).empty() || validInput(nn).empty() || validInput(pn).empty() || validInput(ds).empty())
    {
        std::cout << "empty filed : contact ignored" << std::endl;
        return;
    }
    c1.setFirstName( validInput(fn));
    c1.setLastName( validInput(ln));
    c1.setNickName( validInput(nn));
    c1.setPhoneNumber( validInput(pn));
    c1.setDarkestSecret( validInput(ds));
    // if(this->contactsNumber > 7)
        // this->contactsNumber = 0;
    this->inst[this->contactsNumber % 8] = c1;
    std::cout << "***********before add" <<  contactsNumber << std::endl; 
    this->contactsNumber++;
    std::cout << "***********after add" << contactsNumber << std::endl; 
}
// Get a contact by index

void PhoneBook::setInst(Contacts cnt)
{
    inst[contactsNumber ].setFirstName(cnt.getFirstName());
    inst[contactsNumber].setLastName(cnt.getLastName());
    inst[contactsNumber].setNickName(cnt.getNickName());
    inst[contactsNumber].setPhoneNumber(cnt.getPhoneNumber());
    inst[contactsNumber].setDarkestSecret(cnt.getDarkestSecret());
    // if (contactsNumber >= 0 && 8 > contactsNumber) { // Ensure the index is valid
    // inst[contactsNumber] = cnt;
    // } else{
    // }
    contactsNumber++;
}

Contacts PhoneBook::getInst(int index)
{
    return inst[index];
}

// Set the number of contacts
void PhoneBook::setContactsNumber(int value)
{
    contactsNumber = value;
}

// Get the number of contacts
int PhoneBook::getContactsNumber()
{
    return contactsNumber;
}

// int PhoneBook::setContactsNumber(){
//     return contactsNumber;
// }

void PhoneBook::printContact()
{
    int i;
    int last;

    last = 8;
    if(this->contactsNumber < 8)
        last = this->contactsNumber;   
    i = 0;
    std::cout << "-------------------------------------------------------" << std::endl;
    std::cout << "|First Name|Last Name |NickName |Phone Num|Darkest Secret|"   << std::endl;
    while (i < last)
    {
        std::cout << "|" << inst[i].getFirstName() << "|";
        std::cout << inst[i].getLastName()      << "|";
        std::cout << inst[i].getNickName()      << "|";
        std::cout << inst[i].getPhoneNumber()   << "|";
        std::cout << inst[i].getDarkestSecret() << "|";
        std::cout << std::endl;
        i++;
    }
    std::cout << "-------------------------------------------------------" << std::endl;
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
        return NULL;
    return rightTrim;
}
