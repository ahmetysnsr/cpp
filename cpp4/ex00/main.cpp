#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    Animal animal;
    const Animal *dog = new Dog();
    const Animal *cat = new Cat();

    animal.makeSound();
    std::cout << dog->getType() << ": ";
    dog->makeSound();
    std::cout << cat->getType() << ": ";
    cat->makeSound();
    delete dog;
    delete cat;

    WrongCat wrongCat;
    const WrongAnimal &base = wrongCat;
    base.makeSound();
    wrongCat.makeSound();
    return 0;
}
