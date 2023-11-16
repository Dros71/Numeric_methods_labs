#include "Functions_lab_2.h"
// -*- coding: utf-8 -*-
double func_1(double x1, double x2) {
    return (1.5 * pow(x1, 3) - x2 * x2 - 1);
}

double func_2(double x1, double x2) {
    return (x1 * pow(x2, 3) - x2 - 4);
}

double* residual_vector(double x1, double x2) {                //Вектор невязки
    double* vect = new double[2];
    vect[0] = -func_1(x1, x2);
    vect[1] = -func_2(x1, x2);
    return vect;
}
double** jacobi(double x1, double x2) {
    double** jacobi = new double* [2];
    for (int i = 0; i < 2; i++)
        jacobi[i] = new double[2];
    jacobi[0][0] = 4.5 * x1 * x1;
    jacobi[0][1] = -2 * x2;
    jacobi[1][0] = x2 * x2 * x2;
    jacobi[1][1] = 3 * x1 * x2 * x2 - 1;
    return jacobi;
}
double** jacobiStrange(double x1, double x2, double M) {
    double** jacobi = new double* [2];
    for (int i = 0; i < 2; i++)
        jacobi[i] = new double[2];
    jacobi[0][0] = (func_1(x1 + x1 * M, x2) - func_1(x1, x2)) / (x1 * M);
    jacobi[0][1] = (func_1(x1, x2 + x2 * M) - func_1(x1, x2)) / (x2 * M);
    jacobi[1][0] = (func_2(x1 + x1 * M, x2) - func_2(x1, x2)) / (x1 * M);
    jacobi[1][1] = (func_2(x1, x2 + x2 * M) - func_2(x1, x2)) / (x2 * M);
    return jacobi;
}

int Newton(double x1, double x2, double M, bool flag) {
    bool print = 1;
    cout << "Нажмите 0, если нужно получить только k, и 1, чтобы показать вычисления ";
    cin >> print;                                   // Проверка на ввод..?

    double** Jacobi = new double* [n];
    for (int i = 0; i < n; i++) {
        Jacobi[i] = new double[n];
    }
    double* F = new double[n];
    double* Ans = new double[n];
    double X[n]{ x1, x2 };
    double delta_1 = 0;
    double delta_2 = 0;
    int k = 0;
    do {
        if (k > NIT) {
            cout << "k > NIT :(";
            break;
        }
        delta_2 = delta_1 = 0;
        if (print)
            cout << setw(10) << "Шаг " << k << endl << setw(-10) << "x1(" << k << ") = " << X[0] << endl << "x2(" << k << ") = " << X[1] << endl;
        if (flag)
            Jacobi = jacobiStrange(X[0], X[1], M);
        else Jacobi = jacobi(X[0], X[1]);               // Матрица Якоби. Способ 1
        F = residual_vector(X[0], X[1]);                // Вектор невязки F
        Gauss(Jacobi, F, n);                                  // Прямой ход по Гасусу. Резульат в Jacobi и F
        FindTheAnswer(Jacobi, F, Ans, n);                     // Обратный ход по Гаусу. Нашли (delta)x(k) и занесли результат в Ans

        X[0] += Ans[0];                                       // x(k+1) = x(k) + (delta)x(k)
        X[1] += Ans[1];

        delta_1 = max(fabs(func_2(X[0] - Ans[0], X[1] - Ans[1])), fabs(func_1(X[0] - Ans[0], X[1] - Ans[1])));
        for (int i = 0; i < n; i++) {
            if (fabs(X[i]) < 1)
                delta_2 = max(delta_2, fabs(X[i] - (X[i] - Ans[i])));
            else
                delta_2 = max(delta_2, fabs((X[i] - (X[i] - Ans[i])) / X[i]));
        }
        if (print) {
            cout << "delta(1) = " << delta_1 << endl;
            cout << "delta(2) = " << delta_2 << endl << endl;
        }
        k++;
    } while (delta_1 >= eps && delta_2 >= eps);
    if (print) {
        cout << "ОТВЕТ:" << endl;
        cout << "x1 = " << setprecision(20) << X[0] << endl;
        cout << "x2 = " << X[1] << setprecision(-20) << endl;
    }
    garbageCollector(Jacobi, F, Ans, n);
    return k;
}


void garbageCollector(double** Matrix, double* F, double* Ans, const int n) {
    for (int i = 0; i < n; i++)
        delete[] Matrix[i];
    delete[] Matrix;
    delete[] F;
    delete[] Ans;
}