#ifndef POINT_H
#define POINT_H
#include <iostream>

using namespace std;


class Point {
	void init(double, double, double);
public:
	double x, y, z;
	Point();										// default constructor
	Point(double, double, double);					// constructor
	~Point();										// deconstructor
	Point operator+(Point&);
	Point operator-(Point&);
	Point operator*(double);
	friend Point operator*(double, Point);
	friend ostream& operator<<(ostream&, const Point&);
};


#endif