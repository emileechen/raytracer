#include "geom.h"
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
	Matrix i = identity();
	init(Shading(), i);
}
Geom::~Geom() {
}


void Sphere::init(Shading shade, Matrix trans, Point c, double r) {
	shading = shade;
	transformation = trans;
	centre = c;
	radius = r;
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
	double discriminant = pow(D.dot(CtoS), 2) - (D.dot(D) * (CtoS.dot(CtoS) - pow(this->radius, 2)));
	if (discriminant >= 0) {
		// Solve the quadratic equation for t1 and t2.
		double t1 = (-1 * D.dot(CtoS) + sqrt(discriminant)) / (2 * D.dot(D));
		double t2 = (-1 * D.dot(CtoS) - sqrt(discriminant)) / (2 * D.dot(D));
		double t_max = fmax(t1, t2);
		double t_min = fmin(t1, t2);
		if (t_max >= 0.0) {
			if (t_min <= 0.0) {
				return t_max;
			}
			return t_min;
		}
	}
	// discriminant < 0, no solution, does not intersect
	return std::numeric_limits<float>::max();
}
std::ostream& operator<<(std::ostream &os, const Sphere& s) { 
	os << "Centre: " << s.centre << std::endl;
	os << "Radius: " << s.radius;
	return os;
}