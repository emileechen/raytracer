#ifndef GEOM_H
#define GEOM_H
#include <iostream>

#include "matrix.h"
#include "point.h"
#include "shading.h"


class Geom {
	void init(Shading, Matrix);
public:
	Shading shading;
	Matrix transformation;
	Geom();										// default constructor
	~Geom();									// deconstructor
	friend std::ostream& operator<<(std::ostream&, const Geom&);
};

class Sphere : public Geom {
	void init(Shading, Matrix, Point, double);
public:
	Point centre;
	double radius;
	Sphere(Point, double);
	Sphere(Shading, Matrix, Point, double);
	Vector normal(Point);
	friend std::ostream& operator<<(std::ostream&, const Sphere&);
};

#endif