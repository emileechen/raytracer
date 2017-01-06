#include "colour.h"
#include <cmath>


void Colour::init(double c0, double c1, double c2, double c3) {
	r = c0;
	g = c1;
	b = c2;
	a = c3;
}
Colour::Colour() {
	init(0.0, 0.0, 0.0, 1.0);
}
Colour::Colour(double r, double g, double b, double a) {
	init(r, g, b, a);
}
Colour::Colour(double r, double g, double b) {
	init(r, g, b, 1.0);
}
Colour::Colour(const Colour& c) {
	init(c.r, c.g, c.b, c.a);
}
Colour::~Colour() {
}

Colour Colour::operator+(Colour& a) {
	Colour c(this->r + a.r, this->g + a.g, this->b + a.b, this->a + a.a);
	return c;
}
Colour Colour::operator-(Colour& a) {
	Colour c(this->r - a.r, this->g - a.g, this->b - a.b, this->a - a.a);
	return c;
}
Colour Colour::operator*(double c) {
	Colour col(this->r * c, this->g * c, this->b * c, this->a * c);
	return col;
}
Colour operator*(double c, Colour a) {
	// Colour col(a.r * c, a.g * c, a.b * c);
	return a * c;
}
std::ostream& operator<<(std::ostream &os, const Colour& c) { 
    os << "RGBA(" << c.r << ", " << c.g << ", " << c.b << ", " << c.a << ")";
    return os;
}