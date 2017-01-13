#include "ray.h"


void Ray::init(Point o, Vector d) {
	origin = o;
	direction = d;
}
Ray::Ray() {
	init(Point(0, 0, 0), Vector(1, 0, 0));
}
Ray::Ray(Point o, Vector d) {
	init(o, d);
}
Ray::~Ray() {
}

Point Ray::intersection(double t, Matrix transformation) {
	Vector d = t * Vector(transformation.getInverse() * Vector4(this->direction));
	Point o = Point(transformation.getInverse() * Vector4(this->origin));
	return o + d;
}
std::ostream& operator<<(std::ostream &os, const Ray& r) { 
	os << "Origin: " << r.origin << std::endl;
	os << "Direction: " << r.direction;
	return os;
}