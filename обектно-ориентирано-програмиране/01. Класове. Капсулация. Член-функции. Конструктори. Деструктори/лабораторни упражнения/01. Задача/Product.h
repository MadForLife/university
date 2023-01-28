#ifndef Product_h
#define Product_h

class Product
{
	public:
		Product();
		Product(char* name, char* producer, double price, int width, int height, int depth);
		~Product();

		int setName(char* name);
		int setProducer(char* producer);
		int setPrice(double price);
		int setWidth(int width);
		int setHeight(int height);
		int setDepth(int depth);

		char* getName() const { return name; };
		char* getProducer() const { return producer; };
		double getPrice() const { return price; };
		int getWidth() const { return width; };
		int getHeight() const { return height; };
		int setDepth() const { return depth; };

		int print() const;

	private:
		char* name;
		char* producer;
		double price;
		int width, height, depth;
};

#endif // !Product_hpp