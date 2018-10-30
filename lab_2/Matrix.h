#include<ostream>
#pragma once
class Matrix {
public:
	unsigned int getRow() const;
	unsigned  int getColumn() const;

	Matrix();
	~Matrix();
	void matrixSize(unsigned int row, unsigned int column);
	Matrix & operator = (const Matrix & other);
	bool operator == (const Matrix & other) const;
	Matrix & operator + (const Matrix & other);
	Matrix & operator - (const Matrix & other);
	Matrix & operator * (const Matrix & other);
	Matrix & operator * (const double & num);
	Matrix & operator ~ ();
	friend std::ostream & operator << (std::ostream & output, const Matrix & matr);
	friend std::istream & operator >> (std::istream & input, Matrix & matr);
	double * operator [] (const int & roves) const;
private:
	double *pmas;
	unsigned int row;
	unsigned int column;

};