#ifndef FIXED_HPP
#define FIXED_HPP

#include <ostream>

class Fixed
{
private:
    int raw;
    static const int fractionalBits = 8;
public:
    Fixed();
    Fixed(const Fixed &other);
    Fixed &operator=(const Fixed &other);
    ~Fixed();
    int getRawBits() const;
    void setRawBits(int const value);
    Fixed(int const value);
    Fixed(float const value);
    float toFloat() const;
    int toInt() const;
};
std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif
