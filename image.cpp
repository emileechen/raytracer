#include "image.h"


void Image::init(unsigned int w, unsigned int h, const double* i) {
	width = w;
	height = h;
	image = std::vector<double>(i, i+ (w * h * 4));
}
Image::Image() {
	const int w = 100;
	const int h = 100;
	double i[w * h * 4] = {0};
	init(w, h, i);
}
Image::Image(unsigned int w, unsigned int h) {
	double i[w * h * 4];
	for (int n = 0; n < w * h * 4; n++)
		i[n] = 0;
	init(w, h, i);
}
Image::Image(const Image& im) {
	const double* arr = im.image.data();
	init(im.width, im.height, arr);
}
Image::~Image() {
}

std::ostream& operator<<(std::ostream &os, const Image& im) {
	for (int i = 0; i < im.width * im.height; i++) {
		os << "(" << im.image[i*4] << ", " << im.image[i*4 + 1] << ", " << im.image[i*4 + 2] << ", " << im.image[i*4 + 3] << ") ";
		if (i % im.width == im.width - 1)
			os << std::endl;
	}
    return os;
}