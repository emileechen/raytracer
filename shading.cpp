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
void Shading::init(Colour a, Colour d, Colour s, double sp) {
	ambient = a;
	diffuse = d;
	specular = s;
	specP = sp;
}
Shading::Shading() {
	// Glossy metallic reflective blue
	init(Colour(0.1, 0, 0.2), Colour(0.588, 0.392, 0.666), Colour(0.8, 0.8, 0.8), 13.0);
}
Shading::Shading(double kar, double kag, double kab, double kdr, double kdg, double kdb, double ksr, double ksg, double ksb, double ksp) {
	init(Colour(kar, kag, kab), Colour(kdr, kdg, kdb), Colour(ksr, ksg, ksb), ksp);
}
Shading::Shading(Colour ambient, Colour diffuse, Colour specular, double specP) {
	init(ambient, diffuse, specular, specP);
}
Shading::~Shading() {
}
std::ostream& operator<<(std::ostream &os, const Shading& s) { 
	os << "Ambient: " << s.ambient << std::endl;
	os << "Diffuse: " << s.diffuse << std::endl;
	os << "Specular: " << s.specular << ", " << s.specP << "";
	return os;
}