#ifndef COLOUR_H
#define COLOUR_H
#include <iostream>

using namespace std;


class Colour {
	void init(double, double, double);
public:
	double r, g, b;
	Colour();									// default constructor
	Colour(double, double, double);				// constructor
	Colour(const Colour&);
	~Colour();									// deconstructor
	Colour operator+(Colour&);
	Colour operator-(Colour&);
	Colour operator*(double);
	friend Colour operator*(double, Colour);
	friend ostream& operator<<(ostream&, const Colour&);
};


#endif