#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>

using namespace std;


class Matrix {
	void init(const double*);
public:
	double *mat;
	Matrix();
	Matrix(double*);
	~Matrix();
	Matrix operator+(Matrix&);
	friend ostream& operator<<(ostream&, const Matrix&);
};

#endif