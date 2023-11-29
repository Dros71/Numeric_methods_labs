#pragma once
#include "Gauss_Function.h"
using namespace std;
const int n = 5;
const int m = n;
const double H[] = {0.164, 0.328, 0.656, 0.984 , 1.312, 1.640};
const double Eta[] = {0.448, 0.432, 0.421, 0.417, 0.414, 0.412};

double* Sum_X(double*);
double* Least_square_method();