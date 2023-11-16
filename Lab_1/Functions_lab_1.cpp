#include "Functions_lab_1.h"

void Input(ifstream& OpenFile, double** Matrix, double** StartMatrix, double* B, double* StartB, int n)
{

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            OpenFile >> Matrix[i][j];
    for (int i = 0; i < n; i++)
        OpenFile >> B[i];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            StartMatrix[i][j] = Matrix[i][j];
    for (int i = 0; i < n; i++)
        StartB[i] = B[i];

    OpenFile.close();

}

void FreeMemory(double** Matrix, double** StartMatrix, double* B, double* StartB, double* NewB, double* Answer, double* Answer2, double* F, int n)
{
    delete[] B;
    delete[] StartB;
    delete[] NewB;
    delete[] Answer;
    delete[] Answer2;
    delete[] F;
    for (int i = 0; i < n; i++)
        delete[] StartMatrix[i];
    delete[] StartMatrix;
    for (int i = 0; i < n; i++)
        delete[] Matrix[i];
    delete[] Matrix;
}