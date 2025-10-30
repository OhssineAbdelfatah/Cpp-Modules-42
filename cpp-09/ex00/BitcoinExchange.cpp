#include"BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange(){}


BitcoinExchange::BitcoinExchange(char *path) {
    try{
        std::ifstream dataSet(path, std::ios::in);
    }catch (std::exception& e){
        std::cout << e.what() << std::endl;
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& obj){
    *this = obj;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& obj){
    if(this != &obj){
        pricesDataBase = obj.pricesDataBase;
    }
    return *this;
}
BitcoinExchange::~BitcoinExchange(){}

// void BitcoinExchange::openFile(std::string path){

// }

std::pair<std::string , float> BitcoinExchange::parseLine(std::string& line){
    std::string token[2];
    token[0] = line.substr(0 , line.find('|'));
    token[1] = line.substr(line.find('|'), line.size());
    if(token[0].size() == 0 || token[1].size() == 0 || token[0].size() == std::string::npos || token[1].size() == std::string::npos )
        throw BitcoinExchange::BadInputException();
    std::string date[3];
    // date[0] = token[0].substr(0, token[0].find('-')); 
    // date[1] = token[0].substr(token[0].find('-'), token[0].find('-')); 
    // std::string::iterator it = token[0].begin();
    int pos = 0;
    for (size_t i = 0; i < 3; i++)
    {
        date[i] = token[0].substr( pos, token[0].find('-', pos )); 
        pos = token[0].find('-', pos );
        std::cout << ">>>>>>>>>> " << date[i] << std::endl;
    }
    
}


void BitcoinExchange::readFile(){
    
    std::string line;
    
    while( std::getline(file, line)){
        parseLine(line);
    }
}

const char* BitcoinExchange::BadInputException::what() const throw(){
    return ("bad input !!");
}

