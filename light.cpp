#include "light.h"
#include <limits>


void Light::init(Colour c) {
	colour = c;
}
Light::Light() {
	// Default colour is white.
	init(Colour(1, 1, 1));
}
Light::~Light() {
}

std::ostream& operator<<(std::ostream &os, const Light& l) { 
	os << "Light:	" << l.colour;
	return os;
}


void PointLight::init(Point p, Colour c) {
	point = p;
	colour = c;
}
PointLight::PointLight() {
	init(Point(), Colour(1, 1, 1));
}
PointLight::PointLight(Point p, Colour c) {
	init(p, c);
}

Vector PointLight::vectorFrom(Point p) {
	return p.vectorTo(this->point);
}
Ray PointLight::rayFrom(Point p) {
	return Ray(p, this->vectorFrom(p));
}
double PointLight::distance(Point p) {
	return this->vectorFrom(p).magnitude();
}

std::ostream& operator<<(std::ostream &os, const PointLight& l) { 
	os << "PointLight:	" << l.point << std::endl;
	os << "		" << l.colour;
	return os;
}


void DirectionalLight::init(Vector v, Colour c) {
	direction = v;
	colour = c;
}
DirectionalLight::DirectionalLight() {
	init(Vector(), Colour(1, 1, 1));
}
DirectionalLight::DirectionalLight(Vector v, Colour c) {
	init(v, c);
}

Vector DirectionalLight::vectorFrom(Point p) {
	return this->direction;
}
Ray DirectionalLight::rayFrom(Point p) {
	return Ray(p, this->direction);
}
double DirectionalLight::distance(Point p) {
	return std::numeric_limits<float>::max();
}
std::ostream& operator<<(std::ostream &os, const DirectionalLight& l) { 
	os << "DirectionalLight:	" << l.direction << std::endl;
	os << "			" << l.colour;
	return os;
}
