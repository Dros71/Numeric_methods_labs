#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double a = 1.001;
const double b = 2.631;
const double eps1 = 1e-4; const double eps2 = 1e-5;
const int n = 2;


double function_value(double);
double trapezoid_method();
double Simpsons_method();
//double Simpsons_cubaturn();
