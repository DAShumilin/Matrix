#include <iostream>
#include "Vector.h"

Vector::Vector() {

}

Vector::Vector(int n) {

	this->n = n;
	data = new double[n];
	for (int i = 0; i < n; ++i) {
		data[i] = 0.;
	}
}

Vector::Vector(const Vector& v){

	this->resize(v.n);

	for (int i = 0; i < this->n; ++i) {
		this->data[i] = v.data[i];
	}
}

Vector::~Vector() {

	delete[] data;
}

Vector Vector::operator+(const Vector& v) const {

	Vector c(n);
	for (int i = 0; i < n; ++i) {
		c.data[i] = v.data[i] + this->data[i];
	}
	return c;
}

Vector& Vector::operator+=(const Vector& v) {

	for (int i = 0; i < n; ++i) {
		this->data[i] = this->data[i] + v.data[i];
	}
	return *this;
}

Vector Vector::operator-(const Vector& v) const {

	Vector c(n);
	for (int i = 0; i < n; ++i) {
		c.data[i] = v.data[i] - this->data[i];
	}
	return c;
}

Vector& Vector::operator-=(const Vector& v) {

	for (int i = 0; i < n; ++i) {
		this->data[i] = this->data[i] - v.data[i];
	}
	return *this;
}

Vector Vector::operator*(double d) const {

	Vector c(n);
	for (int i = 0; i < n; ++i) {
		c.data[i] = d * this->data[i];
	}
	return c;
}

Vector& Vector::operator*=(double d) {

	for (int i = 0; i < n; ++i) {
		this->data[i] = d * this->data[i];
	}
	return *this;
}

Vector& Vector::operator=(const Vector& v) {

	if (this->n != v.n) {
		this->resize(v.n);
	}
	for (int i = 0; i < n; ++i) {
		this->data[i] = v.data[i];
	}
	return *this;
}

double& Vector::operator[](int i) {

	return data[i];
}

double Vector::operator[](int i) const {

	return data[i];
}

void Vector::resize(int newSize) {

	delete[] data;
	data = new double[newSize];
	this->n = newSize;

	for (int i = 0; i < n; ++i) {
		data[i] = 0.;
	}
}

double Vector::dot(const Vector& v) const {

	double ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += (this->data[i] * v.data[i]);
	}

	return ans;
}

std::ostream& operator<<(std::ostream& obj, const Vector& v){

	for (int i = 0; i < v.n; ++i) {
		obj << v.data[i] << " ";
	}
	std::cout << std::endl;

	return obj;
}

Vector operator*(double d, const Vector& v){

	return (v * d);
}
