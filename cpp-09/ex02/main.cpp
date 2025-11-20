#include"PmergeMe.hpp"


int wordCounter(std::string token){
    int word = 0 ;
    for( pos != token.size()){
        if( (pos = token.find_first_not_of(' ' , pos)) != std::string::npos ){
            word++;
            if( (pos = token.find(' ', pos))  != std::string::npos )
                pos++;
        }else
            break;
    }
}

// std::vector<std::string> spliter(std::string token){
//     if(token.find_first_not_of(' ') == std::string::npos)
//         throw std::exception();
//     int pos = token.find_first_not_of(' ');
//     std::vector<std::string> strs ;
//     size_t garde = pos;
//     // while(garde != token.size())
//     // {
//     //     std::string tmp = token.substr( pos, token.find(' ', pos ) - pos );
//     //     pos += tmp.size();
//     //     if(token.find_first_not_of(' ') == std::string::npos ){
//     //         token.substr( pos, token.size() - pos);
//     //         strs.push_back(tmp);
//     //         break;
//     //     }
//     //     pos  = token.find_first_not_of(' ');
//     //     garde = pos - garde;
//     // }
//     return strs;
// }

int main(int ac , char *av[])
{
    if(ac  >=  2 ){
        // PmergeMe( &(av[1]), ac);
        std::vector<std::string> strs = spliter(av[1]);
        for(std::vector<std::string>::iterator it = strs.begin() ; it != strs.end() ; it++){
            std::cout << *it << std::endl;
        } 
    }else
        std::cerr << "No Input ..." << std::endl;
}