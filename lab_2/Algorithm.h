#pragma once
#include "Matrix.h"
class Algorithm {
public:
	//Algorithm();
	//~Algorithm();
	Matrix Gaus(Matrix &matr);
	Matrix Kachmaj(Matrix&matr, double accuracy);
private:
	Matrix *pMatrix;
	unsigned int leadElement(unsigned int column);
	void swapRows(unsigned int row_1, unsigned row_2);
	void div(unsigned int row);
	void zero(unsigned int column);
	double vectorMul(Matrix &matr1, Matrix&matr2);
	double normalVector(Matrix&matr);
};	