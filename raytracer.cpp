// #include "colour.h"
#include "image.h"
#include "lodepng.h"
#include "matrix.h"
#include "point.h"
#include "vector.h"


void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
	// Encode the image
	unsigned error = lodepng::encode(filename, image, width, height);
	std::cout << "Saved to: " << filename;

	// If there's an error, display it
	if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

int main() {
	std::cout << "Hello World!" << std::endl;

	std::cout << std::endl;

	// Test default constructor
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

	Vector v;
	std::cout << v << std::endl;
	std::cout << "Should be Vector(0.0, 0.0, 0.0)." << std::endl;

	std::cout << std::endl;

	Vector v2(1.2, 1.0, 2.0);
	Vector v3(2.0, 2.3, 0.5);
	std::cout << v2 << std::endl;
	std::cout << v3 << std::endl;
	std::cout << v2.dot(v3) << std::endl;
	std::cout << "(1.2, 1.0, 2.0) . (2.0, 2.3, 0.5) = 2.4 + 2.3 + 1.0 = 5.7" << std::endl;

	std::cout << std::endl;

	std::cout << v2.magnitude() << std::endl;
	std::cout << "Magnitude of (1.2, 1.0, 2.0) = sqrt(1.44 + 1 + 4) = 2.53..." << std::endl;

	std::cout << std::endl;

	Vector v4(2.0, 1.0, 2.0);
	std::cout << v4 << std::endl;
	std::cout << v4.normalize() << std::endl;
	std::cout << "Normalize (2.0, 1.0, 2.0) = (2/3, 1/3, 2/3)" << std::endl;

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

	// std::cout << std::endl;

	// const char* filename = "test.png";

	// // From: https://raw.githubusercontent.com/lvandeve/lodepng/master/examples/example_encode.cpp
	// // Generate some image
	// const unsigned width = 512, height = 512;
	// std::vector<unsigned char> image;
	// image.resize(width * height * 4);
	// for (unsigned y = 0; y < height; y++)
	// 	for(unsigned x = 0; x < width; x++) {
	// 		image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
	// 		image[4 * width * y + 4 * x + 1] = x ^ y;
	// 		image[4 * width * y + 4 * x + 2] = x | y;
	// 		image[4 * width * y + 4 * x + 3] = 255;
	// 	}

	// encodeOneStep(filename, image, width, height);

	// std::cout << std::endl;

	// const unsigned width = 512, height = 512;
	// Colour* image = (Colour*) malloc(width * height * sizeof(Colour));

	std::cout << std::endl;

	const unsigned int width = 512, height = 512;

	Image i = Image(5, 5);
	i.image[8] = 29;
	i.image[0] = 2;
	std::cerr << i << std::endl;

	Image i2 = Image(i);
	std::cerr << i2 << std::endl;

	i2.image[2] = 4;
	
	std::cerr << i << std::endl;
	std::cerr << i2 << std::endl;

	return 0;
}
