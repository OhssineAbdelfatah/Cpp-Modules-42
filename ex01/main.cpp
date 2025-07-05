#include "Serializer.hpp"

#include <iostream>
#include "Serializer.hpp"

int main()
{
    std::cout << "hello world" << std::endl; 
    Data* ptr = new Data("abde", 15);

    std::cout << ptr << std::endl;
    uintptr_t intptrt = Serializer::serialize(ptr);
    std::cout << intptrt << std::endl;
    Data* ptr2 = Serializer::deserialize(intptrt);
    std::cout << ptr2 << std::endl;
    delete ptr;
}