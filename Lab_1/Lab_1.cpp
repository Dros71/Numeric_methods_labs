#include "Functions_lab_1.h"
int main()
{
    //Инициализация
    srand(time(NULL));
    setlocale(LC_ALL, "");
    ifstream OpenFile;
    OpenFile.open("Input.txt");
    int n;
    OpenFile >> n;
    double** Matrix = new double* [n];
    for (int i = 0; i < n; i++)
        Matrix[i] = new double[n];
    double** StartMatrix = new double* [n];
    for (int i = 0; i < n; i++)
        StartMatrix[i] = new double[n];
    double* B = new double[n];
    double* StartB = new double[n];
    Input(OpenFile, Matrix, StartMatrix, B, StartB, n);

    cout << "1) Матрица сначала: " << endl << setprecision(7);
    OutputMatrix(Matrix, B, n);
    //Вниззззз
    Gauss(Matrix, B, n);
    cout << "Матрица после: " << endl;
    OutputMatrix(Matrix, B, n);
    //Вверхххх
    cout << "ОТВЕТ:" << setw(10) << endl;
    double* Answer = new double[n];
    FindTheAnswer(Matrix, B, Answer, n);
    for (int i = 0; i < n; i++)
        cout << "x[" << i + 1 << "] = " << Answer[i] << setw(10) << endl;

    // Часть 2
    double* F = new double[n];
    for (int i = 0; i < n; i++)
    {
        double tmp = 0;
        for (int j = 0; j < n; j++)
        {
            tmp += (Answer[j] * StartMatrix[i][j]);
        }
        F[i] = StartB[i] - tmp;
    }
    cout << "Вектор невязки :" << setw(10) << endl;
    for (int i = 0; i < n; i++)
        cout << "F[" << i + 1 << "] = " << F[i] << setw(10) << endl;

    double norm = F[0];
    for (int i = 1; i < n; i++)
        norm = max(fabs(norm), fabs(F[i]));
    cout << setw(-10) << endl << "2) НОРМА: " << norm << endl;

    //Часть 3
    double* NewB = new double[n];
    for (int i = 0; i < n; i++) {
        double tmp = 0;
        for (int j = 0; j < n; j++)
            tmp += (Answer[j] * StartMatrix[i][j]);
        NewB[i] = tmp;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            Matrix[i][j] = StartMatrix[i][j];

    double* Answer2 = new double[n];
    Gauss(Matrix, NewB, n);
    FindTheAnswer(Matrix, NewB, Answer2, n);

    double deltamax = 0;
    for (int i = 0; i < n; i++)
        if (deltamax < abs(Answer2[i] - Answer[i]) / abs(Answer[i]))
            deltamax = abs(Answer2[i] - Answer[i]) / abs(Answer[i]);
    cout << endl << "3) ОТНОСИТЕЛЬНАЯ ПОГРЕШНОСТЬ: " << deltamax << endl;

    FreeMemory(Matrix, StartMatrix, B, StartB, NewB, Answer, Answer2, F, n);
}