#ifndef SHADING_H
#define SHADING_H
#include <iostream>

#include "colour.h"


class Shading {
	// void init(double, double, double, double, double, double, double, double, double, double);
	void init(Colour, Colour, Colour, double);
public:
	// // Ambient RGB
	// double kar, kag, kab;
	// // Diffuse RGB
	// double kdr, kdg, kdb;
	// // Specular RGB + exponent "roughness"
	// double ksr, ksg, ksb, ksp;
	Colour ambient;
	Colour diffuse;
	Colour specular;
	double specP;

	Shading();									// default constructor
	Shading(double, double, double, double, double, double, double, double, double, double);
	Shading(Colour, Colour, Colour, double);
	~Shading();									// deconstructor
	friend std::ostream& operator<<(std::ostream&, const Shading&);
};

#endif