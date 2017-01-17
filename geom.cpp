#include "geom.h"
#include "ray.h"
#include <algorithm>
#include <cmath>
#include <limits>

// Assume that transformations are given in the order: T, R, S to
// have the geometry be first scaled, rotated, then translated.

void Geom::init(Shading shade, Matrix trans) {
	shading = shade;
	transformation = trans;
}
Geom::Geom() {
	init(Shading(), identity());
}
Geom::~Geom() {
}

Vector Geom::normal(Point p) {
	return Vector();
}
double Geom::hit(Ray r) {
	std::cout << "This Geom has no type." << std::endl;
	return 0;
}
void Geom::print(std::ostream& os) const {
	os << "This Geom has no type.";
}
std::ostream& operator<<(std::ostream& os, const Geom& g) {
	g.print(os);
	return os;
}


void Sphere::init(Shading shade, Matrix trans, Point c, double r) {
	shading = shade;
	transformation = trans;
	centre = c;
	radius = r;
}
Sphere::Sphere() {
	Matrix i = identity();
	init(Shading(), i, Point(0, 5, 0), 1);
}
Sphere::Sphere(Point c, double r) {
	Matrix i = identity();
	init(Shading(), i, c, r);
}
Sphere::Sphere(Shading shade, Matrix trans, Point c, double r) {
	init(shade, trans, c, r);
}
Vector Sphere::normal(Point intersection) {
	Vector v = (this->centre.vectorTo(intersection)).normalize();
	v = Vector(this->transformation.getInverse() * Vector4(v, 0));
	return v;
}
// Solve |S-C + tD|^2 = r^2 for t
//		S - point, origin of ray
//		C - point, centre of sphere
//		D - vector, ray direction
//		r - double, sphere radius
//		t - double, ray length
double Sphere::hit(Ray r) {
	// D = ray direction after sphere transformation
	// D = Transformation inverse * ray direction
	Vector D(this->transformation.getInverse() * Vector4(r.direction, 0));
	// S = ray origin after sphere transformation
	Point S(this->transformation.getInverse() * Vector4(r.direction, 1));
	// CtoS = S - C
	Vector CtoS = this->centre.vectorTo(S);
	std::cout << "r.d: " << r.direction << std::endl;
	std::cout << "D: " << D << std::endl;
	std::cout << "S: " << S << std::endl;
	std::cout << "C: " << this->centre << std::endl;
	double discriminant = pow(D.dot(CtoS), 2) - (D.dot(D) * (CtoS.dot(CtoS) - pow(this->radius, 2)));

	// std::cout << r << std::endl;
	// std::cout << *this << std::endl;
	// std::cout << discriminant << std::endl;

	if (discriminant >= 0) {
		// Solve the quadratic equation for t1 and t2.
		double t1 = (-1 * D.dot(CtoS) + sqrt(discriminant)) / (2 * D.dot(D));
		double t2 = (-1 * D.dot(CtoS) - sqrt(discriminant)) / (2 * D.dot(D));
		double tMax = fmax(t1, t2);
		double tMin = fmin(t1, t2);
		if (tMax >= 0.0) {
			if (tMin <= 0.0) {
				return tMax;
			}
			return tMin;
		}
	}
	// discriminant < 0, no solution, does not intersect
	return std::numeric_limits<double>::max();
}
void Sphere::print(std::ostream& os) const {
	os << "Centre: " << this->centre << std::endl;
	os << "Radius: " << this->radius << std::endl;
	os << "Shading: " << this->shading;
}
std::ostream& operator<<(std::ostream& os, const Sphere& s) {
	s.print(os);
	return os;
}
