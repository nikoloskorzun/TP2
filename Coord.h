#pragma once


class Coord
{
private:
	double x;
	double y;
	double z;
public:
	//constructors:
	Coord(); //without parameter
	explicit Coord(double x, double y, double z); //explicit constuct.

	~Coord(); //destructor

	Coord(const Coord& Coord_copy); //copys constructor
	Coord(Coord* Coord_copy); 


	//getters and setters
	
	double set_x(double value);
	double get_x();

	double set_y(double value);
	double get_y();

	double set_z(double value);
	double get_z();

	void print();



	
	friend double operator++(Coord& c); //префиксная форма
	double operator--(); //префиксная форма

	
	Coord operator++(int); //постфиксная форма
	Coord operator--(int); //постфиксная форма
};
