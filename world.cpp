#include "world.h"
#include "light.h"
#include "ray.h"
#include <fstream>
#include <limits>
#include <sstream>
#include <string>


void World::init() {
}
World::World() {
	init();
}
World::~World() {
}

void World::addSphere(double cx, double cy, double cz, double r) {
	// Sphere: sph cx cy cz r
	// Sphere s(Point(cx, cy, cz), r);
	objects.push_back(new Sphere(Point(cx, cy, cz), r));
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
double World::hit(Ray r, int& closest_obj, double t_min, double t_max) {
	double avoid_ref = std::numeric_limits<double>::max();
	double closest_t = t_max;
	// Iterate through every Geom in objects...
	for (std::vector<Geom>::size_type i = 0; i != objects.size(); i++) {
		double t = objects[i]->hit(r);
		// If some geom is the closest, in front of camera, and hit...
		if (t < closest_t and t >= t_min and t <= t_max) {
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
