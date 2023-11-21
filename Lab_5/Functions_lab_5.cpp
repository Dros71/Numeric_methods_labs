#include "Functions_lab_5.h"

double function_value(double x) {
	return (1 + x + x * x) / sqrt(x * x * x - 1);		// x != 0 !!!
}

double trapezoid_method(double eps) {
	double h = (b - a) / n;
	double integral_trapezoid_h = 0;
	double integral_trapezoid_h2 = 0;
	do {
		integral_trapezoid_h = integral_trapezoid_h2;
		h /= 2;
		integral_trapezoid_h2 = ((function_value(a) + function_value(b)) * h) / 2;
		for (double x = a + h; x < b; x += h)
			integral_trapezoid_h2 += h * function_value(x);
	} while (fabs(integral_trapezoid_h2 - integral_trapezoid_h) >= (3 * eps));
	return integral_trapezoid_h2;
}

double Simpsons_method(double eps) {
	double h = (b - a) / n;
	int m = n / 2;
	double integral_Simpsons_h = 0;
	double integral_Simpsons_h2 = 0;
	do {
		integral_Simpsons_h = integral_Simpsons_h2;
		integral_Simpsons_h2 = (function_value(a) + function_value(b)) * h / 3;
		double x = a + h;
		for (int i = 1; i <= m; i++) {
			integral_Simpsons_h2 += 4 * h / 3 * function_value(x);
			x += 2 * h;
		}
		x = a + 2 * h;
		for (int i = 1; i < m; i++) {
			integral_Simpsons_h2 += 2 * h / 3 * function_value(x);
			x += 2 * h;
		}
		h /= 2;
		m *= 2;
	} while (fabs(integral_Simpsons_h2 - integral_Simpsons_h) >= (15 * eps));
	return integral_Simpsons_h2;
}