#ifndef RAY_H
#define RAY_H
#include <iostream>

#include "matrix.h"
#include "point.h"
#include "vector.h"


class Ray {
	void init(Point, Vector);
public:
	Point origin;
	Vector direction;
	Ray();									// default constructor
	Ray(Point, Vector);
	~Ray();									// deconstructor
	Point intersection(double, Matrix);
	friend std::ostream& operator<<(std::ostream&, const Ray&);
};

#endif