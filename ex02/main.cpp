#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>

void identify(Base* p){
    if(dynamic_cast<A*>(p) != NULL)
        std::cout << "Actual type is A" << std::endl;
    else if(dynamic_cast<B*>(p) != NULL)
        std::cout << "Actual type is B" << std::endl;
    else if(dynamic_cast<C*>(p) != NULL)
        std::cout << "Actual type is C" << std::endl;
}

void identify(Base& p){
    try{
        A& inst = dynamic_cast<A&>(p);
        std::cout << "Type A" << std::endl;
        (void)inst;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        B& inst = dynamic_cast<B&>(p);
        std::cout << "Type B" << std::endl;
        (void)inst;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
    try{
        C& inst = dynamic_cast<C&>(p);
        std::cout << "Type C" << std::endl;
        (void)inst;
    }
    catch(std::exception &e){
        std::cout << e.what() << std::endl;
    }
}

Base* generate(void)
{
    int classGen  = (std::time(0));
    std::stringstream timee ;
    timee<< classGen;
    std::string ttime = timee.str();
    classGen = ttime.back() - '0';
    std::cout << classGen << std::endl;
    switch(classGen)
    {
        case 1:
        case 4:
        case 7:
            return (new A());
        case 2: 
        case 5: 
        case 8: 
        case 0: 
            return (new C());
        case 3:
        case 6:
        case 9:
            return (new B());
    }
    return NULL;
}

int main()
{
    std::cout << "hello world" << std::endl; 

    Base* ptr = generate();
    std::cout << ptr << std::endl;
    identify(ptr);
    identify(*ptr);
}