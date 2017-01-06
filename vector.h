#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>


class Vector {
	void init(double, double, double);
public:
	double x, y, z;
	Vector();									// default constructor
	Vector(double, double, double);				// constructor
	Vector(const Vector&);
	~Vector();									// deconstructor
	Vector operator+(Vector&);
	Vector operator-(Vector&);
	Vector operator*(double);
	friend Vector operator*(double, Vector);
	Vector operator/(double);
	double dot(Vector);
	double magnitude();
	Vector normalize();
	friend std::ostream& operator<<(std::ostream&, const Vector&);
};


#endif