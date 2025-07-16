#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include<cstdint>
#include<string>
#include<iostream>


typedef struct Data {
    std::string name;
    int age;

    Data(const std::string& n, int v) : name(n), age(v) {}
} Data;

class Serializer {
    public:
        static uintptr_t serialize(Data* );
        static Data* deserialize(uintptr_t );

    private:
        Serializer& operator=(const Serializer& );
        Serializer(const Serializer& );
        ~Serializer();
        Serializer();
};

#endif // SERIALIZER_HPP

/*
    In C99, it is defined as 
    "an unsigned integer type 
    with the property that any valid pointer to void can be converted to this type,
    then converted back to pointer to void, 
    and the result will compare equal to the original pointer".


    uintptr_t is an unsigned integer type that is capable of storing a data pointer (whether it can hold a function pointer is unspecified).

    That typically means that it's the same size as a pointer.

    It is optionally defined in C++11 and later standards.

    A common reason to want an integer type that can hold an architecture's pointer type 
    is to perform integer-specific operations on a pointer, 
    or to obscure the type of a pointer by providing it as an integer "handle".
*/