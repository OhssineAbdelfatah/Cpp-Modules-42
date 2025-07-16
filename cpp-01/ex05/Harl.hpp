#ifndef HARL_HPP
#define HARL_HPP

class Harl 
{
    private :
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public :
        Harl();
        ~Harl();
        void complain( std::string level );
};   

typedef void (Harl::*t_func) (void) ;
/*
    creats a typdef t_func = pointer to member fucntion
    of Harl class 
    use :
        t_func ptrName = functionSignature ; 
*/
#endif