#include "world.h"
#include "geom.h"

#include <fstream>
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
	Sphere s(Point(cx, cy, cz), r);
	objects.push_back(s);
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