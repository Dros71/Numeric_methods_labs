#include "Functions_lab_5.h"
/*
    SITES TO CHECK
    https://math.semestr.ru/optim/trapezoid-formula.php - trapezoid + Simpson's
    https://mathforyou.net/online/calculus/integral/definite/double/ - Simpson's cubaturn
*/

int main(){
    double R = 0;
    cout << "Area trapezoid with eps = " << eps1 << ", = " << setprecision(10) << trapezoid_method(eps1, R) << " R = "<< R << endl;
    cout << "Area Simpsons with eps = " << eps1 << ", = " << Simpsons_method(eps1, R) << " R = " << R << endl;
    cout << "Area trapezoid with eps = "<< eps2 << ", = " << trapezoid_method(eps2, R) << " R = " << R << endl;
    cout << "Area Simpsons with eps = " << eps2 << ", = " << Simpsons_method(eps2, R) << " R = " << R << endl;
    cout << "Area Simpsons cubaturn : " << Simpsons_cubaturn() << endl;
    
}
