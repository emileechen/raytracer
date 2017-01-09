#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <vector>



class Image {
	void init(unsigned int, unsigned int, const unsigned char*);
public:
	std::vector<unsigned char> image;
	unsigned int width, height;
	Image();									// default constructor
	Image(unsigned int, unsigned int);
	Image(const Image&);
	~Image();									// deconstructor
	friend std::ostream& operator<<(std::ostream&, const Image&);
};



// class Image {
// 	void init(unsigned int, unsigned int);
// public:
// 	std::vector<double> image;
// 	unsigned int width, height;
// 	Image();									// default constructor
// 	Image(unsigned int, unsigned int);
// 	Image(const Image&);
// 	~Image();									// deconstructor
// 	friend std::ostream& operator<<(std::ostream&, const Image&);
// };


#endif