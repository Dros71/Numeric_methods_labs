#include "Functions_lab_2.h"

int main()
{
	setlocale(LC_ALL, "");
	//Инициализация
	int x1 = 1;
	int x2 = 1;
	bool flag = 0;				//Флаг для нахождения матрицы Якоби 2-ым способом
	double M = 0.01;

	//Метод Ньютона для СНАУ
	cout << "Метод Ньютона, где матрица Якоби находится аналитически. " << endl;
	int k = Newton(x1, x2, M, flag);
	cout << "k = " << k << endl << endl;
	flag = 1;
	cout << "Метод Ньютона, где матрица Якоби находится конечно-разностным методом. " << endl;
	cout << "При M = " << M << endl;
	k = Newton(x1, x2, M, flag);
	cout << "k = " << k << endl << endl;

	M = 0.05;
	cout << "При M = " << M << endl;
	k = Newton(x1, x2, M, flag);
	cout << "k = " << k << endl << endl;

	M = 0.1;
	cout << "При M = " << M << endl;
	k = Newton(x1, x2, M, flag);
	cout << "k = " << k;
}
