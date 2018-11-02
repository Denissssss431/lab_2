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
	 for (unsigned int i = column; i < pMatrix->getRow; i++) {

	 }

 }