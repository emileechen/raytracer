#include "point.h"
#include <iostream>

using namespace std;


int main() {
	cout << "Hello World!" << endl;

	Point pt;		//calls default constructor
	cout << "pt.x = " << pt.getX() << endl;
	cout << pt.getX() << ", " << pt.getY()  << ", " << pt.getZ()<< endl;

	Point* pt1 = new Point();		//calls default constructor
	cout << "pt1.x = " << pt1->getX() << endl;
	cout << pt1->getX() << ", " << pt1->getY()  << ", " << pt1->getZ()<< endl;

	Point pt2(1.1, 2.3, 1.3);
	cout << "pt2.x = " << pt2.getX() << endl;
	cout << pt2 << endl;

	Point* pt3 = new Point(1.1, 2.3, 1.3);
	cout << "pt3.x = " << pt3->getX() << endl;
	cout << pt3 << endl;

	cout << "Testing + operator" << endl;
	Point pt4 = pt2 + pt2;
	cout << pt4 << endl;

	cout << "Testing - operator" << endl;
	cout << pt4 - pt2 << endl;

	cout << "Testing * operator" << endl;
	cout << pt2 * 3.0 << endl;
	cout << 3.0 * pt2 << endl;
	cout << 3 * pt2 << endl;


	return 0;
}