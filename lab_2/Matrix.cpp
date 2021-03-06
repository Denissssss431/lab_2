#include "Matrix.h"
#include <iostream>
#include <string>
#include <time.h>
//using namespace std;


void Matrix::matrixSize(unsigned int row, unsigned int column) {
	this->row = row;
	this->column = column;
	//pmas = new double[row*column];
	
}

Matrix::Matrix() {
	row = 1;
	column = 1;
	pmas = new double[row*column];
}

Matrix::Matrix(const unsigned int & row, const unsigned int & column)
{
	matrixSize(row, column);
	pmas = new double[row* column];
}

Matrix::Matrix(const Matrix & other)
{
	*this = other;
}
Matrix::~Matrix() {
	if (pmas != nullptr)
	{
		delete pmas;
	}
}

unsigned int Matrix::getRow() const{
	return row;
}

unsigned int Matrix::getColumn() const {
	return column;
}

Matrix & Matrix::operator = (const Matrix & other) {
	double temp = 123123;
	matrixSize(other.getRow(), other.getColumn());
	pmas = new double[row*column];
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			temp = other[i][j];
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
				if ((pmas + i * column)[j] != other[i][j])
					return false;
			}
		}
	}
	return true;
}

Matrix Matrix::operator + (Matrix & other) {
	Matrix a;
	a.matrixSize(other.row, other.column);
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			a[i][j]=(pmas + i * column)[j] + other[i][j];
		}
	}
	return a;
}

Matrix Matrix::operator - (const Matrix & other) {
	Matrix a;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			a[i][j]=(pmas + i * column)[j] - other[i][j];
		}
	}
	return a;
}

Matrix Matrix::operator * (const Matrix & other) {
	Matrix a;
	unsigned int res = 0;
	if (other.getRow() == this->getColumn())
	{
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column; j++)
			{

				for (int t = 0; t < j; t++)
				{
					res += (pmas + i * column)[t] * other[t][j];
				}
				a[i][j] = res;
				res = 0;
			}

		}
	}
	return a;
}

Matrix Matrix::operator * (const double & num) {
	Matrix a;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			a [i][j]= (pmas + i * column)[j] * num;
		}
	}
	return a;
}

Matrix Matrix::operator ~ () {
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
	for (size_t row_ = 0; row_ < matr.getRow(); ++row_)
	{
		for (size_t col = 0; col < matr.getColumn(); ++col)
		{
			output << matr[row_][col] << "\t";
		}
		output << "\n";
	}

	return output;
}

std::istream & operator >> (std::istream & input, Matrix & matr)
{
	std::string snum;
	for (size_t row_ = 0; row_ < matr.getRow(); ++row_)
	{
		std::cout << "Please input row number " << row_ << "." << std::endl;
		for (size_t col = 0; col < matr.getColumn(); ++col)
		{
			std::cout << "please input value of x[" << row_ << "][" << col << "] " << ":";
			input >> snum;
			matr[row_][col] = std::atol(snum.c_str());
			std::cout << std::endl;
		}
	}

	return input;
}
double * Matrix::operator[](const int & row) const
{
	return (pmas + row * column);
}

void Matrix::randomMatrix(Matrix &matr)
{
	srand(time(0));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			matr[i][j] = 1 + rand() % 200;
		}
	}
}

void Matrix::simmetricMatrix(Matrix &matr)
{
	srand(time(0));

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i == j)
			{
				matr[i][j] = 1 + rand() % 200;
			}
			else
			{
				matr[i][j] = matr[j][i] = 1 + rand() % 200;
			}
		}
	}
}

void Matrix::hilbertMatrix(Matrix &matr)
{
	for (int i = 1; i <= row; i++)
	{
		for (int j = 1; j <= column; j++)
		{
			matr[i - 1][j - 1] = 1.0 / double(i + j - 1);
		}
	}
}