#ifnodef ZOMBIE_HPP
#define ZOMBIE_HPP


class Zombie {
  private :
    std:string _name;

  public :
    Zombie(std::string name);
    ~Zombie();
    void setName(std:string name);
    std:string getName() const;
    void announce( void );
    Zombie* newZombie( std::string name );
    void randomChump( std::string name );
};
#endif
