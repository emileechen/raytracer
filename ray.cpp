#include "ray.h"
#include "light.h"
#include <algorithm>
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
	Vector d = Vector(obj.transformation.getInverse() * Vector4(this->direction));
	Point o = Point(obj.transformation.getInverse() * Vector4(this->origin));

	std::cerr << "o: " << o << std::endl;
	std::cerr << "d: " << d << std::endl;

	return (t * d) + o;
}
Colour Ray::trace(World world) {
	int objInd = -1;					// Index to objects vector<Geom> of closest Geom
	double t = world.hit(*this, objInd);	// Ray t value for intersection point of ray and closest Geom
	// If the ray hits something...
	Colour finalColour = Colour(world.background);
	if (objInd != -1) {
		std::shared_ptr<Geom> obj = world.objects[objInd];
		Point intersection = this->intersection(t, *obj);
		Point intersectionTrans = Point(obj->transformation.getInverse() * Vector4(intersection));
		Vector normal = obj->normal(intersectionTrans);
		for (std::vector<std::shared_ptr<Light> >::size_type i = 0; i < world.lights.size(); i++) {
			finalColour = world.lights[i]->resultingColour(world, obj, intersection, *this) + finalColour;
			std::cout << "finalColour: " << finalColour << std::endl;
		}
	}
	return finalColour.min(1.0);
}
std::ostream& operator<<(std::ostream &os, const Ray& r) { 
	os << "Origin: " << r.origin << std::endl;
	os << "Direction: " << r.direction;
	return os;
}