#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main()
{
    PhoneBook book;
    std::string command;
    while (true)
    {
        std::cout << "ADD, SEARCH or EXIT: ";
        if (!std::getline(std::cin, command))
            break;

        if (command == "EXIT")
            break;
        else if (command == "ADD")
        {
            if (!book.add())
                break;
        }
        else if (command == "SEARCH")
        {
            book.search();
        }
    }
    return 0;
}
