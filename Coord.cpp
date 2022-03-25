#include "Coord.h"
#include <iostream>


using namespace std;

/* CONSTUCTORS */

Coord::Coord() : x(0), y(0), z(0) {} 

Coord::Coord(double a, double b, double c)
{
	this->x = a;
	this->y = b;
	this->z = c;
}

Coord::~Coord() {}

Coord::Coord(const Coord& Coord_copy) : x(Coord_copy.x), y(Coord_copy.y), z(Coord_copy.z) {}
Coord::Coord(Coord* Coord_copy) : x(Coord_copy->x), y(Coord_copy->y), z(Coord_copy->z) {}


/* SETTERS AND GETTERS*/
double Coord::set_x(double value)
{
	return (this->x = value);
}
double Coord::set_y(double value)
{
	return (this->y = value);
}
double Coord::set_z(double value)
{
	return (this->z = value);
}

double Coord::get_x()
{
	return this->x;
}
double Coord::get_y()
{
	return this->y;
}
double Coord::get_z()
{
	return this->z;
}

/* METODS */
void Coord::print()
{
	cout << "{" << get_x() << "; " << get_y() << "; " << get_z() << "}" << endl;
}


double operator++ (Coord& c)
{
	return c.get_x() + c.get_y() + c.get_z();
}
double Coord::operator--()
{
	cout << "strange operator: "<<endl;
	char choice = ' ';
	while(choice != 'x' && choice != 'y' && choice != 'z')
	{ 
	cout << "input coordinate: (x or y or z): ";
	cin >> choice;
	}
	double number, result;
	cout << "input number: ";
	cin >> number;
	
	switch (choice)
	{
	case 'x':
		result = number - this->get_x();
		break;
	case 'y':
		result = number - this->get_y();
		break;
	case 'z':
		result = number - this->get_z();
		break;
	}

	return result;
}
Coord Coord::operator++(int)
{
	Coord oldValue(this);
	this->set_x(this->get_x() + 1.5);
	this->set_y(this->get_y() + 1.5);
	this->set_z(this->get_z() + 1.5);
	
	return oldValue;
}

Coord Coord::operator--(int)
{
	Coord oldValue(this);
	this->set_x(this->get_x() - 5.9);
	this->set_y(this->get_y() - 5.9);
	this->set_z(this->get_z() - 5.9);
	
	return oldValue;
}
