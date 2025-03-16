#include <iostream>
#include <string>

int main()
{
    std::string myString("HI THIS IS BRAIN");
    std::string* stringPTR = &myString;
    std::string& stringREF = myString;

    std::cout << "The memory address of  myString : " << &myString << std::endl;
    std::cout << "The memory address of stringPTR : " << &stringPTR << std::endl;
    std::cout << "The memory address of stringREF : " << &stringREF << std::endl;

    std::cout << "----------------------------------" << std::endl ;
    
    std::cout << "The value of  myString : " << myString << std::endl;
    std::cout << "The value of stringPTR : " << *stringPTR << std::endl;
    std::cout << "The value of stringREF : " << stringREF << std::endl;
    return 0;
}
