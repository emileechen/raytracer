#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <vector>

#include "geom.h"
#include "light.h"

class World {
	void init();
public:
	std::vector<Geom> objects;
	std::vector<Light> lights;
	World();
	~World();
	void addSphere(double, double, double, double);
	void parseFile(const char*);
	friend std::ostream& operator<<(std::ostream&, const World&);
};

#endif