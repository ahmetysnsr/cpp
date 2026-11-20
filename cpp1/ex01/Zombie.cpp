#include "Zombie.hpp"
#include <iostream>

Zombie::~Zombie()
{
    std::cout << name << ": destroyed" << std::endl;
}

void Zombie::setName(const std::string &value)
{
    name = value;
}

void Zombie::announce()
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
