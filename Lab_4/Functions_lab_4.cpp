#include "Functions_lab_4.h"

double* Sum_X(double* result) {
	for (int k = 0; k < 2 * m; k++) {
		result[k] = 0;
		for (int i = 0; i < n; i++)
			result[k] += pow(H[i], k);
	}
	return result;
}

double* Least_square_method() {
	double* X = new double[2 * m];
	X = Sum_X(X);
	int l = m + 1;
	double** Matrix = new double*[m + 1];
	for (int i = 0; i < m + 1; i++)
		Matrix[i] = new double[m + 1];
	for (int l = 0; l <= m; l++) {
		for (int j = 0; j <= m; j++) {
			int k = l + j;
			Matrix[l][j] = X[k];
		}
	}
	double* B = new double[m + 1];
	for (int l = 0; l < m; l++) {
		B[l] = 0;
		for (int i = 0; i < n; i++) {
			B[l] += Eta[i] * pow(H[i], l);
		}
	}
	double* Ans = new double[m];
	Gauss(Matrix, B, m);                                  // Прямой ход по Гасусу. Резульат в Jacobi и F
	FindTheAnswer(Matrix, B, Ans, m);
	OutputMatrix(Matrix, B, m);
	return Ans;
}

