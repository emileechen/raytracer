#include "point.h"
#include <iostream>
#include <string>

using namespace std;


void Point::init(double p0, double p1, double p2) {
	x = p0;
	y = p1;
	z = p2;
	cout << "init successful!" << endl;
}
Point::Point() {
	cout << "In default constructor..." << endl;
	init(0.0, 0.0, 0.0);
}
Point::Point(double x, double y, double z) {
	cout << "In (double x, double y, double z) constructor..." << endl;
	init(x, y, z);
}
Point::~Point() {
	cout << "Destroying Point..." << endl;
}

const double Point::getX(void) {
	return x;
}
const double Point::getY(void) {
	return y;
}
const double Point::getZ(void) {
	return z;
}
Point Point::operator+(Point& b) {
	Point p(this->x + b.x, this->y + b.y, this->z + b.z);
	return p;
}