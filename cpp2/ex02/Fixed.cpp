#include "Fixed.hpp"
#include <iostream>
#include <cmath>
#include <limits>
#include <stdexcept>

Fixed::Fixed() : raw(0)
{
}

Fixed::Fixed(const Fixed &other) : raw(other.raw)
{
}

Fixed &Fixed::operator=(const Fixed &other)
{
    raw = other.raw;
    return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
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
}

Fixed::Fixed(float const value) : raw(checkedRaw(::roundf(value * (1 << fractionalBits))))
{
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

bool Fixed::operator>(const Fixed &other) const
{
    return raw > other.raw;
}

bool Fixed::operator<(const Fixed &other) const
{
    return raw < other.raw;
}

bool Fixed::operator>=(const Fixed &other) const
{
    return raw >= other.raw;
}

bool Fixed::operator<=(const Fixed &other) const
{
    return raw <= other.raw;
}

bool Fixed::operator==(const Fixed &other) const
{
    return raw == other.raw;
}

bool Fixed::operator!=(const Fixed &other) const
{
    return raw != other.raw;
}

Fixed Fixed::operator+(const Fixed &other) const
{
    Fixed result;
    result.raw = checkedRaw(static_cast<double>(raw) + other.raw);
    return result;
}

Fixed Fixed::operator-(const Fixed &other) const
{
    Fixed result;
    result.raw = checkedRaw(static_cast<double>(raw) - other.raw);
    return result;
}

Fixed Fixed::operator*(const Fixed &other) const
{
    Fixed result;
    result.raw = checkedRaw((static_cast<double>(raw) * other.raw) / (1 << fractionalBits));
    return result;
}

Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.raw == 0)
        throw std::domain_error("Fixed: division by zero");
    Fixed result;
    result.raw = checkedRaw(static_cast<double>(raw) * (1 << fractionalBits) / other.raw);
    return result;
}

Fixed &Fixed::operator++()
{
    raw = checkedRaw(static_cast<double>(raw) + 1);
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed previous(*this);
    ++(*this);
    return previous;
}

Fixed &Fixed::operator--()
{
    raw = checkedRaw(static_cast<double>(raw) - 1);
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed previous(*this);
    --(*this);
    return previous;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}
