#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>


class Matrix {
	void init(const double*);
public:
	double *mat;
	double *inv;
	bool hasInverse;
	Matrix();
	Matrix(double*);
	~Matrix();
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(double);
	friend Matrix operator*(double, Matrix&);
	Matrix dot(Matrix&);
	friend std::ostream& operator<<(std::ostream&, const Matrix&);
};

bool inverse(double*, double*);
Matrix identity();		// IS THIS SUPPOSED TO BE HERE THO BC ITS GLOABL NOW AMIRITE
Matrix translation(double, double, double);
Matrix rotation(double, double, double);
Matrix scaling(double, double, double);

#endif