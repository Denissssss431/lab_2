#pragma once
#include "Matrix.h"
class Algorithm {
public:
	Algorithm()=default;
	~Algorithm();
	Algorithm(Matrix &m);
	Matrix Gaus();
	Matrix Kachmaj(Matrix&matr, double accuracy);
private:
	Matrix *pMatrix;
	unsigned int leadElement(unsigned int column);
	void swapRows(unsigned int row_1, unsigned row_2);
	bool emptyLine(unsigned int row);
	void div(unsigned int row);
	void zero(const unsigned int & leadRow);///!!!
	Matrix reverce_zero();
	double vectorMul(Matrix &matr1, Matrix&matr2);
	double normalVector(Matrix&matr);
};	