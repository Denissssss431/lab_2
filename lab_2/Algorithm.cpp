#include <iostream>
#include "Algorithm.h"
 unsigned int Algorithm::leadElement(unsigned int column) {
	 for (unsigned int i = column; i < pMatrix->getRow(); i++) {
		 if ((*pMatrix)[i][column] != 0)
			 return i;
	 }
	 throw std::logic_error("");
}


 void Algorithm::swapRows(unsigned int row_1, unsigned row_2) {
	 double temp;
	 for (unsigned int i = 0; i < pMatrix->getColumn(); i++) {
		 temp = (*pMatrix)[row_1][i];
		 (*pMatrix)[row_1][i] == (*pMatrix)[row_2][i];
		 (*pMatrix)[row_2][i] = temp;
	 }
 }
 
 void Algorithm::div(unsigned int row) {
	 double one = (*pMatrix)[row][row];
	 for (unsigned int i = row; i <pMatrix->getColumn(); i++) {
		 ((*pMatrix)[row][row]) / one;
     }
 }
 
 void Algorithm::zero(unsigned int column) {
	 for (int i = 0; i < pMatrix->getColumn() - 2; i++)
	 {
		 for (int j = i; j < pMatrix->getRow(); j++)
		 {
			 double temp = (*pMatrix[i + 1][j]);
			 for (int k = j; k < pMatrix->getColumn(); k++)
			 {
				 (*pMatrix)[i + 1][k] = (*pMatrix)[i][k] * temp - (*pMatrix)[i + 1][k];
			 }
		 }
	 }
 }
 
 Matrix Algorithm::Gaus(Matrix &matr) {
	 return matr;
 }

 Matrix Algorithm::Kachmaj(Matrix&matr, double accuracy) {
	 Matrix vector1;
	 vector1.matrixSize(1, matr.getColumn()-1);
	 Matrix vector2;
	 vector2.matrixSize(1, matr.getColumn() - 1);
	 Matrix vector3;
	 vector3.matrixSize(1, matr.getColumn() - 1);
	 double k;
	 int Iterator = 0;
	 for (int i = 0; i < matr.getColumn() - 1; i++) {
		 vector1[0][i] = matr[0][i];
	 }
	 for (int i = 0; i < matr.getColumn() - 1; i++) {

		 vector3[0][i] = 1;
	 }
	 while (normalVector(vector3) > accuracy)
	 {
		 Matrix temp;
		 temp.matrixSize(1, matr.getColumn() - 1);
		 for (int i = 0; i < matr.getColumn() - 1; i++) {
			 temp[0][i] = matr[Iterator][i];
		 }
		 k = (matr[Iterator][matr.getColumn() - 1] - vectorMul(temp, vector1)) / (normalVector(temp)*normalVector(temp));
		 temp = temp * k;
		 vector2 = vector1 + temp;
		 vector3 = vector2 - vector1;
		 vector1 = vector2;
		 if (Iterator < vector1.getColumn() - 1)
		 {
			 Iterator++;
		 }
		 else
			 Iterator = 0;
	 }
	 return vector1;

 }

 double Algorithm::vectorMul(Matrix&matr1, Matrix&matr2) {
	 double temp = 0;
	 for(int i=0; i<matr1.getColumn()-1; i++){
		 temp += matr1[0][i] * matr2[0][i];
	 }
	 return temp;

 }

 double Algorithm::normalVector(Matrix&matr) {
	 double temp=0;
	 for(int i=0; i<matr.getColumn()-1; i++){
		 temp += matr[0][i]* matr[0][i];
	 }
	 return sqrt(temp);
 }
