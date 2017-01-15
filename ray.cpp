#include "ray.h"
#include "light.h"
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
		Point intersectionTrans = Point(obj->transformation.getInverse() * Vector4(intersection));
		Vector normal = obj->normal(intersectionTrans);
		Colour finalColour = Colour(world.background);
		for (std::vector<std::shared_ptr<Light> >::size_type i = 0; i < world.lights.size(); i++) {
			finalColour = world.lights[i]->resultingColour(world, obj, intersection, *this);
		}
	}
}
std::ostream& operator<<(std::ostream &os, const Ray& r) { 
	os << "Origin: " << r.origin << std::endl;
	os << "Direction: " << r.direction;
	return os;
}