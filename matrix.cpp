#include "matrix.h"
#include <cmath>
#include <iostream>
#include <string>

using namespace std;


bool inverse(double* m, double* invOut) {
	double inv[16], det;
	int i;

	inv[0] = m[5]  * m[10] * m[15] - 
			 m[5]  * m[11] * m[14] - 
			 m[9]  * m[6]  * m[15] + 
			 m[9]  * m[7]  * m[14] +
			 m[13] * m[6]  * m[11] - 
			 m[13] * m[7]  * m[10];

	inv[4] = -m[4]  * m[10] * m[15] + 
			  m[4]  * m[11] * m[14] + 
			  m[8]  * m[6]  * m[15] - 
			  m[8]  * m[7]  * m[14] - 
			  m[12] * m[6]  * m[11] + 
			  m[12] * m[7]  * m[10];

	inv[8] = m[4]  * m[9] * m[15] - 
			 m[4]  * m[11] * m[13] - 
			 m[8]  * m[5] * m[15] + 
			 m[8]  * m[7] * m[13] + 
			 m[12] * m[5] * m[11] - 
			 m[12] * m[7] * m[9];

	inv[12] = -m[4]  * m[9] * m[14] + 
			   m[4]  * m[10] * m[13] +
			   m[8]  * m[5] * m[14] - 
			   m[8]  * m[6] * m[13] - 
			   m[12] * m[5] * m[10] + 
			   m[12] * m[6] * m[9];

	inv[1] = -m[1]  * m[10] * m[15] + 
			  m[1]  * m[11] * m[14] + 
			  m[9]  * m[2] * m[15] - 
			  m[9]  * m[3] * m[14] - 
			  m[13] * m[2] * m[11] + 
			  m[13] * m[3] * m[10];

	inv[5] = m[0]  * m[10] * m[15] - 
			 m[0]  * m[11] * m[14] - 
			 m[8]  * m[2] * m[15] + 
			 m[8]  * m[3] * m[14] + 
			 m[12] * m[2] * m[11] - 
			 m[12] * m[3] * m[10];

	inv[9] = -m[0]  * m[9] * m[15] + 
			  m[0]  * m[11] * m[13] + 
			  m[8]  * m[1] * m[15] - 
			  m[8]  * m[3] * m[13] - 
			  m[12] * m[1] * m[11] + 
			  m[12] * m[3] * m[9];

	inv[13] = m[0]  * m[9] * m[14] - 
			  m[0]  * m[10] * m[13] - 
			  m[8]  * m[1] * m[14] + 
			  m[8]  * m[2] * m[13] + 
			  m[12] * m[1] * m[10] - 
			  m[12] * m[2] * m[9];

	inv[2] = m[1]  * m[6] * m[15] - 
			 m[1]  * m[7] * m[14] - 
			 m[5]  * m[2] * m[15] + 
			 m[5]  * m[3] * m[14] + 
			 m[13] * m[2] * m[7] - 
			 m[13] * m[3] * m[6];

	inv[6] = -m[0]  * m[6] * m[15] + 
			  m[0]  * m[7] * m[14] + 
			  m[4]  * m[2] * m[15] - 
			  m[4]  * m[3] * m[14] - 
			  m[12] * m[2] * m[7] + 
			  m[12] * m[3] * m[6];

	inv[10] = m[0]  * m[5] * m[15] - 
			  m[0]  * m[7] * m[13] - 
			  m[4]  * m[1] * m[15] + 
			  m[4]  * m[3] * m[13] + 
			  m[12] * m[1] * m[7] - 
			  m[12] * m[3] * m[5];

	inv[14] = -m[0]  * m[5] * m[14] + 
			   m[0]  * m[6] * m[13] + 
			   m[4]  * m[1] * m[14] - 
			   m[4]  * m[2] * m[13] - 
			   m[12] * m[1] * m[6] + 
			   m[12] * m[2] * m[5];

	inv[3] = -m[1] * m[6] * m[11] + 
			  m[1] * m[7] * m[10] + 
			  m[5] * m[2] * m[11] - 
			  m[5] * m[3] * m[10] - 
			  m[9] * m[2] * m[7] + 
			  m[9] * m[3] * m[6];

	inv[7] = m[0] * m[6] * m[11] - 
			 m[0] * m[7] * m[10] - 
			 m[4] * m[2] * m[11] + 
			 m[4] * m[3] * m[10] + 
			 m[8] * m[2] * m[7] - 
			 m[8] * m[3] * m[6];

	inv[11] = -m[0] * m[5] * m[11] + 
			   m[0] * m[7] * m[9] + 
			   m[4] * m[1] * m[11] - 
			   m[4] * m[3] * m[9] - 
			   m[8] * m[1] * m[7] + 
			   m[8] * m[3] * m[5];

	inv[15] = m[0] * m[5] * m[10] - 
			  m[0] * m[6] * m[9] - 
			  m[4] * m[1] * m[10] + 
			  m[4] * m[2] * m[9] + 
			  m[8] * m[1] * m[6] - 
			  m[8] * m[2] * m[5];

	det = m[0] * inv[0] + m[1] * inv[4] + m[2] * inv[8] + m[3] * inv[12];

	if (det == 0)
		return false;

	det = 1.0 / det;

	for (i = 0; i < 16; i++)
		invOut[i] = inv[i] * det;

	return true;
}

