#include "Functions_lab_5.h"

double function_1_value(double x) {
	return (1 + x + x * x) / sqrt(x * x * x - 1);		// x != 0 !!! (in task a = 0)
}
double function_2_value(double x, double y) {	
	return ((x * x) / (1 + y * y));
}
double trapezoid_method(double eps, double& R) {
	double h = (b - a) / n;
	double integral_trapezoid_h = 0;
	double integral_trapezoid_h2 = 0;
	do {
		integral_trapezoid_h = integral_trapezoid_h2;
		h /= 2;
		integral_trapezoid_h2 = ((function_1_value(a) + function_1_value(b)) * h) / 2;
		for (double x = a + h; x < b; x += h)
			integral_trapezoid_h2 += h * function_1_value(x);
	} while (fabs(integral_trapezoid_h2 - integral_trapezoid_h) >= (3 * eps));
	R = (integral_trapezoid_h - integral_trapezoid_h2) * (0,5 * 0,5 - 1);
	return integral_trapezoid_h2;
}

double Simpsons_method(double eps, double& R) {
	double h = (b - a) / n;
	int m = n / 2;
	double integral_Simpsons_h = 0;
	double integral_Simpsons_h2 = 0;
	do {
		integral_Simpsons_h = integral_Simpsons_h2;
		integral_Simpsons_h2 = (function_1_value(a) + function_1_value(b)) * h / 3;
		double x = a + h;
		for (int i = 1; i <= m; i++) {
			integral_Simpsons_h2 += 4 * h / 3 * function_1_value(x);
			x += 2 * h;
		}
		x = a + 2 * h;
		for (int i = 1; i < m; i++) {
			integral_Simpsons_h2 += 2 * h / 3 * function_1_value(x);
			x += 2 * h;
		}
		h /= 2;
		m *= 2;
	} while (fabs(integral_Simpsons_h2 - integral_Simpsons_h) >= (15 * eps));
	R = (integral_Simpsons_h - integral_Simpsons_h2) * (0,5 * 0,5 * 0,5 * 0,5 - 1);
	return integral_Simpsons_h2;
}

double Simpsons_cubaturn() {		// Using the formula to calculate the integral as in the book
	double hx = (b_2 - a_2) / (2 * N);
	double hy = (d - c) / (2 * M);
	double integral_Simpsons_cubaturn = 0;
	for (int i = 0; i <= N - 1; i++)
		for(int j = 0; j <= M - 1; j++)
		integral_Simpsons_cubaturn += function_2_value(a_2 , c) + 4 * function_2_value(a_2 + hx, c) +	//127 
			function_2_value(b_2, c ) + 4 * function_2_value(a_2, c + hy) +
			16 * function_2_value(a_2 + hx, c + hy) + 4 * function_2_value(b_2 , c + hy) +
			function_2_value(a_2 , d) + 4 * function_2_value(a_2 + hx, d) +
			function_2_value(b_2 , d);
	integral_Simpsons_cubaturn *= (hx * hy) / 9;
	return integral_Simpsons_cubaturn;
}