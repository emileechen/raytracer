#include "point.h"
#include "vector.h"


void Point::init(double p0, double p1, double p2) {
	x = p0;
	y = p1;
	z = p2;
}
Point::Point() {
	init(0.0, 0.0, 0.0);
}
Point::Point(double x, double y, double z) {
	init(x, y, z);
}
Point::Point(Vector v) {
	init(v.x, v.y, v.z);
}
Point::Point(Vector4 v) {
	init(v.x, v.y, v.z);
}
Point::~Point() {
}

Point Point::operator+(Point& b) {
	Point p(this->x + b.x, this->y + b.y, this->z + b.z);
	return p;
}
Point Point::operator+(Vector& b) {
	Point p(this->x + b.x, this->y + b.y, this->z + b.z);
	return p;
}
Point Point::operator-(Point& b) {
	Point p(this->x - b.x, this->y - b.y, this->z - b.z);
	return p;
}
Point Point::operator*(double c) {
	Point p(this->x * c, this->y * c, this->z * c);
	return p;
}
Point operator*(double c, Point pt) {
	// Point p(pt.x * c, pt.y * c, pt.z * c);
	return pt * c;
}
Vector Point::vectorTo(Point p) {
	Vector v(p.x - this->x, p.y - this->y, p.z - this->z);
	return v;
}
std::ostream& operator<<(std::ostream &os, const Point& p) { 
	os << "Point(" << p.x << ", " << p.y << ", " << p.z << ")";
	return os;
}