#include "camera.h"


void Camera::init(Point eye, Point ll, Point lr, Point ul, Point ur) {
	this->eye = eye;
	this->ll = ll;
	this->lr = lr;
	this->ul = ul;
	this->ur = ur;
}
Camera::Camera() {
	init(Point(0,0,0), Point(-1, -1, 1), Point(1, -1, 1), Point(-1, 1, 1), Point(1, 1, 1));
}
Camera::Camera(Point eye, Point ll, Point lr, Point ul, Point ur) {
	init(eye, ll, lr, ul, ur);
}
Camera::~Camera() {
}

std::vector<Ray> Camera::makeRays(unsigned int width, unsigned int height) {
	std::vector<Ray> rays;		// Top left to bottom right
	double u_step = 1.0 / (width - 1);
	double v_step = 1.0 / (height - 1);
	for (int y = 0; y < height; y++) {
		for (int x = 0; x < width; x++) {
			Point p1a = (this->ur * (x * u_step));
			Point p1b = (this->ul * (1.0 - (x * u_step)));
			Point p1 = p1a + p1b;
			Point p2a = this->lr * (x * u_step);
			Point p2b = this->ll * (1.0 - (x * u_step));
			Point p2 = p2a + p2b;
			Point pa = p1 * (1.0 - (y * v_step));
			Point pb = p2 * (y * v_step);
			Point p = pa + pb;
			rays.push_back(Ray(this->eye, this->eye.vectorTo(p)));
		}
	}
	return rays;
}
std::ostream& operator<<(std::ostream &os, const Camera& c) { 
	os << "Eye: " << c.eye << std::endl;
	os << "UL: " << c.ul << "	" << "UR: " << c.ur << std::endl;
	os << "LL: " << c.ll << "	" << "LR: " << c.lr;
	return os;
}