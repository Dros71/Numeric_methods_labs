#pragma once
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

const double u1_0 = 0;
const double u2_0 = 1;
const double a = 2;
const double k = 0.25;
const double eps = 1e-3;
const double T = 1;

double der_u1(double, double);
double der_u2(double, double);

void Explicit_Euler_method();
double Find_t(double, double);