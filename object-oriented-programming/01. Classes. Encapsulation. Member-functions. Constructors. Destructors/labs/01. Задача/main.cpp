#include <iostream>
#include "Product.h"

int main()
{
	Product p1;
	Product p2("vafla", "naia", 1.20, 2, 5, 15);

	p1.print();
	p2.print();
	return 0;
}