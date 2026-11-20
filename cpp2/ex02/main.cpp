#include "Fixed.hpp"
#include <iostream>

int main()
{
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    Fixed x(2);
    Fixed y(3);
    std::cout << "sum: " << x + y << '\n';
    std::cout << "difference: " << x - y << '\n';
    std::cout << "product: " << x * y << '\n';
    std::cout << "quotient: " << y / x << '\n';
    std::cout << "comparisons (< > <= >= == !=): "
              << (x < y) << ' ' << (x > y) << ' ' << (x <= y) << ' '
              << (x >= y) << ' ' << (x == y) << ' ' << (x != y) << '\n';
    std::cout << "post-decrement: " << x-- << '\n';
    std::cout << "pre-decrement: " << --x << '\n';
    std::cout << "min: " << Fixed::min(x, y) << '\n';
    std::cout << "max: " << Fixed::max(x, y) << '\n';
    std::cout << "const min: " << Fixed::min(a, b) << '\n';
    return 0;
}
