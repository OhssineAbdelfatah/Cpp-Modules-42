#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include<string>
#include<iostream>
#include<sstream>
#include<cstdlib>
#include<exception>
#include <iomanip>

typedef enum DataType {
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    ERROR 
} DataType;

class ScalarConverter {
    private :
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter& other);
        ScalarConverter& operator=(const ScalarConverter& other);
    public:
        static void convert(std::string );
};

DataType getType(std::string);
void ConvertFromChar(std::string& base);

#endif // SCALARCONVERTER_HPP
