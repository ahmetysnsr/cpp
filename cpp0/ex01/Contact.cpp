#include "Contact.hpp"
#include <iostream>
#include <iomanip>

static bool readField(const std::string &prompt, std::string &value)
{
    while (true)
    {
        std::cout << prompt << ": ";
        if (!std::getline(std::cin, value))
            return false;
        if (value.find_first_not_of(" \t\r\v\f") != std::string::npos)
            return true;
        std::cout << "A field cannot be empty." << std::endl;
    }
}

bool Contact::read()
{
    if (!readField("First name", firstName))
        return false;
    if (!readField("Last name", lastName))
        return false;
    if (!readField("Nickname", nickname))
        return false;
    if (!readField("Phone number", phoneNumber))
        return false;
    return readField("Darkest secret", darkestSecret);
}

static std::string column(const std::string &value)
{
    if (value.size() > 10)
        return value.substr(0, 9) + ".";
    return value;
}

void Contact::displayRow(int index) const
{
    std::cout << std::right << std::setw(10) << index << '|'
        << std::setw(10) << column(firstName) << '|'
        << std::setw(10) << column(lastName) << '|'
        << std::setw(10) << column(nickname) << std::endl;
}

void Contact::display() const
{
    std::cout << "First name: " << firstName << '\n'
        << "Last name: " << lastName << '\n'
        << "Nickname: " << nickname << '\n'
        << "Phone number: " << phoneNumber << '\n'
        << "Darkest secret: " << darkestSecret << std::endl;
}
