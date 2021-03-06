#include "image.h"
#include "lodepng.h"


void Image::init(unsigned int w, unsigned int h, const unsigned char* i) {
	width = w;
	height = h;
	image = std::vector<unsigned char>(i, i + (w * h * 4));
}
Image::Image() {
	const int w = 100;
	const int h = 100;
	unsigned char i[w * h * 4] = {255};
	init(w, h, i);
}
Image::Image(unsigned int w, unsigned int h) {
	unsigned char i[w * h * 4];
	for (int n = 0; n < w * h * 4; n++)
		if ((n + 1) % 4 == 0) {
			i[n] = 255;
		} else {
			i[n] = 0;
		}
	init(w, h, i);
}
Image::Image(const Image& im) {
	const unsigned char* arr = im.image.data();
	init(im.width, im.height, arr);
}
Image::~Image() {
}

void Image::assignColour(unsigned int x, unsigned int y, Colour c) {
	this->image[(y * this->width + x) * 4] = c.r * 255;
	this->image[(y * this->width + x) * 4 + 1] = c.g * 255;
	this->image[(y * this->width + x) * 4 + 2] = c.b * 255;
}
void Image::save(const char* filename) {
	// Encode the image
	unsigned error = lodepng::encode(filename, this->image, this->width, this->height);
	std::cout << "Saved to: " << filename << std::endl;

	// If there's an error, display it
	if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}
std::ostream& operator<<(std::ostream &os, const Image& im) {
	for (int i = 0; i < im.width * im.height; i++) {
		os << "(";
		for (int j = 0; j < 3; j++)
			os << (int) im.image[i*4 + j] << ", ";
		os << (int) im.image[i*4 + 4] << ") ";
		if (i % im.width == im.width - 1)
			os << std::endl;
	}
	return os;
}