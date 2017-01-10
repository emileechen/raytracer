#ifndef SHADING_H
#define SHADING_H
#include <iostream>


class Shading {
	void init();
public:
	// Ambient RGB
	double kar, kag, kab;
	// Diffuse RGB
	double kdr, kdg, kdb;
	// Specular RGB + exponent "roughness"
	double ksr, ksg, ksb, ksp;

	Shading();									// default constructor
	Shading(kar, kag, kab, kdr, kdg, kdb, ksr, ksg, ksb, ksp);
	~Shading();									// deconstructor
	friend std::ostream& operator<<(std::ostream&, const Geom&);
};

#endif