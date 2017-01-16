#include "camera.h"
#include "colour.h"
#include "geom.h"
#include "image.h"
#include "light.h"
#include "matrix.h"
#include "point.h"
#include "ray.h"
#include "shading.h"
#include "vector.h"
#include "world.h"

#include <vector>


int main() {

	World world = World();
	const char* inputfilename = "input00.txt";
	const unsigned int width = 200, height = 200;
	Image image = Image(width, height);
	Camera camera = Camera(Point(0, 0, 0), Point(-1, -1, 1), Point(1, -1, 1), Point(-1, 1, 1), Point(1, 1, 1));
	std::vector<Ray> rays = Camera().makeRays(width, height);
	world.addSphere(0, 0, 2, 0.75);
	// world.objects[0]->transformation = translation(1, 0, 0);
	world.addPointLight(1, 1, 1, 1, 1, 1);
	world.addAmbientLight(0.1, 0.1, 0.1);

	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			Colour colour = rays[y * width + x].trace(world);
			// std::cout << colour << std::endl;
			image.assignColour(x, y, colour);
		}
	}

	const char* filename = "test00.png";
	image.save(filename);

	return 0;
}
