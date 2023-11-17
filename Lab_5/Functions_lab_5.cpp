#include "Functions_lab_5.h"

double function_value(double x) {
	return (1 + x + x * x) / pow((x * x * x - 1), 1 / 2);
}

double trapezoid_method() {
	double h = (b - a) / n;
	double integral_trapezoid = ((a + b) * h )/ 2;
	double x = a;
	for (double i = 1; i < n; i++) {
		x += h;
		double integral_part = h * function_value(x);
		double integral_part = h * function_value(x - h / 2);

		//integral_trapezoid +=
	}
	return integral_trapezoid;
}

double Simpsons_method() {
	double h = (b - a) / (2 * n);
	int m = n / 2;
	double integral_Simpsons = ((a + b) * h) / 3;
	double x = a;
	for (int i = 0; i < m; i++) {
		x += 2 * h;
		integral_Simpsons += (h / 3) * 4 * function_value(x);
	}
	x = a;
	for (int i = 0; i < m - 1; i++) {
		x += 2 * h;
		integral_Simpsons += (h / 3) * 2 * function_value(x);
	}
	return integral_Simpsons;
}