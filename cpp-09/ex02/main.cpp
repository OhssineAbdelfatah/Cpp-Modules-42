#include"PmergeMe.hpp"

int main(int ac , char *av[])
{
    if(ac  >=  2 ){
        try{
            // if(av[1] == NULL || strlen(av[1]) == 0)
            //     throw std::exception();
            clock_t timeVec;
	        clock_t timeDeq;

            // merge insertion sort or Ford Jhonson 
            
            // Container 1
            timeVec = clock();
            PmergeMe vect;
            vect.MergeInsertVect(av + 1, ac);
            timeVec = - clock() - timeVec ;

            //Container 2
            timeDeq = clock();
            // PmergeMe(av+1, ac);
            timeDeq = - clock() - timeDeq ;

            // print Container 1
            // before sort
            // after sort

            // print Container 2
            // before sort 
            // after sort

        }catch (std::exception& e){
            std::cout << "" << e.what() << std::endl;
        }
    }else
        std::cerr << "No Input ..." << std::endl;
}