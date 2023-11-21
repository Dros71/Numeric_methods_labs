#include "Functions_lab_5.h"

int main(){
    cout << "Area trapezoid : " << setprecision(10) << trapezoid_method(eps1) << endl;
    cout << "Area Simpsons : " << Simpsons_method(eps1) << endl;
    cout << "Area trapezoid : " << trapezoid_method(eps2) << endl;
    cout << "Area Simpsons : " << Simpsons_method(eps2) << endl;
}
