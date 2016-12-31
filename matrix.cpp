#include "matrix.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;


void Matrix::init(const double* arr) {
	mat = new double[4 * 4];
	int x, y;
	for (x=0; x < 4; x++) {
		for (y=0; y < 4; y++) {
			mat[y*4 + x] = arr[y*4 + x];
		}
	}
}
Matrix::Matrix() {
	//Initialize with zeros.
	double arr[4 * 4] = {0};
	init(arr);
}
Matrix::Matrix(double* arr) {
	init(arr);
}
Matrix::~Matrix() {
}

Matrix Matrix::operator+(Matrix& m) {
	Matrix ma;
	int x, y;
	for (x=0; x < 4; x++) {
		for (y=0; y < 4; y++) {
			ma.mat[y*4 + x] = m.mat[y*4 + x] + this->mat[y*4 + x];
		}
	}
	return ma;
}
ostream& operator<<(ostream &os, const Matrix& m) { 
    os << "[ [ " << m.mat[0] << " " << m.mat[1] << " " << m.mat[2] << " " << m.mat[3] << " ]" << endl;
    os << "  [ " << m.mat[4] << " " << m.mat[5] << " " << m.mat[6] << " " << m.mat[7] << " ]" << endl;
    os << "  [ " << m.mat[8] << " " << m.mat[9] << " " << m.mat[10] << " " << m.mat[11] << " ]" << endl;
    os << "  [ " << m.mat[12] << " " << m.mat[13] << " " << m.mat[14] << " " << m.mat[15] << " ] ]" << endl;
    return os;
}