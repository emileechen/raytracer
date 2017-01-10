#include "shading.h"


void Shading::init(double ar, double ag, double ab, double dr, double dg, double db, double sr, double sg, double sb, double sp) {
	kar = ar;
	kag = ag;
	kab = ab;
	kdr = dr;
	kdg = dg;
	kdb = db;
	ksr = sr;
	ksg = sg;
	ksb = sb;
}
Shading::Shading() {
	// Glossy metallic reflective blue
	init(0.1, 0, 0.2, 0.588, 0.392, 0.666, 0.8, 0.8, 0.8, 13.0);
}
Shading::Shading(double kar, double kag, double kab, double kdr, double kdg, double kdb, double ksr, double ksg, double ksb, double ksp) {
	init(kar, kag, kab, kdr, kdg, kdb, ksr, ksg, ksb, ksp);
}
Shading::~Shading() {
}