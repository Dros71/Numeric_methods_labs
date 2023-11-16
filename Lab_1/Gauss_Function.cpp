#include "Gauss_Function.h"
// -*- coding: utf-8 -*-
void OutputMatrix(double** Matrix, double* B, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << setw(10);
        for (int j = 0; j < n; j++)
        {
            cout << Matrix[i][j] << setw(10);
        }
        cout << B[i];
        cout << endl;
    }
}
void CheckBefore(double** Matrix, double* B, int i, int n)
{
    if (i + 1 < n)
    {
        int index = i;
        for (int k = i + 1; k < n; k++)
        {
            if (abs(Matrix[i][i]) < abs(Matrix[k][i]))
                index = k;
        }
        for (int k = 0; k < n; k++)
        {
            double tmp = Matrix[i][k];
            Matrix[i][k] = Matrix[index][k];
            Matrix[index][k] = tmp;
        }
        double Btmp = B[i];
        B[i] = B[index];
        B[index] = Btmp;
    }
}
void DoTheXnOne(double** Matrix, double* B, int k, int n)
{
    CheckBefore(Matrix, B, k, n);
    double Divider = Matrix[k][k]; //Делитель
    for (int i = 0; i < n; i++)
        Matrix[k][i] /= Divider;
    B[k] /= Divider;
}

void Gauss(double** Matrix, double* B, int n)
{
    for (int i = 0; i < n; i++)
    {
        int rowWithOne = i;
        int ColumnZero = 0;
        if (i != 0)
        {
            for (int tmp = 0; tmp < i; tmp++)
            {
                double zeroThere = Matrix[i][ColumnZero];
                for (int j = 0; j < n; j++)
                    Matrix[i][j] = Matrix[i][j] - Matrix[i - rowWithOne][j] * zeroThere;
                B[i] -= B[i - rowWithOne] * zeroThere;
                ColumnZero++;
                rowWithOne--;
            }
        }
        DoTheXnOne(Matrix, B, i, n);
    }
}

void FindTheAnswer(double** Matrix, double* B, double* Answer, int n)
{
    int i = n - 1;
    Answer[i] = B[i];
    double Buffer;
    for (--i; i >= 0; i--)
    {
        Buffer = B[i];
        for (int j = n - 1; j > i; j--)
        {
            Buffer = Buffer - Answer[j] * Matrix[i][j];
        }
        Answer[i] = Buffer;
    }
}