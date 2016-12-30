#ifndef POINT_H
#define POINT_H

class Point {
private:
	float x;
	float y;
	float z;
	void init(float, float, float);
public:
	Point(float x=0.0, float y=0.0, float z=0.0);	// default constructor
	Point(float x, float y, float z);				// constructor
//	Point(const Point&);							// copy constructor
	~Point();										// deconstructor
};

#endif