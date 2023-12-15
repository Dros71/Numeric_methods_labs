#include "Functions_lab_3.h"


double der_u1(double u1, double u2) {
	return (u2 - (a * u1 + k * u2) * u1);
}
double der_u2(double u1, double u2) {
	return (exp(u1) - (u1 + a * u2) * u1);
}
double Find_t(double d_u1, double d_u2) {
	return (d_u1 > d_u2 ? d_u2 : d_u1);
}

void Explicit_Euler_method() {
	int i = 0;
	double h = 0.0;
	double u01 = u1_0;
	double u02 = u2_0;
	double t = 0;
	while (t <= T)
	{
		i++;
		double der_u1_count = der_u1(u01, u02);
		double der_u2_count = der_u2(u01, u02);
		double tk_1 = eps / (fabs(der_u1_count) + eps / T);
		double tk_2 = eps / (fabs(der_u2_count) + eps / T);
		h = Find_t(tk_1, tk_2);

		u01 = u01 + h * der_u1_count;
		u02 = u02 + h * der_u2_count;


		cout << "t = " << t << setw(10) <<
				" u1: " << u01 << setw(10) << 
				" u2: " << u02 << setw(10) << 
				" i: " << i << endl;
		t += h;
	}
}