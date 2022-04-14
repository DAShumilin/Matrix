#pragma once

#include <iostream>

class Vector {

	friend class Matrix;

private:

	double* data = 0;
	int n = 0;

public:

	Vector();
	Vector(int n);
	Vector(const Vector& v);
	~Vector();

	void resize(int newSize);
	double dot(const Vector& v) const;
	double& operator[](int i);
	double operator[](int i) const;

	Vector& operator=(const Vector& v);
	Vector operator+(const Vector& v) const;
	Vector operator-(const Vector& v) const;
	Vector& operator+=(const Vector& v);
	Vector& operator-=(const Vector& v);
	Vector operator*(double d) const;
	Vector& operator*=(double d);

	friend std::ostream& operator<<(std::ostream& obj, const Vector& v);
	friend Vector operator*(double d, const Vector& v);
};