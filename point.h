#ifndef POINT_H
#define POINT_H

#include <string>

using namespace std;


class Point {
	double x, y, z;
	void init(double, double, double);
public:
	Point();	// default constructor
	Point(double, double, double);				// constructor
	~Point();										// deconstructor
	const double getX(void);
	const double getY(void);
	const double getZ(void);
	Point operator+(Point&);
};



#endif