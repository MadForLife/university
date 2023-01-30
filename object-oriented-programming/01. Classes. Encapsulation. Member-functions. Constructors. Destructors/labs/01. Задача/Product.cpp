#include "Product.h"
#include <cstring>
#include <iostream>

Product::Product()
{
	name = new char[2];
	producer = new char[2];

	strcpy_s(name, 2, " ");
	strcpy_s(producer, 2, " ");

	price = 0;
	width = 0;
	height = 0;
	depth = 0;

}

Product::Product(const char* name, const char* producer, double price, int width, int height, int depth)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->producer = new char[strlen(producer) + 1];
	strcpy_s(this->producer, strlen(producer) + 1, producer);

	setPrice(price);
	setWidth(width);
	setHeight(height);
	setDepth(depth);
}

Product::~Product()
{
	if (this->name != nullptr) delete[] this->name;
	if (this->producer != nullptr) delete[] this->producer;
}

int Product::setName(const char* name)
{
	if (this->name != nullptr) delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
	return 0;
}

int Product::setProducer(const char* producer)
{
	if (this->producer != nullptr) delete[] this->producer;

	this->producer = new char[strlen(producer) + 1];
	strcpy_s(this->producer, strlen(producer) + 1, producer);
	return 0;
}

int Product::setPrice(double price)
{
	if (price >= 0) this->price = price;
	else this->price = -price;

	return 0;
}
int Product::setWidth(int width)
{
	if (width > 0) this->width = width;
	else this->width = -width;

	return 0;
}
int Product::setHeight(int height)
{
	if (height > 0) this->height = height;
	else this->height = -height;

	return 0;
}
int Product::setDepth(int depth)
{
	if (depth > 0) this->depth = depth;
	else this->depth = -depth;

	return 0;
}

int Product::print() const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Producer: " << producer << std::endl;
	std::cout << "Price: " << price << std::endl;
	std::cout << "Width: " << width << std::endl;
	std::cout << "Height: " << height << std::endl;
	std::cout << "Depth: " << depth << std::endl;
	std::cout << std::endl;

	return 0;
}