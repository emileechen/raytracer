#ifndef LIGHT_H
#define LIGHT_H
#include <iostream>

#include "colour.h"
#include "point.h"
#include "ray.h"
#include "vector.h"


class Light {
	void init(Colour);
public:
	Colour colour;
	Light();
	~Light();
	friend std::ostream& operator<<(std::ostream&, const Light&);
};

class PointLight : public Light {
	void init(Point, Colour);
public:
	Point point;
	PointLight(Point, Colour);
	Vector vectorTo(Point);
	Ray rayTo(Point);
	double distance(Point);
	friend std::ostream& operator<<(std::ostream&, const Point&);
};

#endif