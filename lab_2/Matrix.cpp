#include <iostream>
#include "Header.h"
#include <string>
using namespace std;


void Matrix::matrixSize(unsigned int row, unsigned int column) {
	this->row = row;
	this->column = column;
	pmas = new double[row*column];
	
}

Matrix::Matrix() {
	row = 1;
	column = 1;
	pmas = new double[row*column];
}

Matrix::~Matrix() {
	if (pmas != nullptr)
		delete pmas;
}

unsigned int Matrix::getRow() const{
	return row;
}

unsigned int Matrix::getColumn() const {
	return column;
}

Matrix & Matrix::operator = (const Matrix & other) {
	matrixSize(other.getRow(), other.getColumn());
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			(pmas + i * column)[j] = other[i][j];
		}
	}
	return *this;
}

bool Matrix:: operator == (const Matrix & other) const {
	if (other.getRow() != this->row || other.getColumn() != this->column)
	{
		return false;
	}
	else
	{
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if ((pmas + i * column)[j] == other[i][j])
					return false;
			}
		}
	}
	return true;
}

Matrix & Matrix::operator + (const Matrix & other) {
	Matrix a;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			a[i][j]=(pmas + i * column)[j] + other[i][j];
		}
	}
	return a;
}

Matrix & Matrix::operator - (const Matrix & other) {
	Matrix a;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			a[i][j]=(pmas + i * column)[j] - other[i][j];
		}
	}
	return a;
}

Matrix & Matrix::operator * (const Matrix & other) {
	Matrix a;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			a[i][j] = 0;
		}
	}
	if (other.getRow() == this->getColumn()) {
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				for (int t = 0; t < j; t++) {
					a[i][j] += (pmas + i * column)[t] * other[t][j];
				}
			}
		}
	}
	return a;
}

Matrix & Matrix::operator * (const double & num) {
	Matrix a;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			a [i][j]= (pmas + i * column)[j] * num;
		}
	}
	return a;
}

Matrix & Matrix::operator ~ () {
	double temp=0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			temp = (pmas + i * column)[j];
			(pmas + i * column)[j] == (pmas + j * column)[i];
			(pmas + j * column)[i]=temp;
		}
	}
	return *this;
}

std::ostream & operator<<(std::ostream & output, const Matrix & matr) // !!!
{
	for (size_t row = 0; row < matr.getRow(); ++row)
	{
		for (size_t column = 0; column < matr.getColumn(); ++column)
		{
			output << matr[row][column] << "\t";
		}
		output << "\n";
	}

	return output;
}
std::istream & operator >> (std::istream & input, Matrix & matr)
{
	std::string snum;
	for (size_t row = 0; row < matr.getRow(); ++row)
	{
		std::cout << "Please input row number " << row << "." << std::endl;
		for (size_t column = 0; column < matr.getColumn(); ++column)
		{
			std::cout << "please input value of x[" << row << "][" << column << "] " << ":";
			input >> snum;
			matr[row][column] = std::atol(snum.c_str());
			std::cout << std::endl;
		}
	}
	return input;
}
double * Matrix::operator[](const int & row) const
{
	return (pmas + row * column);
}

