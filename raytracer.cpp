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
	world.addSphere(-0.25, 0, 2, 0.75);
	world.addSphere(2, 3, 6, 1.5);
	// world.objects[0]->transformation = translation(1, 0, 0);
	world.addPointLight(5, 5, 0, 1, 1, 1);
	world.addAmbientLight(0.1, 0.1, 0.1);

	for (unsigned int y = 0; y < height; y++) {
		for (unsigned int x = 0; x < width; x++) {
			Colour colour = rays[y * width + x].trace(world);
			image.assignColour(x, y, colour);
		}
	}


	// std::cout << rays[100 * 200 + 100] << std::endl;
	// Colour colour = rays[100 * 200 + 100].trace(world);
	// image.assignColour(100, 100, colour);



	const char* filename = "test00.png";
	image.save(filename);

	return 0;
}
