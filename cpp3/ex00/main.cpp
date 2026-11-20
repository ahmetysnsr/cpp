#include "ClapTrap.hpp"

int main()
{
    ClapTrap bot("Bolt");
    bot.attack("target");
    bot.takeDamage(3);
    bot.beRepaired(2);
    bot.takeDamage(10);
    bot.attack("target");

    ClapTrap tired("Spark");
    for (int i = 0; i < 10; ++i)
        tired.attack("target");
    tired.beRepaired(1);
    return 0;
}
