#include <iostream>
#include "Algorithm.h"
#include"Matrix.h"
 unsigned int Algorithm::leadElement(unsigned int column) {
	 for (unsigned int i = column; i < pMatrix->getRow(); i++) {
		 if ((*pMatrix)[i][column] != 0);
			 return i;
	 }
	 throw std::logic_error("");
}


 void Algorithm::swapRows(unsigned int row_1, unsigned row_2) {
	 double temp=0;
	 for (unsigned int i = 0; i < pMatrix->getColumn(); i++) {
		 temp = (*pMatrix)[row_1][i];
		 (*pMatrix)[row_1][i] = (*pMatrix)[row_2][i];
		 (*pMatrix)[row_2][i] = temp;
	 }
 }

 bool Algorithm::emptyLine(unsigned int row)
 {
	 for (int col = 0; col < pMatrix->getColumn(); ++col)
	 {
		 if ((*pMatrix)[row][col] != 0)
		 {
			 if (col == pMatrix->getColumn())
				 break;

			 return false;
			 break;
		 }
	 }
	 return true;
 }

 
 void Algorithm::div(unsigned int row) {
	 double one = (*pMatrix)[row][row];
	 for (unsigned int i = row; i <pMatrix->getColumn(); i++) {
		 ((*pMatrix)[row][i]) /= one;
     }
 }
 
 void Algorithm::zero(const unsigned int & leadRow) {
	 if (leadRow >= pMatrix->getRow() - 1)	return;

	 unsigned int j = leadRow;
	 double temp = 0;
	 for (int i = leadRow + 1; i < pMatrix->getRow(); i++)
	 {
		 j = leadRow;
		 temp = (*pMatrix)[i][j];
		 for (; j < pMatrix->getColumn(); j++)
		 {
			 (*pMatrix)[i][j] -= (*pMatrix)[leadRow][j] * temp;
		 }
	 }
 }

 Matrix Algorithm::reverce_zero()
 {
	 Matrix res(1, pMatrix->getColumn() - 1);
	 int lead_row = pMatrix->getRow() - 1;
	 double Ai_lead, temp;
	 for (int j = pMatrix->getColumn() - 2; j >= 0; j--, lead_row--)
	 {
		 Ai_lead = (*pMatrix)[lead_row][pMatrix->getColumn() - 1];
		 (res)[0][pMatrix->getColumn() - 2 - j] = (Ai_lead);
		 for (int i = lead_row; i > 0; --i)
		 {
			 temp = (*pMatrix)[i - 1][j];
			 (*pMatrix)[i - 1][pMatrix->getColumn() - 1] -= Ai_lead * temp;
			 (*pMatrix)[i - 1][j] -= (*pMatrix)[lead_row][j] * temp;
		 }
	 }

	 return res;
 }
 
 Algorithm::~Algorithm()
 {
	 delete pMatrix;
 }

 Algorithm::Algorithm(Matrix & m)
 {
	 pMatrix = new Matrix(m);
 }

 Matrix Algorithm::Gaus()
 {
	 //pMatrix = new Matrix;
	 //*pMatrix = matr;

	 //std::cout << *pMatrix;

	 unsigned int k = 0;
	 unsigned int next_line = k;

	 unsigned int rowOfelement;

	 for (; k < pMatrix->getRow(); k++, next_line++)
	 {
		 if (!emptyLine(k))
		 {
			 rowOfelement = leadElement(k);
			 swapRows(rowOfelement, next_line);
			 //std::cout << *pMatrix;
			 div(next_line);
			 //std::cout << *pMatrix;
			 zero(next_line);
			 //std::cout << *pMatrix;
		 }
	 }

	 return reverce_zero();
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
