#include <iostream>
#include "Matrix.h"
#include "Algorithm.h"

using namespace std;

int main()
{
	Algorithm alg;

	Matrix M;

	M.matrixSize(3, 4);

	M.randomMatrix(M);

	cout << alg.Kachmaj(M, 0.000001) << endl;

	system("pause");

	return 0;
}