#include "Brain.hpp"
#include <iostream>
#include <stdexcept>

Brain::Brain()
{
    std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Brain copy constructor" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    if (this != &other)
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    return *this;
}

Brain::~Brain()
{
    std::cout << "Brain destructor" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
    if (index < 0 || index >= 100)
        throw std::out_of_range("Brain index");
    ideas[index] = idea;
}

const std::string &Brain::getIdea(int index) const
{
    if (index < 0 || index >= 100)
        throw std::out_of_range("Brain index");
    return ideas[index];
}
