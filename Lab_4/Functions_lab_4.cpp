#include "Functions_lab_4.h"

double* sum_X(double* result) {
	for (int k = 0; k <= (2 * m); k++) {
		result[k] = 0;
		for (int i = 0; i < n; i++)
			result[k] += 1 / pow(x[i], k);
	}
	return result;
}

void least_square_method(double* A) {
	double* X = new double[2 * m + 1];
	X = sum_X(X);
	int l = m + 1;
	double** Matrix = new double*[m + 1];
	for (int i = 0; i < (m + 1); i++)
		Matrix[i] = new double[m + 1];
	for (int l = 0; l <= m; l++) {
		for (int j = 0; j <= m; j++) {
			int k = l + j;
			Matrix[l][j] = X[k];
		}
	}
	double* B = new double[m + 1];
	for (int l = 0; l <= m; l++) {
		B[l] = 0;
		for (int i = 0; i < n; i++)
			B[l] += y[i] * pow(1/x[i], l);
	}

	Gauss(Matrix, B, m + 1);                            
	FindTheAnswer(Matrix, B, A, m + 1);
	garbage_Collector(Matrix, B, X);
}

double Count_eps(double* A) {
	double S = 0;
	for (int i = 0; i < n; i++) {
		double tmp = y[i];
		for (int j = 0; j <= m; j++) {
			tmp -= A[j] * pow(1 / x[i], j);
		}
		S += tmp * tmp;
	}
	S /= n - m - 1;
	return (sqrt(S));
}

void garbage_Collector(double** Matrix, double* B, double* X) {
	for (int i = 0; i < m + 1; i++)
		delete[] Matrix[i];
	delete[] Matrix;
	delete[] B;
	delete[] X;
}

