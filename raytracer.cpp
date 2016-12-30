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
	cout << pt2.getX() << ", " << pt2.getY()  << ", " << pt2.getZ()<< endl;

	Point* pt3 = new Point(1.1, 2.3, 1.3);
	cout << "pt3.x = " << pt3->getX() << endl;
	cout << pt3->getX() << ", " << pt3->getY()  << ", " << pt3->getZ()<< endl;

	return 0;
}