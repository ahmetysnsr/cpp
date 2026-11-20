#include "PhoneBook.hpp"
#include <iostream>
#include <sstream>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), next(0)
{
}

bool PhoneBook::add()
{
    Contact candidate;
    if (!candidate.read())
        return false;
    contacts[next] = candidate;
    ++next;
    if (next == 8)
        next = 0;
    if (count < 8)
        ++count;
    return true;
}

void PhoneBook::search() const
{
    if (count == 0)
    {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << std::right << std::setw(10) << "Index" << '|'
        << std::setw(10) << "First name" << '|'
        << std::setw(10) << "Last name" << '|'
        << std::setw(10) << "Nickname" << std::endl;
    for (int i = 0; i < count; ++i)
        contacts[i].displayRow(i);
    std::string line;
    std::cout << "Index: ";
    if (!std::getline(std::cin, line))
        return;
    std::istringstream input(line);
    int index;
    char extra;
    if (!(input >> index) || input >> extra || index < 0 || index >= count)
    {
        std::cout << "Invalid index." << std::endl;
        return;
    }
    contacts[index].display();
}
