#include "vector.h"
#include <cmath>


void Vector::init(double v0, double v1, double v2) {
	x = v0;
	y = v1;
	z = v2;
}
Vector::Vector() {
	init(0.0, 0.0, 0.0);
}
Vector::Vector(double x, double y, double z) {
	init(x, y, z);
}
Vector::Vector(const Vector& v) {
	init(v.x, v.y, v.z);
}
Vector::~Vector() {
}

Vector Vector::operator+(Vector& a) {
	Vector v(this->x + a.x, this->y + a.y, this->z + a.z);
	return v;
}
Vector Vector::operator-(Vector& a) {
	Vector v(this->x - a.x, this->y - a.y, this->z - a.z);
	return v;
}
Vector Vector::operator*(double c) {
	Vector v(this->x * c, this->y * c, this->z * c);
	return v;
}
Vector operator*(double c, Vector vec) {
	// Vector v(vec.x * c, vec.y * c, vec.z * c);
	return vec * c;
}
Vector Vector::operator/(double c) {
	Vector v(this->x / c, this->y / c, this->z / c);
	return v;
}
double Vector::dot(Vector a) {
	return (this->x * a.x) + (this->y * a.y) + (this->z * a.z);
}
double Vector::magnitude() {
	return sqrt(this->dot(*this));
}
Vector Vector::normalize() {
	Vector v(*this);
	return v / this->magnitude();
}
std::ostream& operator<<(std::ostream &os, const Vector& v) { 
	os << "Vector(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}


void Vector4::init(double v0, double v1, double v2, double v3) {
	x = v0;
	y = v1;
	z = v2;
	w = v3;
}
Vector4::Vector4() {
	init(0.0, 0.0, 0.0, 1.0);
}
Vector4::Vector4(double x, double y, double z, double w) {
	init(x, y, z, w);
}
Vector4::Vector4(Vector v, double w) {
	init(v.x, v.y, v.z, w);
}
Vector4::Vector4(const Vector4& v) {
	init(v.x, v.y, v.z, v.w);
}
Vector4::~Vector4() {
}

std::ostream& operator<<(std::ostream &os, const Vector4& v) { 
	os << "Vector4(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
	return os;
}
