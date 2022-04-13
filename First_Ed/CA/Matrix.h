#pragma once

#include "Vector.h"

class Matrix {

private:

	int lines = 0;
	int columns = 0;
	Vector* data = 0;

public:

	Matrix();
	Matrix(const Matrix& m);
	Matrix(int lines, int columns);
	~Matrix();

	Matrix& operator=(const Matrix& m);
	Matrix& operator+=(const Matrix& m);
	Matrix& operator-=(const Matrix& m);
	Matrix operator+(const Matrix& m) const;
	Matrix operator-(const Matrix& m) const;
	Matrix operator*(double d) const;
	Matrix& operator*=(double d);
	Vector& operator[](int k);
	Matrix operator*(const Matrix& m);

	friend Matrix operator*(double d, const Matrix& v);
	Matrix& T();
};