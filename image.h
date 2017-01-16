#ifndef IMAGE_H
#define IMAGE_H
#include <iostream>
#include <vector>

#include "colour.h"


class Image {
	void init(unsigned int, unsigned int, const unsigned char*);
public:
	std::vector<unsigned char> image;
	unsigned int width, height;
	Image();									// default constructor
	Image(unsigned int, unsigned int);
	Image(const Image&);
	~Image();									// deconstructor
	void assignColour(unsigned int, unsigned int, Colour);
	void save(const char*);
	friend std::ostream& operator<<(std::ostream&, const Image&);
};


#endif