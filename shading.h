#ifndef SHADING_H
#define SHADING_H
#include <iostream>


class Shading {
	void init(double, double, double, double, double, double, double, double, double, double);
public:
	// Ambient RGB
	double kar, kag, kab;
	// Diffuse RGB
	double kdr, kdg, kdb;
	// Specular RGB + exponent "roughness"
	double ksr, ksg, ksb, ksp;

	Shading();									// default constructor
	Shading(double, double, double, double, double, double, double, double, double, double);
	~Shading();									// deconstructor
	friend std::ostream& operator<<(std::ostream&, const Shading&);
};

#endif