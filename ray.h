#ifndef RAY_H
#define RAY_H
#include <iostream>

#include "geom.h"
#include "matrix.h"
#include "point.h"
#include "vector.h"
#include "world.h"


class Ray {
	void init(Point, Vector);
public:
	Point origin;
	Vector direction;
	Ray();									// default constructor
	Ray(Point, Vector);
	~Ray();									// deconstructor
	Point intersection(double, Geom);
	void trace(World);
	friend std::ostream& operator<<(std::ostream&, const Ray&);
};

#endif