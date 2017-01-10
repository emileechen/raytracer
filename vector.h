#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>

class Vector4;

class Vector {
	void init(double, double, double);
public:
	double x, y, z;
	Vector();									// default constructor
	Vector(double, double, double);
	Vector(Vector4);
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


class Vector4 {
	void init(double, double, double, double);
public:
	double x, y, z, w;
	Vector4();
	Vector4(double, double, double, double);
	Vector4(Vector, double);
	Vector4(const Vector4&);
	~Vector4();
	friend std::ostream& operator<<(std::ostream&, const Vector4&);
};

#endif