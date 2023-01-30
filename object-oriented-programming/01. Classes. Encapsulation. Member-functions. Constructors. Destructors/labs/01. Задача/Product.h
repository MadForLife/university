#ifndef Product_h
#define Product_h

class Product
{
	public:
		Product();
		Product(const char* name, const char* producer, double, int, int, int);
		~Product();

		int setName(const char* name);
		int setProducer(const char* producer);
		int setPrice(double price);
		int setWidth(int width);
		int setHeight(int height);
		int setDepth(int depth);

		char* getName() const { return name; };
		char* getProducer() const { return producer; };
		double getPrice() const { return price; };
		int getWidth() const { return width; };
		int getHeight() const { return height; };
		int getDepth() const { return depth; };

		int print() const;
		
	private:
		char* name;
		char* producer;

		double price;
		int width, height, depth;
};
#endif // !Product_h