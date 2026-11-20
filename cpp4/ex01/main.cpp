#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
    Animal *animals[4];
    for (int i = 0; i < 4; ++i)
    {
        if (i < 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    for (int i = 0; i < 4; ++i)
    {
        animals[i]->makeSound();
        delete animals[i];
    }

    Dog dog;
    dog.getBrain().setIdea(0, "Fetch");
    Dog dogCopy(dog);
    dog.getBrain().setIdea(0, "Sleep");

    Cat cat;
    cat.getBrain().setIdea(0, "Fish");
    Cat catCopy;
    catCopy = cat;
    cat.getBrain().setIdea(0, "Milk");

    std::cout << "Dog copy: " << dogCopy.getBrain().getIdea(0) << '\n';
    std::cout << "Cat copy: " << catCopy.getBrain().getIdea(0) << '\n';
    if (dogCopy.getBrain().getIdea(0) != "Fetch")
        return 1;
    if (catCopy.getBrain().getIdea(0) != "Fish")
        return 1;
    return 0;
}
