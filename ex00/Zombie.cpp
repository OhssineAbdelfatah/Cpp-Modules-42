#include "Zombie.hpp"

Zombie::Zombie(std::string): _name(name)
{
  std::cout "Zombie" << name << "born":
}

Zombie::~Zombie()
{
  std::cout "Zombie" << name << "is dead":
}

void Zombie::setName(std:string name){
  this->_name = name;
}

std:string Zombie::getName() const{
  return _name;
}


void Zombie::announce( void ){
  std::cout << _name << " : BraiiiiiiinnnzzzZ..." << std::endl;
}
