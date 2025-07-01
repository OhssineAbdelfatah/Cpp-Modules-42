#include"ScalarConverter.hpp"

/*
    Cases :
        char : 'c'
        -inf +inf nan nanf -inff +inff
        float f and dot
        double dot
        
*/
static bool isInt(std::string &base){
    if(base.size() == 0)
        return false;
    for (int i = 0 ; i < (int)base.size() ; i++){
        if(!isdigit(base[0]))// 'a' => 0 , '5' => 1
            return false;
    }
    return true;
}

DataType getType(std::string base)
{
    // char check
    if( base.size() == 3 && base[0] == '\'' && base[2] == '\'' )
        return CHAR;
    
    // int check
    if (isInt(base))
        return INT;

    // double or float
    if ( base.find('.') != std::string::npos && base[base.size() -1 ] != '.' && base[0] != '.')
    {
        int end = (int)base.size();
        if ( base[base.size() -1 ] == 'f' ){
            end = base.size() -1;
            for(int i = 0 ; i < end ; i++)
            {   
                if(!isdigit(base[i]) && base[i] != '.')
                    return ERROR;
            }
            return FLOAT;
        }
        return DOUBLE;
    }
    if(base == "nan" || base =="-inf" || base =="+inf")
        return DOUBLE;
    if(base == "nanf" || base =="-inff" || base =="+inff")
            return FLOAT;
    return ERROR;
}

void printChar(std::string& base)
{
    int i = atoi(base.c_str());

    if( i >= 32 && i <= 126 )
        std::cout << "alo alo char: " << base[1] << std::endl;
    else
        std::cout << "char: " << "Non displayable" << std::endl;

}

void printInt(std::string& base)
{
    int i = atoi(base.c_str());

    std::cout << "int: " << i << std::endl;
}

void ConvertFromChar(std::string& base)
{   
    printChar(base);
    printInt(base);
    printDouble();
}
