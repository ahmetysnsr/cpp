#include <string>
#include <ostream>
#include <iostream>
enum Product_Type
{
	Food,
	Furniture,
	Cosmetic,
	Hygiene
};

class Product
{
	public:
		Product(std::string name, double price);
		void showProductInfo();
	private:
		std::string name;
		double price;
};
