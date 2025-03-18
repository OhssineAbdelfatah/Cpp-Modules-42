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
    return Contacts::darkestSecret;
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
