#include "shading.h"


// void Shading::init(double ar, double ag, double ab, double dr, double dg, double db, double sr, double sg, double sb, double sp) {
// 	kar = ar;
// 	kag = ag;
// 	kab = ab;
// 	kdr = dr;
// 	kdg = dg;
// 	kdb = db;
// 	ksr = sr;
// 	ksg = sg;
// 	ksb = sb;
// 	ksp = sp;
// }
void Shading::init(Colour a, Colour d, Colour s, double i) {
	ambient = a;
	diffuse = d;
	specular = s;
	intensity = i;
}
Shading::Shading() {
	// Purple
	init(Colour(0.1, 0, 0.2), Colour(0.588, 0.392, 0.666), Colour(0.8, 0.8, 0.8), 64.0);
}
Shading::Shading(double kar, double kag, double kab, double kdr, double kdg, double kdb, double ksr, double ksg, double ksb, double intensity) {
	init(Colour(kar, kag, kab), Colour(kdr, kdg, kdb), Colour(ksr, ksg, ksb), intensity);
}
Shading::Shading(Colour ambient, Colour diffuse, Colour specular, double intensity) {
	init(ambient, diffuse, specular, intensity);
}
Shading::~Shading() {
}
std::ostream& operator<<(std::ostream &os, const Shading& s) { 
	os << "Ambient: " << s.ambient << std::endl;
	os << "Diffuse: " << s.diffuse << std::endl;
	os << "Specular: " << s.specular << ", " << s.intensity << "";
	return os;
}