#include"Contacts.hpp"

std::string Contacts::getFirstName() const{
    return firstName;
}
void Contacts::setFirstName(std::string firstName){
    this->firstName = firstName;
}

std::string Contacts::getLastName() const{
    return lastName;
}
void Contacts::setLastName(std::string lastName) {
    this->lastName = lastName;
}

std::string Contacts::getNickName() const{
    return nickName;
}

void Contacts::setNickName(std::string nickName){
    this->nickName = nickName;
}

std::string Contacts::getDarkestSecret() const{
    return darkestSecret;
}

void Contacts::setDarkestSecret(std::string darkestSecret) {
    this->darkestSecret = darkestSecret;
}

std::string Contacts::getPhoneNumber() const{
    return phoneNumber;
}

void Contacts::setPhoneNumber(std::string phoneNumber){
    this->phoneNumber = phoneNumber;
}


void Contacts::printContact()
{
    std::cout << "First Name " << getFirstName() << std::endl;
    std::cout << "Last Name " << getLastName() << std::endl;
    std::cout << "NickName " << getNickName() << std::endl;
    std::cout << "Phone Number " << getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret " << getDarkestSecret() << std::endl;
}

void Contacts::addContact()
{
    std::string fn;

    std::cout << "First Name " << std::endl;
    std::getline(std::cin ,fn );
    if(std::cin.eof() || fn.empty())
    {
        std::cout << "empty filed : enter your first name" << std::endl ;
        continue;
    }
    setFirstName(fn);

    std::string ln;
    std::cout << "Last Name " << std::endl;
    //std::cin >> buff ;
    std::getline(std::cin, ln );
    setLastName(ln);

    std::string nn;
    std::cout << "Nick Name " << std::endl;
    //std::cin >> buff ;
    std::getline(std::cin, nn );
    setNickName(nn);

    std::string pn;
    std::cout << "phone Number " << std::endl;
    //std::cin >> buff ;
    std::getline(std::cin ,pn );
    setPhoneNumber(pn);

    std::string ds;
    std::cout << "darkest Secret " << std::endl;
    std::getline(std::cin, ds );
    //std::cin >> buff ;
    setDarkestSecret(ds);
}



// Contacts(){
    // std::cout << this->firstName << std::endl ;
// }
