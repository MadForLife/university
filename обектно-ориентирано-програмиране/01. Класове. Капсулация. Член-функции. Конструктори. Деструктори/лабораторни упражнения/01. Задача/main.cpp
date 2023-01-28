#include <iostream>
#include "Product.h"

int main()
{
	Product p;

	char name[]  = "vafla";
	char producer[] = "preshush foods";
	Product pr(name, producer, 5, 5, 15, 3);

	p.print();
	std::cout << std::endl;
	pr.print();

	return 0;
}