#include "Zombie.hpp"

int main()
{
    Zombie *heap = newZombie("Heap");
    heap->announce();
    randomChump("Stack");
    delete heap;
}
