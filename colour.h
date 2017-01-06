#ifndef COLOUR_H
#define COLOUR_H
#include <iostream>


class Colour {
	void init(double, double, double, double);
public:
	double r, g, b, a;
	Colour();									// default constructor
	Colour(double, double, double, double);		// constructor
	Colour(double, double, double);				// constructor
	Colour(const Colour&);
	~Colour();									// deconstructor
	Colour operator+(Colour&);
	Colour operator-(Colour&);
	Colour operator*(double);
	friend Colour operator*(double, Colour);
	friend std::ostream& operator<<(std::ostream&, const Colour&);
};


#endif