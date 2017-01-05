#include "colour.h"
#include "lodepng.h"
#include "matrix.h"
#include "point.h"
#include "vector.h"
#include <iostream>

using namespace std;

void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
	// Encode the image
	unsigned error = lodepng::encode(filename, image, width, height);
	cout << "Saved to: " << filename;

	// If there's an error, display it
	if (error) cout << "encoder error " << error << ": " << lodepng_error_text(error) << endl;
}

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

	cout << endl;

	cout << v2.magnitude() << endl;
	cout << "Magnitude of (1.2, 1.0, 2.0) = sqrt(1.44 + 1 + 4) = 2.53..." << endl;

	cout << endl;

	Vector v4(2.0, 1.0, 2.0);
	cout << v4 << endl;
	cout << v4.normalize() << endl;
	cout << "Normalize (2.0, 1.0, 2.0) = (2/3, 1/3, 2/3)" << endl;

	cout << endl;

	// Matrix tests
	cout << "Initialize a basic matrix..." << endl;
	Matrix m;
	cout << m << endl;

	cout << endl;

	cout << "Initialize a specified matrix..." << endl;
	double arr[] = { 0,0,0,0,
					 1,2,2,2,
					 2,2,2,2,
					 3,3,3,3};
	Matrix m1(arr);
	cout << m1 << endl;

	cout << endl;

	cout << "Initialize a identity matrix..." << endl;
	Matrix m3 = identity();
	cout << m3 << endl;

	cout << endl;

	cout << "Matrix addition..." << endl;
	double arr1[] = { 1,1,2,3,
					  1,0,2,2,
					  1,2,1,2,
					  1,3,3,1};
	Matrix m2(arr1);
	cout << m1 + m2 << endl;

	cout << endl;

	double arr2[] = { 1,2,1,1,
					  1,1,-1,-2,
					  1,-1,-1,2,
					  1,-2,1,1};
	Matrix m4(arr2);
	cout << m4 << endl;

	cout << endl;

	cout << "Matrix scalar multiplication..." << endl;
	cout << m4 * 2 << endl;
	cout << 2 * m4 << endl;

	cout << endl;

	cout << "Matrix multiplication..." << endl;
	cout << (m4 * 2).dot(m4) << endl;

	cout << endl;

	cout << "Translation matrix..." << endl;
	cout << translation(1.0, 2.0, 1.0) << endl;

	cout << endl;

	cout << "Rotation matrix..." << endl;
	cout << rotation(1, 0, 0) << endl;
	cout << "Should be: " << endl;
	cout << "[[ 1.        ,  0.        ,  0.        ,  0.        ]," << endl;
    cout << " [ 0.        ,  0.9998477 , -0.01745241,  0.        ]," << endl;
    cout << " [ 0.        ,  0.01745241,  0.9998477 ,  0.        ]," << endl;
    cout << " [ 0.        ,  0.        ,  0.        ,  1.        ]]";

	cout << endl;

	cout << "Scaling matrix..." << endl;
	cout << scaling(1.0, 2.0, 3.0) << endl;

	cout << endl;

	const char* filename = "test.png";

	// From: https://raw.githubusercontent.com/lvandeve/lodepng/master/examples/example_encode.cpp
	// Generate some image
	const unsigned width = 512, height = 512;
	vector<unsigned char> image;
	image.resize(width * height * 4);
	for (unsigned y = 0; y < height; y++)
		for(unsigned x = 0; x < width; x++) {
			image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
			image[4 * width * y + 4 * x + 1] = x ^ y;
			image[4 * width * y + 4 * x + 2] = x | y;
			image[4 * width * y + 4 * x + 3] = 255;
		}

	encodeOneStep(filename, image, width, height);

	cout << endl;

	const unsigned width = 512, height = 512;
	Colour* image = (Colour*) malloc(width * height * sizeof(Colour));

	return 0;
}
