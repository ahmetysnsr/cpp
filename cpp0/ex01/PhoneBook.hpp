#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int count;
    int next;
public:
    PhoneBook();
    bool add();
    void search() const;
};

#endif
