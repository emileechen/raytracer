#include "world.h"
#include "camera.h"
#include "light.h"
#include "ray.h"
#include <fstream>
#include <limits>
#include <sstream>
#include <string>


void World::init(Colour bg) {
	background = bg;
}
World::World() {
	// Black
	init(Colour());
}
World::World(Colour bg) {
	// Black
	init(bg);
}
World::~World() {
}

// Should Camera be a member of World????
void World::addCamera(	double ex, double ey, double ez,
						double llx, double lly, double llz,
						double lrx, double lry, double lrz,
						double ulx, double uly, double ulz,
						double urx, double ury, double urz	) {
	// Camera: cam ex ey ez llx lly llz lrx lry lrz ulx uly ulz urx ury urz
	Camera c = Camera(Point(ex, ey, ez), Point(llx, lly, llz), Point(lrx, lry, lrz), Point(ulx, uly, ulz), Point(urx, ury, urz));
}
void World::addSphere(double cx, double cy, double cz, double r) {
	// Sphere: sph cx cy cz r
	// Sphere s(Point(cx, cy, cz), r);
	Sphere s = Sphere(Point(cx, cy, cz), r);
	objects.push_back(std::make_shared<Sphere>(s));
}
void World::addPointLight(double px, double py, double pz, double r, double g, double b) {
	// PointLight: ltp px py pz r g b
	PointLight p = PointLight(Point(px, py, pz), Colour(r, g, b));
	lights.push_back(std::make_shared<PointLight>(p));
}
void World::addAmbientLight(double r, double g, double b) {
	AmbientLight a = AmbientLight(Colour(r, g, b));
	lights.push_back(std::make_shared<AmbientLight>(a));
}
void World::parseFile(const char* filename) {
	std::ifstream input(filename);
	for(std::string line; std::getline(input, line); ) {
		std::cout << line << std::endl;
	}
	// std::string line;
	// while (std::getline(input, line)) {
	// 	std::istringstream iss(line);
	// 	int a, b;
	// 	if (!(iss >> a >> b)) { break; } // error
	// }
}
// Returns t intersection value for the first Geom in objects hit by given ray
double World::hit(Ray r, int& closest_obj, double tMin, double tMax) {
	double avoid_ref = std::numeric_limits<double>::max();
	double closest_t = tMax;
	std::cout << r << std::endl;
	// Iterate through every Geom in objects...
	for (std::vector<std::shared_ptr<Geom> >::size_type i = 0; i < objects.size(); i++) {
		double t = objects[i]->hit(r);
		// If some geom is the closest, in front of camera, and hit...
		if (t < closest_t and t >= tMin and t <= tMax) {
			closest_t = t;
			closest_obj = i;
		}
	}
	return closest_t;
}
std::ostream& operator<<(std::ostream &os, const World& w) {
	for (std::vector<Geom>::size_type i = 0; i != w.objects.size(); i++) {
		os << *w.objects[i] << std::endl;
	}
	return os;
}
