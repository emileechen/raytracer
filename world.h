#ifndef WORLD_H
#define WORLD_H
#include <iostream>
#include <vector>

#include "geom.h"

class Light;
class World;


class World {
	void init();
public:
	std::vector<std::shared_ptr<Geom> > objects;
	// std::vector<Geom*> objects;
	std::vector<Light> lights;
	World();
	~World();
	void addSphere(double, double, double, double);
	void parseFile(const char*);
	double hit(Ray, int&, double t_min = 0, double t_max = std::numeric_limits<double>::max());
	friend std::ostream& operator<<(std::ostream&, const World&);
};

#endif