void Matrix::init(const double* arr) {
	mat = new double[4 * 4];
	inv = new double[4 * 4];
	int x, y;
	for (x=0; x < 4; x++) {
		for (y=0; y < 4; y++) {
			mat[y*4 + x] = arr[y*4 + x];
		}
	}
	hasInverse = inverse(mat, inv);
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
	double arr[4 * 4] = {0};
	int x, y;
	for (x=0; x < 4; x++) {
		for (y=0; y < 4; y++) {
			arr[y*4 + x] = m.mat[y*4 + x] + this->mat[y*4 + x];
		}
	}
	return Matrix(arr);
}
Matrix Matrix::operator-(Matrix& m) {
	double arr[4 * 4] = {0};
	int x, y;
	for (x=0; x < 4; x++) {
		for (y=0; y < 4; y++) {
			arr[y*4 + x] = m.mat[y*4 + x] - this->mat[y*4 + x];
		}
	}
	return Matrix(arr);
}
Matrix Matrix::operator*(double c) {
	Matrix ma;
	int x, y;
	for (x=0; x < 4; x++) {
		for (y=0; y < 4; y++) {
			ma.mat[y*4 + x] = this->mat[y*4 + x] * c;
		}
	}
	if (this->hasInverse == true)
		ma.hasInverse = true;
		for (x=0; x < 4; x++) {
			for (y=0; y < 4; y++) {
				ma.inv[y*4 + x] = this->inv[y*4 + x] / c;
			}
		}
	return ma;
}
Matrix operator*(double c, Matrix m) {
	return m * c;
}
Matrix identity() {
	double arr[4 * 4] = {0};
	for (int x = 0; x < 4; x++)
		arr[x*4 + x] = 1;
	return Matrix(arr);
}
ostream& operator<<(ostream &os, const Matrix& m) { 
	os << "[ [ " << m.mat[0] << " " << m.mat[1] << " " << m.mat[2] << " " << m.mat[3] << " ]" << endl;
	os << "  [ " << m.mat[4] << " " << m.mat[5] << " " << m.mat[6] << " " << m.mat[7] << " ]" << endl;
	os << "  [ " << m.mat[8] << " " << m.mat[9] << " " << m.mat[10] << " " << m.mat[11] << " ]" << endl;
	os << "  [ " << m.mat[12] << " " << m.mat[13] << " " << m.mat[14] << " " << m.mat[15] << " ] ]";

	os << endl;

	if (m.hasInverse == true) {
		os << "inverse: " << endl;
		os << "[ [ " << m.inv[0] << " " << m.inv[1] << " " << m.inv[2] << " " << m.inv[3] << " ]" << endl;
		os << "  [ " << m.inv[4] << " " << m.inv[5] << " " << m.inv[6] << " " << m.inv[7] << " ]" << endl;
		os << "  [ " << m.inv[8] << " " << m.inv[9] << " " << m.inv[10] << " " << m.inv[11] << " ]" << endl;
		os << "  [ " << m.inv[12] << " " << m.inv[13] << " " << m.inv[14] << " " << m.inv[15] << " ] ]";
	} else {
		os << "no inverse";
	}

	return os;
}