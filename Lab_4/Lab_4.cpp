#include "Functions_lab_4.h"

int main()
{
    for (int i = 0; i < n; i++) {
        cout << " h =" << H[i] << ". eta = " << Eta[i] << endl;
    }
    double* A = new double[n];
    A = Least_square_method();
    for (int i = 0; i < n; i++)
        cout << "a[" << i << "] = " << A[i] << endl;
}


