#include "ray.h"
#include <vector>


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

Point Ray::intersection(double t, Geom obj) {
	Vector d = t * Vector(obj.transformation.getInverse() * Vector4(this->direction));
	Point o = Point(obj.transformation.getInverse() * Vector4(this->origin));
	return o + d;
}
void Ray::trace(World world) {
	int objInd = -1;					// Index to objects vector<Geom> of closest Geom
	double t = world.hit(*this, objInd);	// Ray t value for intersection point of ray and closest Geom
	// If the ray hits something...
	std::cout << "objInd: " << objInd << std::endl;
	std::cout << "t: " << t << std::endl;
	if (objInd != -1) {
		std::shared_ptr<Geom> obj = world.objects[objInd];
		Point intersection = this->intersection(t, *obj);

		std::cout << intersection << std::endl;

		intersection = Point(obj->transformation.getInverse() * Vector4(intersection));

		std::cout << intersection << std::endl;

		Vector normal = obj->normal(intersection);

		std::cout << normal << std::endl;

	}

	// if closest_ref is not None:
	// 		obj = OBJECTS_DICT[closest_ref]
	// 		intersect_point = self.intersection(closest_t, obj.transformation)
	// 		if obj.transformation is not None and len(obj.transformation) > 0:
	// 			intersect_point = point_from_list(matrix_deify(matrix_multiply(obj.inverse, matrix_ify(intersect_point.to_list(), 1))))
	// 		obj_normal = obj.normal(intersect_point)
	// 		if obj.transformation is not None and len(obj.transformation) > 0:
	// 			intersect_point = point_from_list(matrix_deify(matrix_multiply(obj.transformation, matrix_ify(intersect_point.to_list(), 1))))
	// 		ambient_color = Color()
	// 		diffuse_color = Color()
	// 		specular_color = Color()
	// 		reflected_color = Color()
	// 		view_normal = self.direction.scalarMultiply(-1.0)
}
std::ostream& operator<<(std::ostream &os, const Ray& r) { 
	os << "Origin: " << r.origin << std::endl;
	os << "Direction: " << r.direction;
	return os;
}