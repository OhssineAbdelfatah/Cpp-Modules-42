#include "Zombie.hpp"
#include <iostream>


int main(){
    int numZombies = 5;
    // std::string baseName = "Zombie";

    // Create a horde of zombies
    Zombie* horde = ZombieHorde(numZombies, "zombie");

    // Make each zombie announce itself
    for (int i = 0; i < numZombies; ++i) {
        horde[i].announce();
    }

    // Clean up the allocated memory
    delete[] horde;

    return 0;
}
