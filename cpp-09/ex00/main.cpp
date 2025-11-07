#include<iostream>

#define BLUE "\033[34m"
#define RED "\033[31m"
#define DEF "\033[0m"
#define GREEN "\033[32m" 
#define PINK "\033[35m" 
#include "BitcoinExchange.hpp"

int main(int ac , char *av[]){
  /*   (void)av;
    (void)ac; */
    if(ac != 2 )
        std::cerr << RED << " no file provided !!"<< DEF << std::endl;
    else {
        try{
            BitcoinExchange btc(av[1]);
            btc.readBaseFile();
            btc.readInputFile();
        }catch (std::exception& e){
            std::cout << "Error " << e.what() << std::endl;
        }
    }

/*     
    std::map <std::string , float> mappp;

    std::pair<std::string , float> pp("20200106", 10.5);
    mappp.insert(pp);
    std::pair<std::string , float> pp1("20200110", 15.5);
    mappp.insert(pp1);
    std::string ss("20200106");
    std::map<std::string , float>::iterator it = mappp.find(ss);
    if(it != mappp.end())
        std::cout << it->second << std::endl;
    else 
        std::cout << "error     " << std::endl;  */


/* // map::lower_bound/upper_bound
  std::map<char,int> mymap;
  std::map<char,int>::iterator itlow,itup, it;

  mymap['a']=20;
  mymap['b']=40;
  mymap['d']=60;
  mymap['e']=80;
  mymap['f']=100;

  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
std::cout << " =============> "  << '\n';

  itlow=mymap.lower_bound ('c');  // itlow points to b
//   it = mymap.lower_bound(itlow->first);
//   it up=mymap.upper_bound ('d');   // itup points to e (not d!)

  mymap.erase(--itlow);        // erases [itlow,itup)

  // print content:
  for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0; */
}