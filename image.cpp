#include "image.h"


void Image::init(unsigned int w, unsigned int h) {
	width = w;
	height = h;
	image.reserve(w * h * 4);
}
Image::Image() {
	init(512, 512);
}
Image::Image(unsigned int w, unsigned int h) {
	init(w, h);
}
// Image::Image(const Image& im) {
// 	init(im.width, im.height);
// }
Image::~Image() {
}