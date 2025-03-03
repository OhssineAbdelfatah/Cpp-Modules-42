#include "PhoneBook.hpp"
#include "Contacts.hpp"

// Constructor to initialize contactsNumber
// PhoneBook::PhoneBook() : contactsNumber(0) {}

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
    std::getline(std::cin ,fn );

    std::string ln;
    std::cout << "Last Name " << std::endl;
    std::getline(std::cin, ln );
    std::string nn;
    std::cout << "Nick Name " << std::endl;
    std::getline(std::cin, nn );

    std::string pn;
    std::cout << "phone Number " << std::endl;
    std::getline(std::cin ,pn );

    std::string ds;
    std::cout << "darkest Secret " << std::endl;
    std::getline(std::cin, ds );
    
    //if(std::cin.eof() || !validInput(fn) || ln.empty() || nn.empty() || pn.empty() || ds.empty())
    // if(std::cin.eof() || !validInput(fn) || !validInput(ln) ||  !validInput(nn) ||  !validInput(pn) || !validInput(ds))
    if(std::cin.eof() || validInput(fn).empty() || validInput(ln).empty() || validInput(nn).empty() || validInput(pn).empty() || validInput(ds).empty())
    {
        std::cout << "empty filed : contact ignored" << std::endl ;
        return;
    }
    c1.setFirstName(fn);
    // c1.setLastName(ln);
    // c1.setNickName(nn);
    // c1.setPhoneNumber(pn);
    // c1.setDarkestSecret(ds);
    // setInst(c1);
}
// Get a contact by index

void PhoneBook::setInst(Contacts cnt) {
    if (contactsNumber >= 0 && 8 > contactsNumber) { // Ensure the index is valid
        inst[contactsNumber] = cnt;
    } else{
        inst[contactsNumber%7] = cnt;
    }
    contactsNumber++;
}

Contacts PhoneBook::getInst() {
    return inst[contactsNumber%7];
}

// Set the number of contacts
void PhoneBook::setContactsNumber(int value) {
    contactsNumber = value;
}

// Get the number of contacts
int PhoneBook::getContactsNumber() {
    return contactsNumber;
}

// int PhoneBook::setContactsNumber(){
//     return contactsNumber;
// }

void PhoneBook::printContact()
{
    int i;

    i = 0;
    while(i < contactsNumber){
        std::cout << "First Name " << inst[i].getFirstName() << std::endl;
        std::cout << "Last Name " << inst[i].getLastName() << std::endl;
        std::cout << "NickName " << inst[i].getNickName() << std::endl;
        std::cout << "Phone Number " << inst[i].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret " << inst[i].getDarkestSecret() << std::endl;
        i++;
    }
}

std::string PhoneBook::validInput(std::string value)
{
  const std::string whiteSpace = " \n\r\t\f\v";
  std::string leftTrim;
  int end;

  if(value.empty())
 		return "";
	size_t start = value.find_first_not_of(whiteSpace);
  if(start == std::string::npos)
		return "";

  leftTrim = value.substr(start);

  std::string rightTrim = leftTrim.substr(0, leftTrim.find_last_not_of(whiteSpace)+1);
  if(rightTrim.length() == 0)
	return NULL;
  return rightTrim ;
}