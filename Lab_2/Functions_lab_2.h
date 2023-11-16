#include "Gauss_Function.h"
#include <clocale>
#include <cmath>
using namespace std;
const double eps = 1e-10;
const int NIT = 100;
const int n = 2;

double func_1(double, double);
double func_2(double, double);
double* residual_vector(double, double);
double** jacobi(double, double);
double** jacobiStrange(double, double, double);

int Newton(double, double, double, bool);
void garbageCollector(double**, double*, double*, const int);