#include "Functions_lab_2.h"

int main()
{
	setlocale(LC_ALL, "");
	//�������������
	int x1 = 1;
	int x2 = 1;
	bool flag = 0;				//���� ��� ���������� ������� ����� 2-�� ��������
	double M = 0.01;

	//����� ������� ��� ����
	cout << "����� �������, ��� ������� ����� ��������� ������������. " << endl;
	int k = Newton(x1, x2, M, flag);
	cout << "k = " << k << endl << endl;
	flag = 1;
	cout << "����� �������, ��� ������� ����� ��������� �������-���������� �������. " << endl;
	cout << "��� M = " << M << endl;
	k = Newton(x1, x2, M, flag);
	cout << "k = " << k << endl << endl;

	M = 0.05;
	cout << "��� M = " << M << endl;
	k = Newton(x1, x2, M, flag);
	cout << "k = " << k << endl << endl;

	M = 0.1;
	cout << "��� M = " << M << endl;
	k = Newton(x1, x2, M, flag);
	cout << "k = " << k;
}
