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
            vect.MergeInsertDque(av+1, ac);
            timeDeq = - clock() - timeDeq ;

            std::cout << "before ... " ;
            vect.printVector(vect.getVectSeq());
            std::cout << "after ... " ;
            vect.printVector(vect.getVect());

            std::cout << "Time to process a range of " << ac - 1 << " elements with std::vector : " << (double)timeVec  << " ms" << std::endl;
		    std::cout << "Time to process a range of " << ac - 1 << " elements with std::deque : " << (double)timeDeq  << " ms" << std::endl;

        }catch (std::exception& e){
            std::cout << "" << e.what() << std::endl;
        }
    }else
        std::cerr << "No Input ..." << std::endl;
}