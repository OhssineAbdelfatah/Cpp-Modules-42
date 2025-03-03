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



/*
void Contacts::addContact()
{
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
    // if(std::cin.eof() || !validInput(fn) || !validInput(ln) ||  !validInput(nn) ||  !validInput(pn) ||  !validInput(ds))
    if(std::cin.eof() || validInput(fn).empty() || validInput(ln).empty() || validInput(nn).empty() || validInput(pn).empty() || validInput(ds).empty())
    {
        std::cout << "empty filed : contact ignored" << std::endl ;
        return;
    }
    setFirstName(fn);
    setLastName(ln);
    setNickName(nn);
    setPhoneNumber(pn);
    setDarkestSecret(ds);
}
*/

/*
std::string Contacts::validInput(std::string value)
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
*/


// Contacts(){
    // std::cout << this->firstName << std::endl ;
// }
