 #pragma once
/*
valid lien "date | value
valid date Year-Month-Day
valid value : float or uint  0 <= value <= 1000
*/

#include<string>
#include<fstream>
#include<iostream>
#include<map>
#include<algorithm>
#include<utility>

class BitcoinExchange{
    private :
    std::map<std::string , float> pricesDataBase;
    std::ifstream file;
    BitcoinExchange();
    public :
        class BadInputException : public std::exception {
            public :
                const char* what() const throw();
        };

        BitcoinExchange(char * path);
        BitcoinExchange(const BitcoinExchange&);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange&);
        
        // void openFile(std::string);
        void readFile() ;
        std::pair<std::string , float> parseLine(std::string&);
};