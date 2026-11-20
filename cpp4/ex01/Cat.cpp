#include "Cat.hpp"
#include <iostream>

Cat::Cat() : Animal(), brain(new Brain())
{
    type = "Cat";
    std::cout << "Cat constructor" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other), brain(new Brain(*other.brain))
{
    std::cout << "Cat copy constructor" << std::endl;
}

Cat &Cat::operator=(const Cat &other)
{
    if (this != &other)
    {
        Animal::operator=(other);
        // Copy the ideas into our own Brain, not the pointer.
        *brain = *other.brain;
    }
    return *this;
}

Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor" << std::endl;
}

void Cat::makeSound() const
{
    std::cout << "Meow!" << std::endl;
}

Brain &Cat::getBrain()
{
    return *brain;
}
