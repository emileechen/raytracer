#include "light.h"
#include <algorithm>
#include <limits>
#include <math.h>


void Light::init(Colour c) {
	colour = c;
}
Light::Light() {
	// Default colour is white.
	init(Colour(1, 1, 1));
}
Light::~Light() {
}

Colour Light::resultingColour(World world, std::shared_ptr<Geom> obj, Point intersection, Ray r) {
	return Colour();
}
void Light::print(std::ostream& os) const {
	os << "This Light has no type.";
}
std::ostream& operator<<(std::ostream& os, const Light& l) {
	l.print(os);
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
Colour PointLight::resultingColour(World world, std::shared_ptr<Geom> obj, Point intersection, Ray r) {
	std::cout << "PointLight::resultingColour: " << std::endl;
	Vector objNormal = obj->normal(intersection);
	std::cout << "objNormal: " << objNormal << std::endl;
	std::cout << "intersection: " << intersection << std::endl;
	Vector viewNormal = r.direction * -1;
	std::cout << "viewNormal: " << viewNormal << std::endl;
	Ray shadowRay = this->rayFrom(intersection);
	int closestObj = -1;

	std::cout << "shadowRay: " << shadowRay << std::endl;

	// double shadowRayT = world.hit(shadowRay, closestObj, 0.1 /* SHADOW_THRESHOLD*/);
	Vector lightNormal = shadowRay.direction.normalize();
	Vector reflectedNormal = (2 * objNormal * lightNormal.dot(objNormal)) - lightNormal;

	std::cout << "lightNormal: " << lightNormal << std::endl;
	std::cout << "reflectedNormal: " << reflectedNormal << std::endl;
	// ambient = ka * I
	Colour ambient = obj->shading.ambient * this->colour;
	// diffuse = kd * I * max((l . n), 0)
	std::cout << "Diffuse colour: " << obj->shading.diffuse << std::endl;
	std::cout << "lightNormal . objNormal: " << lightNormal.dot(objNormal) << std::endl;
	Colour diffuse = (obj->shading.diffuse * this->colour) * std::max(lightNormal.dot(objNormal), 0.0);
	// specular = ks * I * max((r . v), 0) ^ p
	Colour specular = (obj->shading.specular * this->colour) * pow(std::max(reflectedNormal.dot(viewNormal), 0.0), obj->shading.intensity);
	std::cout << "Ambient component: " << ambient << std::endl;
	std::cout << "Diffuse component: " << diffuse << std::endl;
	std::cout << "Specular component: " << specular << std::endl;
	return diffuse;
	// return ambient + diffuse + specular;
}
void PointLight::print(std::ostream& os) const {
	os << "PointLight:	" << this->point << std::endl;
	os << "		" << this->colour;
}
std::ostream& operator<<(std::ostream& os, const PointLight& l) {
	l.print(os);
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
Colour DirectionalLight::resultingColour(World world, std::shared_ptr<Geom> obj, Point intersection, Ray r) {
	Vector objNormal = obj->normal(intersection);
	Vector viewNormal = r.direction * -1;
	Ray shadowRay = this->rayFrom(intersection);
	double lightDistance = this->distance(intersection);
	int closestObj = -1;
	double shadowRayT = world.hit(shadowRay, closestObj, 0.1 /* SHADOW_THRESHOLD*/);
	// If the ray does not hit anything before the light source...
	// if (shadowRayT >= std::numeric_limits<float>::max()) {
		Vector lightNormal = shadowRay.direction.normalize();
		Vector reflectedNormal = 2 * objNormal * lightNormal.dot(objNormal);
		reflectedNormal = (lightNormal * -1) +reflectedNormal;
	// }
	// ambient = ka * I
	Colour ambient = obj->shading.ambient * this->colour;
	// diffuse = kd * I * max((l . n), 0)
	Colour diffuse = obj->shading.diffuse * this->colour * std::max(lightNormal.dot(objNormal), 0.0);
	// specular = ks * I * max((r . v), 0) ^ p
	Colour specular = obj->shading.specular * this->colour * pow(std::max(reflectedNormal.dot(viewNormal), 0.0), obj->shading.intensity);
	return ambient + diffuse + specular;
}
void DirectionalLight::print(std::ostream& os) const {
	os << "DirectionalLight:	" << this->direction << std::endl;
	os << "			" << this->colour;
}
std::ostream& operator<<(std::ostream& os, const DirectionalLight& l) {
	l.print(os);
	return os;
}


void AmbientLight::init(Colour c) {
	colour = c;
}
AmbientLight::AmbientLight() {
	init(Colour(0.1, 0.1, 0.1));
}
AmbientLight::AmbientLight(Colour c) {
	init(c);
}

Colour AmbientLight::resultingColour(World world, std::shared_ptr<Geom> obj, Point intersection, Ray r) {
	return obj->shading.ambient * this->colour;
}
void AmbientLight::print(std::ostream& os) const {
	os << "AmbientLight:	" << this->colour;
}
std::ostream& operator<<(std::ostream& os, const AmbientLight& l) {
	l.print(os);
	return os;
}
