#include "camera.h"
#include "colour.h"
#include "geom.h"
#include "image.h"
#include "light.h"
#include "lodepng.h"
#include "matrix.h"
#include "point.h"
#include "shading.h"
#include "vector.h"
#include <vector>


void encodeOneStep(const char* filename, Image im, unsigned width, unsigned height) {
	// Encode the image
	unsigned error = lodepng::encode(filename, im.image, width, height);
	std::cout << "Saved to: " << filename << std::endl;

	// If there's an error, display it
	if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

int main() {
	std::cout << "Hello World!" << std::endl;

	std::cout << std::endl;

	// Test Point default constructor
	Point pt;
	std::cout << pt << std::endl;
	std::cout << "Should be Point(0.0, 0.0, 0.0)." << std::endl;

	std::cout << std::endl;

	Point* pt1 = new Point();
	std::cout << *pt1 << std::endl;
	std::cout << "Should be Point(0.0, 0.0, 0.0)." << std::endl;

	std::cout << std::endl;

	Point pt2(1.1, 2.3, 1.3);
	std::cout << pt2 << std::endl;
	std::cout << "Should be Point(1.1, 2.3, 1.3)." << std::endl;

	std::cout << std::endl;

	std::cout << "Testing + operator" << std::endl;
	Point pt3 = pt2 + pt2;
	std::cout << pt3 << std::endl;
	std::cout << "(1.1, 2.3, 1.3) + (1.1, 2.3, 1.3) = (2.2, 4.6, 2.6)" << std::endl;

	std::cout << std::endl;

	std::cout << "Testing - operator" << std::endl;
	std::cout << pt3 - pt2 << std::endl;
	std::cout << "(2.2, 4.6, 2.6) - (1.1, 2.3, 1.3) = (1.1, 2.3, 1.3)" << std::endl;

	std::cout << std::endl;

	std::cout << "Testing * operator" << std::endl;
	std::cout << pt2 * 3.0 << std::endl;
	std::cout << 3.0 * pt2 << std::endl;
	std::cout << 3 * pt2 << std::endl;
	std::cout << "2 * (1.1, 2.3, 1.3) = (2.2, 4.6, 2.6)" << std::endl;

	std::cout << std::endl;

	std::cout << "Testing vectorTo()" << std::endl;

	Point origin(0, 0, 0);
	Vector v1 = origin.vectorTo(pt2);
	std::cout << v1 << std::endl;
	std::cout << "(0, 0, 0) - (1.1, 2.3, 1.3) = Vector(1.1, 2.3, 1.3)" << std::endl;

	std::cout << std::endl;

	// Vector default constructor
	Vector v;
	std::cout << v << std::endl;
	std::cout << "Should be Vector(0.0, 0.0, 0.0)." << std::endl;

	std::cout << std::endl;

	// Vector dot()
	Vector v2(1.2, 1.0, 2.0);
	Vector v3(2.0, 2.3, 0.5);
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << v2.dot(v3) << std::endl;
	std::cout << "(1.2, 1.0, 2.0) . (2.0, 2.3, 0.5) = 2.4 + 2.3 + 1.0 = 5.7" << std::endl;

	std::cout << std::endl;

	// Vector magnitude()
	std::cout << v2.magnitude() << std::endl;
	std::cout << "Magnitude of (1.2, 1.0, 2.0) = sqrt(1.44 + 1 + 4) = 2.53..." << std::endl;

	std::cout << std::endl;

	// Vector normalize()
	Vector v4(2.0, 1.0, 2.0);
	std::cout << v4 << std::endl;
	std::cout << v4.normalize() << std::endl;
	std::cout << "Normalize (2.0, 1.0, 2.0) = (2/3, 1/3, 2/3)" << std::endl;

	std::cout << std::endl;

	// Vector4 constructors
	Vector4 vec;
	std::cout << vec << std::endl;
	std::cout << "Should be Vector4(0.0, 0.0, 0.0, 1.0)." << std::endl;

	std::cout << std::endl;

	Vector4 vec2(v4, 1);
	std::cout << vec2 << std::endl;
	std::cout << "Should be Vector4(2.0, 1.0, 2.0, 1.0)." << std::endl;

	std::cout << std::endl;

	// Shading constructor
	Shading s(0.1, 0, 0.2, 0.588, 0.392, 0.666, 0.8, 0.8, 0.8, 13.0);
	std::cout << s << std::endl;

	std::cout << std::endl;

	// Matrix tests
	std::cout << "Initialize a basic matrix..." << std::endl;
	Matrix m;
	std::cout << m << std::endl;

	std::cout << std::endl;

	std::cout << "Initialize a specified matrix..." << std::endl;
	double arr[] = { 0,0,0,0,
					 1,2,2,2,
					 2,2,2,2,
					 3,3,3,3};
	Matrix m1(arr);
	std::cout << m1 << std::endl;

	std::cout << std::endl;

	std::cout << "Initialize a identity matrix..." << std::endl;
	Matrix m3 = identity();
	std::cout << m3 << std::endl;

	std::cout << std::endl;

	std::cout << "Matrix addition..." << std::endl;
	double arr1[] = { 1,1,2,3,
					  1,0,2,2,
					  1,2,1,2,
					  1,3,3,1};
	Matrix m2(arr1);
	std::cout << m1 + m2 << std::endl;

	std::cout << std::endl;

	double arr2[] = { 1,2,1,1,
					  1,1,-1,-2,
					  1,-1,-1,2,
					  1,-2,1,1};
	Matrix m4(arr2);
	std::cout << m4 << std::endl;

	std::cout << std::endl;

	std::cout << "Matrix scalar multiplication..." << std::endl;
	std::cout << m4 * 2 << std::endl;
	std::cout << 2 * m4 << std::endl;

	std::cout << std::endl;

	std::cout << "Matrix multiplication..." << std::endl;
	std::cout << (m4 * 2).dot(m4) << std::endl;

	std::cout << std::endl;

	std::cout << "Matrix * Vector4..." << std::endl;
	std::cout << m1 * vec2 << std::endl;
	std::cout << "Should be Vector4(0, 10, 12, 18)." << std::endl;

	std::cout << std::endl;

	std::cout << "Translation matrix..." << std::endl;
	std::cout << translation(1.0, 2.0, 1.0) << std::endl;

	std::cout << std::endl;

	std::cout << "Rotation matrix..." << std::endl;
	std::cout << rotation(1, 0, 0) << std::endl;
	std::cout << "Should be: " << std::endl;
	std::cout << "[[ 1.        ,  0.        ,  0.        ,  0.        ]," << std::endl;
	std::cout << " [ 0.        ,  0.9998477 , -0.01745241,  0.        ]," << std::endl;
	std::cout << " [ 0.        ,  0.01745241,  0.9998477 ,  0.        ]," << std::endl;
	std::cout << " [ 0.        ,  0.        ,  0.        ,  1.        ]]";

	std::cout << std::endl;

	std::cout << "Scaling matrix..." << std::endl;
	std::cout << scaling(1.0, 2.0, 3.0) << std::endl;

	std::cout << std::endl;

	// const unsigned int width = 5, height = 5;

	// Image i = Image(width, height);
	// std::cerr << i << std::endl;
	// Image i2 = Image(i);
	// std::cerr << i2 << std::endl;

	// i.image[0] = 255;	// first pixel red
	// i.image[1] = 0;
	// i.image[2] = 0;

	// i.image[4] = 0;		// second pixel green
	// i.image[5] = 255;
	// i.image[6] = 0;

	// const char* filename = "test.png";
	// encodeOneStep(filename, i, width, height);

	// std::cout << std::endl;

	Point p(0, 0, 0);
	Sphere sph(p, 1);
	std::cout << sph <<std::endl;
	std::cout << sph.normal(Point(2, 2, 0)) << std::endl;

	std::cout << std::endl;

	// Lights
	std::cout << Light() << std::endl;
	std::cout << PointLight() << std::endl;
	std::cout << DirectionalLight() << std::endl;

	std::cout << std::endl;

	// Rays
	std::cout << Ray() << std::endl;

	std::cout << std::endl;

	// Ray intersection
	std::cout << Ray(Point(1,1,0), Vector(1,0,1)).intersection(5, identity()) << std::endl;
	std::cout << "Should be: (1, 1, 0) + 5 * (1, 0, 1) = (6, 1, 5)" << std::endl;

	std::cout << std::endl;

	// Camera
	std::cout << Camera() << std::endl;

	std::cout << std::endl;

	// Camera.makeRays() test
	std::vector<Ray> rays = Camera().makeRays(3, 3);
	for(int i = 0; i < rays.size(); ++i)
		std::cout << rays[i] << " " << std::endl;
	std::cout << "Should be:	(-1, 1, 1)	(0, 1, 1)	(1, 1, 1)" << std::endl;
	std::cout << "		(-1, 0, 1)	(0, 0, 1)	(1, 0, 1)" << std::endl;
	std::cout << "		(-1, -1, 1)	(0, -1, 1)	(1, -1, 1)" << std::endl;


	return 0;
}
