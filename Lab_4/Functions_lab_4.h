#pragma once
#include "Gauss_Function.h"
using namespace std;
const int n = 6;
const int m = 1;
const double x[] = {0.164, 0.328, 0.656, 0.984 , 1.312, 1.640};
const double y[] = {0.448, 0.432, 0.421, 0.417, 0.414, 0.412};

double* sum_X(double*);
void least_square_method(double*);
double Count_eps(double* A);
void garbage_Collector(double**, double*, double*);