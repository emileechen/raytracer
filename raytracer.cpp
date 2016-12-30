#include "point.h"
#include "vector.h"
#include <iostream>

using namespace std;


int main() {
	cout << "Hello World!" << endl;

	cout << endl;

	// Test default constructor
	Point pt;
	cout << pt << endl;
	cout << "Should be Point(0.0, 0.0, 0.0)." << endl;

	cout << endl;

	Point* pt1 = new Point();
	cout << *pt1 << endl;
	cout << "Should be Point(0.0, 0.0, 0.0)." << endl;

	cout << endl;

	Point pt2(1.1, 2.3, 1.3);
	cout << pt2 << endl;
	cout << "Should be Point(1.1, 2.3, 1.3)." << endl;

	cout << endl;

	cout << "Testing + operator" << endl;
	Point pt3 = pt2 + pt2;
	cout << pt3 << endl;
	cout << "(1.1, 2.3, 1.3) + (1.1, 2.3, 1.3) = (2.2, 4.6, 2.6)" << endl;

	cout << endl;

	cout << "Testing - operator" << endl;
	cout << pt3 - pt2 << endl;
	cout << "(2.2, 4.6, 2.6) - (1.1, 2.3, 1.3) = (1.1, 2.3, 1.3)" << endl;

	cout << endl;

	cout << "Testing * operator" << endl;
	cout << pt2 * 3.0 << endl;
	cout << 3.0 * pt2 << endl;
	cout << 3 * pt2 << endl;
	cout << "2 * (1.1, 2.3, 1.3) = (2.2, 4.6, 2.6)" << endl;

	cout << endl;

	Vector v;
	cout << v << endl;
	cout << "Should be Vector(0.0, 0.0, 0.0)." << endl;

	cout << endl;

	Vector v2(1.2, 1.0, 2.0);
	Vector v3(2.0, 2.3, 0.5);
	cout << v2 << endl;
	cout << v3 << endl;
	cout << v2.dot(v3) << endl;
	cout << "(1.2, 1.0, 2.0) . (2.0, 2.3, 0.5) = 2.4 + 2.3 + 1.0 = 5.7" << endl;



	return 0;
}