#include "colour.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;


void Colour::init(double c0, double c1, double c2) {
	r = c0;
	g = c1;
	b = c2;
}
Colour::Colour() {
	init(0.0, 0.0, 0.0);
}
Colour::Colour(double r, double g, double b) {
	init(r, g, b);
}
Colour::Colour(const Colour& c) {
	init(c.r, c.g, c.b);
}
Colour::~Colour() {
}

Colour Colour::operator+(Colour& a) {
	Colour c(this->r + a.r, this->g + a.g, this->b + a.b);
	return c;
}
Colour Colour::operator-(Colour& a) {
	Colour c(this->r - a.r, this->g - a.g, this->b - a.b);
	return c;
}
Colour Colour::operator*(double c) {
	Colour col(this->r * c, this->g * c, this->b * c);
	return col;
}
Colour operator*(double c, Colour a) {
	Colour col(a.r * c, a.g * c, a.b * c);
	return col;
}
ostream& operator<<(ostream &os, const Colour& c) { 
    os << "RGB(" << c.r << ", " << c.g << ", " << c.b << ")";
    return os;
}