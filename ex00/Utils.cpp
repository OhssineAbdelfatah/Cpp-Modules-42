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
    if( base.size() == 3 && base[0] == '\'' && base[2] == '\'' && isalpha(base[1]) )
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
