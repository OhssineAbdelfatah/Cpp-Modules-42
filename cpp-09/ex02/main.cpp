#include"PmergeMe.hpp"

int main(int ac , char *av[])
{
    if(ac  >=  2 ){
        try{
            // if(av[1] == NULL || strlen(av[1]) == 0)
            //     throw std::exception();
            PmergeMe(av+1, ac);
        }catch (std::exception& e){
            std::cout << "" << e.what() << std::endl;
        }
    }else
        std::cerr << "No Input ..." << std::endl;
}