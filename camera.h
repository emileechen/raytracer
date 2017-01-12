#ifndef CAMERA_H
#define CAMERA_H
#include <iostream>
#include <vector>

#include "point.h"
#include "ray.h"


class Camera {
	void init(Point, Point, Point, Point, Point);
public:
	Point eye, ll, lr, ul, ur;
	Camera();
	Camera(Point, Point, Point, Point, Point);
	~Camera();
	std::vector<Ray> makeRays(unsigned int, unsigned int);
	friend std::ostream& operator<<(std::ostream&, const Camera&);
};

#endif