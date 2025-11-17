#include"RPN.hpp"

// bool isAllWhitespace(const std::string& str) {
//     return std::find_if(str.begin(), str.end(), [](char c) { return !std::isspace(static_cast<unsigned char>(c)); }) 
//            == str.end();
// }


int main(int ac , char *av[])
{
    if(ac == 2 ){
        // program logic
        main1(); 
        // RPN rpn(av[1]); 
    (void)av;
    }else 
        std::cerr << "Error : no input provided !"<< std::endl;
}