#include "geom.h"


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

	// def normal(self, intersection):
	// 	c = self.center
	// 	v = c.vectorTo(intersection).normalize()
	// 	if self.transformation is not None and len(self.transformation) > 0:
	// 		v = vector_from_list(matrix_stripped_deify(matrix_multiply(self.inverse_transpose_stripped, matrix_ify(v.to_list()[0:3], 0))))
	// 		v = v.normalize()
	// 	return v
}
std::ostream& operator<<(std::ostream &os, const Sphere& s) { 
	os << "Centre: " << s.centre << std::endl;
	os << "Radius: " << s.radius;
	return os;
}