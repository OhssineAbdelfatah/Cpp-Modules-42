#include "Zombie.hpp"
#include <iostream>


Zombie::Zombie()
{
  std::cout << "Default Constructer" << std::endl;
}

Zombie::Zombie(std::string name): _name(name)
{
  std::cout << "Zombie " << name << " born" << std::endl;
}

Zombie::~Zombie()
{
  std::cout << "Zombie " << _name << " is dead" << std::endl;
}

void Zombie::announce( void ){
  std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
