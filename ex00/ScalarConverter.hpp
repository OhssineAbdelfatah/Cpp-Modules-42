#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <iostream>
#include <string>

enum Type {
    NOT_TYPE,
    CHAR,
    DOUBLE,
    FLOAT,
    INT,
};

class ScalarConverter {
    private:
        ScalarConverter();
        ScalarConverter& operator=(const ScalarConverter& other);
        ScalarConverter(const ScalarConverter& other);
        ~ScalarConverter();
    public:
        static void convert(std::string );
        Type detectType(std::string )
    // Add member variables here
};

literalTypes checkTypes(std::string );
bool isFloat(std::string );
bool isInt(std::string );
bool isDouble(std::string );
bool isChar(std::string );

#endif // SCALARCONVERTER_HPP
