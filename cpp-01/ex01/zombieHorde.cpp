#include "Zombie.hpp"
#include <sstream>

Zombie* zombieHorde( int N, std::string name )
{
    Zombie* horde = new Zombie[N]();
    for (int i = 0; i < N; ++i){
        std::ostringstream __name;
        __name << name << " " << i;
        horde[i].setName(__name.str());
    }
    return horde;
}
