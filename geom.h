#ifndef GEOM_H
#define GEOM_H
#include <iostream>

#include "matrix.h"
#include "point.h"
#include "shading.h"
#include "vector.h"

class Ray;


class Geom {
	void init(Shading, Matrix);
public:
	Shading shading;
	Matrix transformation;
	Geom();										// default constructor
	~Geom();									// deconstructor
	virtual Vector normal(Point);
	virtual double hit(Ray);
	virtual void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream&, const Geom&);
};

class Sphere : public Geom {
	void init(Shading, Matrix, Point, double);
public:
	Point centre;
	double radius;
	Sphere();
	Sphere(Point, double);
	Sphere(Shading, Matrix, Point, double);
	virtual Vector normal(Point);
	virtual double hit(Ray);
	virtual void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream&, const Sphere&);
};

#endif