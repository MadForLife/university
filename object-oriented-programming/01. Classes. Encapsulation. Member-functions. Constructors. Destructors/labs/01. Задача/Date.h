#ifndef Date_h
#define	Date_h

class Date
{
	public:
		Date();
		Date(int day, int month, int year);
		~Date();

		int setDay(int day);
		int setMonth(int month);
		int setYear(int year);

		int getDay() const;
		int getMonth() const;
		int getYear() const;

	private:
		int day;
		int month;
		int year;

};
#endif // !Date_h
