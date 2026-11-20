#include "ClapTrap.hpp"
#include <iostream>
#include <limits>

ClapTrap::ClapTrap() : name("Unnamed"), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap default constructor: " << name << std::endl;
}

ClapTrap::ClapTrap(const std::string &name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "ClapTrap constructor: " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints),
    energyPoints(other.energyPoints), attackDamage(other.attackDamage)
{
    std::cout << "ClapTrap copy constructor: " << name << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energyPoints = other.energyPoints;
        attackDamage = other.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap destructor: " << name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot attack." << std::endl;
        return;
    }
    --energyPoints;
    std::cout << "ClapTrap " << name << " attacks " << target << ", causing "
        << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount >= hitPoints)
        hitPoints = 0;
    else
        hitPoints = hitPoints - amount;
    std::cout << "ClapTrap " << name << " takes " << amount
        << " damage; HP: " << hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints == 0 || energyPoints == 0)
    {
        std::cout << "ClapTrap " << name << " cannot repair." << std::endl;
        return;
    }
    --energyPoints;
    unsigned int room = std::numeric_limits<unsigned int>::max() - hitPoints;
    if (amount > room)
        hitPoints = std::numeric_limits<unsigned int>::max();
    else
        hitPoints = hitPoints + amount;
    std::cout << "ClapTrap " << name << " repairs; HP: " << hitPoints << std::endl;
}
