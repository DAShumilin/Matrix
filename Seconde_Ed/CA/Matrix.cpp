#include "Matrix.h"
#include <iostream>

Matrix::Matrix() {

}

Matrix::Matrix(const Matrix& m){

	delete[] this->data;
	this->data = new Vector[m.lines];

	for (int i = 0; i < this->lines; ++i) {
		this->data[i] = m.data[i];
	}

	this->lines = m.lines;
	this->columns = m.columns;
}

Matrix::Matrix(int lines, int columns) {

	this->lines = lines;
	this->columns = columns;

	this->data = new Vector[lines];

	for (int i = 0; i < lines; ++i) {
		this->data[i] = Vector(columns);
	}
}

Matrix::~Matrix() {

	delete[] data;
}

Matrix& Matrix::operator=(const Matrix& m){

	if (this == &m) {
		return *this;
	}

	this->lines = m.lines;
	this->columns = m.columns;
	delete[] this->data;
	this->data = new Vector[this->lines];

	for (int i = 0; i < this->lines; ++i) {
		this->data[i] = m.data[i];
	}

	return* this;
}

Matrix& Matrix::operator+=(const Matrix& m){
	
	if ((this->lines != m.lines) || (this->columns != m.columns)) {
		std::cout << "Error" << std::endl;
	}
	else {
		for (int i = 0; i < this->lines; ++i) {
			this->data[i] += m.data[i];
		}
	}

	return *this;
}

Matrix& Matrix::operator-=(const Matrix& m){
	
	if ((this->lines != m.lines) || (this->columns != m.columns)) {
		std::cout << "Error" << std::endl;
	}
	else {
		for (int i = 0; i < this->lines; ++i) {
			this->data[i] -= m.data[i];
		}
	}

	return *this;
}

Matrix Matrix::operator+(const Matrix& m) const {

	if ((this->lines != m.lines) || (this->columns != m.columns)) {
		std::cout << "Error" << std::endl;
	}
	else {
		Matrix tmp_m(this->lines, this->columns);

		for (int i = 0; i < this->lines; ++i) {
			tmp_m.data[i] = this->data[i] + m.data[i];
		}
		return tmp_m;
	}
}

Matrix Matrix::operator-(const Matrix& m) const{
	
	if ((this->lines != m.lines) || (this->columns != m.columns)) {
		std::cout << "Error" << std::endl;
	}
	else {
		Matrix tmp_m(this->lines, this->columns);

		for (int i = 0; i < this->lines; ++i) {
			tmp_m.data[i] = this->data[i] - m.data[i];
		}
		return tmp_m;
	}
}

Matrix Matrix::operator*(double d) const{

	Matrix tmp_m(this->lines, this->columns);

	for (int i = 0; i < this->lines; ++i) {
		tmp_m.data[i] = this->data[i] * d;
	}

	return tmp_m;
}

Matrix& Matrix::operator*=(double d){

	for (int i = 0; i < this->lines; ++i) {
		this->data[i] *= d;
	}

	return *this;
}

Vector& Matrix::operator[](int k){
	
	return this->data[k];
}

Matrix Matrix::operator*(const Matrix& m){
	
	if (this->columns != m.lines) {
		std::cout << "Error" << std::endl;
	}
	else {
		Matrix tmp_m_1(this->lines, m.columns);
		Matrix tmp_m_2(m);
		tmp_m_2.T();

		for (int i = 0; i < this->lines; ++i) {
			for (int j = 0; j < this->columns; ++j) {
				tmp_m_1[i][j] = this->data[i].dot(tmp_m_2.data[j]);
			}
		}

		return tmp_m_1;
	}
}

Matrix operator*(double d, const Matrix& v){

	return v * d;
}

Matrix& Matrix::T() {

	Matrix tmp_m(this->columns, this->lines);

	for (int i = 0; i < this->columns; ++i) {
		for (int j = 0; j < this->lines; ++j) {
			tmp_m.data[i][j] = this->data[j][i];
		}
	}

	*this = tmp_m;
	int tmp = this->lines;
	this->lines = this->columns;
	this->columns = tmp;

	return *this;
}

void Matrix::Gauss(const Vector& v, Matrix& m, Vector& v_1){

	if (this->columns != v.n) {
		std::cout << "Error" << std::endl;
	}
	else {

		for (int i = 0; i < m.columns; ++i) {
			for (int j = 1; j < m.lines - 1; ++j) {
				double f = this->data[0][i];
				double g = this->data[j][i];
				double h = g / f;

				m.data[j] = this->data[j] - h * this->data[0];
				v_1.data[j] = v.data[j] - h * v.data[0];
			}
		}
	}
}