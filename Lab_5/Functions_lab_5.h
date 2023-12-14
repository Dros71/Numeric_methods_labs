#pragma once
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double a = 1.00001; // can't be = 1 as in the task
const double b = 2.631;
const double a_2 = 0;	const double b_2 = 4.0;
const double c = 1.0;	const double d = 2.0;
const double eps1 = 1e-4; const double eps2 = 1e-5;
const int n = 2;
const int M = 1, N = 1;		//number of splits (N for Ox, M for Oy)


double function_1_value(double);
double function_2_value(double, double);
double trapezoid_method(double, double&);
double Simpsons_method(double, double&);
double Simpsons_cubaturn();
