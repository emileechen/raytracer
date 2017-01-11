#include "light.h"


void Light::init(Colour c) {
	colour = c;
}
Light::Light() {
	// Default colour is white.
	init(Colour(1, 1, 1));
}
Light::~Light() {
}

std::ostream& operator<<(std::ostream &os, const Light& l) { 
	os << "Light:	" << l.colour;
	return os;
}


