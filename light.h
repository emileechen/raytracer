#ifndef LIGHT_H
#define LIGHT_H
#include <iostream>

#include "colour.h"
#include "geom.h"
#include "point.h"
#include "ray.h"
#include "vector.h"
#include "world.h"


class Light {
	void init(Colour);
public:
	Colour colour;
	Light();
	~Light();
	virtual Colour resultingColour(World, std::shared_ptr<Geom>, Point, Ray);
	virtual void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream&, const Light&);
};

class PointLight : public Light {
	void init(Point, Colour);
public:
	Point point;
	PointLight();
	PointLight(Point, Colour);
	Vector vectorFrom(Point);
	Ray rayFrom(Point);
	double distance(Point);
	virtual Colour resultingColour(World, std::shared_ptr<Geom>, Point, Ray);
	virtual void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream&, const PointLight&);
};

class DirectionalLight : public Light {
	void init(Vector, Colour);
public:
	Vector direction;
	DirectionalLight();
	DirectionalLight(Vector, Colour);
	Vector vectorFrom(Point);
	Ray rayFrom(Point);
	double distance(Point);
	virtual Colour resultingColour(World, std::shared_ptr<Geom>, Point, Ray);
	virtual void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream&, const DirectionalLight&);
};

class AmbientLight : public Light {
	void init(Colour);
public:
	virtual Colour resultingColour(World, std::shared_ptr<Geom>, Point, Ray);
	virtual void print(std::ostream&) const;
	friend std::ostream& operator<<(std::ostream&, const AmbientLight&);
};

#endif