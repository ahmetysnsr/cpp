#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>

Fixed::Fixed() : raw(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : raw(other.raw)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    raw = other.raw;
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return raw;
}

void Fixed::setRawBits(int const value)
{
    raw = value;
}

// Use double for the range check, avoiding signed-shift and signed-overflow UB.
static int checkedRaw(double value)
{
    if (value != value || value < std::numeric_limits<int>::min()
        || value > std::numeric_limits<int>::max())
        throw std::overflow_error("Fixed: value out of range");
    return static_cast<int>(value);
}

Fixed::Fixed(int const value) : raw(checkedRaw(static_cast<double>(value) * (1 << fractionalBits)))
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const value) : raw(checkedRaw(::roundf(value * (1 << fractionalBits))))
{
    std::cout << "Float constructor called" << std::endl;
}

float Fixed::toFloat() const
{
    return static_cast<float>(raw) / (1 << fractionalBits);
}

int Fixed::toInt() const
{
    return raw / (1 << fractionalBits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &value)
{
    return out << value.toFloat();
}
