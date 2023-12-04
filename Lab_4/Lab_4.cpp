#include "Functions_lab_4.h"

int main()
{
    for (int i = 0; i < n; i++) 
        cout << " x = " << x[i] << ". y = " << y[i] << endl;
    cout << endl;
    double* A = new double[m + 1];
    least_square_method(A);
    cout << "a = " << A[1] << endl;
    cout << "b = " << A[0] << endl;
    for (int i = 0; i < n; i++)
        cout << "Expectation: " << (A[1] / x[i]) + A[0] << " Reality: " << y[i] << endl;
    double eps = Count_eps(A);
    cout << "eps = " << eps << endl;
    cout << "Answer: " << "y = " << A[1] << "/x + " << A[0];
}


