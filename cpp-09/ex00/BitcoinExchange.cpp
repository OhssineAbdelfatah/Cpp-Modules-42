#include"BitcoinExchange.hpp"
BitcoinExchange::BitcoinExchange(){}


BitcoinExchange::BitcoinExchange(std::string& path) {
    try{
        std::ifstream dataSet(path);
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

void BitcoinExchange::openFile(std::string path){

}

std::pair<std::string , float> BitcoinExchange::parseLine(std::string& line){
    std::string token[2];
    token[0] = line.substr(0 , line.find('|'));
    token[1] = line.substr(line.find('|'), line.size())
    if(token[0].size() == 0 || token[1].size() == 0 || token[0].size() == std::npos || token[1].size() == std::npos )
        throw BitcoinExchange::BadInputException();
    std::string date[3];
    date[0] = token[0].substr(0, token[0].find('-')); 
    date[1] = token[0].substr(token[0].find('-'), token[0].find('-')); 
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

