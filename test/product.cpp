#include "product.hpp"
#include <string>
#include <ostream>
#include <iostream>
void Product::showProductInfo()
{
	std::cout << "NAME:" <<this->name << std::endl;
	std::cout << "PRICE:" << this->price << std::endl;
	//std::cout << "TYPE" << this->type << std::endl;

	return;
}

Product::Product(std::string name, double price)
{
	this->name = name;
	this->price = price;
}
