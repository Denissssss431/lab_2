#pragma once
#include "Matrix.h"
class Algorithm {
public:
	Algorithm();
	~Algorithm();
	Matrix Hauss();
private:
	Matrix *pMatrix;
	unsigned int leadElement(unsigned int column);
	void swapRows(unsigned int row_1, unsigned row_2);
	void div(unsigned int row);
	void zero(unsigned int column);
};	