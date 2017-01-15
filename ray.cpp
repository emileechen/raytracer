#include "ray.h"
#include "light.h"
#include <vector>


void Ray::init(Point o, Vector d) {
	origin = o;
	direction = d;
}
Ray::Ray() {
	init(Point(0, 0, 0), Vector(1, 0, 0));
}
Ray::Ray(Point o, Vector d) {
	init(o, d);
}
Ray::~Ray() {
}

Point Ray::intersection(double t, Geom obj) {
	Vector d = t * Vector(obj.transformation.getInverse() * Vector4(this->direction));
	Point o = Point(obj.transformation.getInverse() * Vector4(this->origin));
	return o + d;
}
void Ray::trace(World world) {
	int objInd = -1;					// Index to objects vector<Geom> of closest Geom
	double t = world.hit(*this, objInd);	// Ray t value for intersection point of ray and closest Geom
	// If the ray hits something...
	std::cout << "objInd: " << objInd << std::endl;
	std::cout << "t: " << t << std::endl;
	if (objInd != -1) {
		std::shared_ptr<Geom> obj = world.objects[objInd];
		Point intersection = this->intersection(t, *obj);
		Point intersectionTrans = Point(obj->transformation.getInverse() * Vector4(intersection));
		Vector normal = obj->normal(intersectionTrans);
		Vector viewNormal = this->direction * -1;
		Colour ambientColour = Colour(world.background);
		Colour diffuseColour = Colour();
		Colour specularColour = Colour();
		Colour reflectedColour = Colour();
		for (std::vector<std::shared_ptr<Light> >::size_type i = 0; i < world.lights.size(); i++) {
			
			Colour ambient = world.lights[i]->colour * obj->shading.ambient;
			ambientColour += ambient;
		}

	}

			// for light in world.lights:
			// 	if isinstance(light, AmbientLight):
			// 		ambient_color = ambient_color.add(light.color.multiply(obj.shading.ka))
			// 	else:
			// 		shadow_ray = light.ray_to_light(intersect_point)
			// 		light_distance = light.distance(shadow_ray.origin)
			// 		shadow_ray_t = world.hit(shadow_ray, t_min = SHADOW_THRESHOLD, avoid_ref = closest_ref)[0]
			// 		if (isinstance(light, PointLight) and shadow_ray_t >= light_distance) or (isinstance(light, DirectionalLight) and shadow_ray_t >= MAX_FLOAT): ## did not hit anything before light source
			// 			light_normal = shadow_ray.direction.normalize()
			// 			reflected_normal = light_normal.scalarMultiply(-1.0).add(obj_normal.scalarMultiply(2.0 * light_normal.dot(obj_normal)))
			// 			if isinstance(light, PointLight):
			// 				light_color = light.color.calc_falloff(light.falloff, light_distance)
			// 			else:
			// 				light_color = light.color
			// 			diffuse_color = diffuse_color.add(obj.shading.kd.multiply(light_color).scalarMultiply(light_normal.dot(obj_normal)).max(0.0))
			// 			specular_color = specular_color.add(obj.shading.ks.multiply(light_color).scalarMultiply(max(reflected_normal.dot(view_normal), 0.0) ** obj.shading.intensity))
			// if obj.shading.kr.nonzero() and depth < RECURSION_DEPTH:
			// 	reflected_direction = self.direction.add(obj_normal.scalarMultiply(2.0 * self.direction.scalarMultiply(-1.0).dot(obj_normal)))
			// 	reflected_ray = Ray(intersect_point, reflected_direction)
			// 	reflected_ray.trace(world, depth + 1)
			// 	reflected_color = reflected_color.add(reflected_ray.color)
			// self.color = self.color.add(ambient_color).add(diffuse_color).add(specular_color).add(reflected_color)
			// self.color = self.color.min(1.0)











}
std::ostream& operator<<(std::ostream &os, const Ray& r) { 
	os << "Origin: " << r.origin << std::endl;
	os << "Direction: " << r.direction;
	return os;
}