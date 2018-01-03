#include"ElectricalGoods.h"
#include "FoodProduct.h"
#include "Watcher.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_CTYPE, ".1251");

	// ������ ��������� 
	Product * array[7] = 
	{
		new ElectricalGoods("B","������� ������", 356.99),
		new ElectricalGoods("A+", "����", 756.99),
		new ElectricalGoods("B+", "���������������", 2356.99),

		new Watcher(1000, "B+", "zanussi zwse 7", 12896.99),
		new Watcher(1400,"A+++", "Samsung Wf 60 F1R1 G0WD", 18936.99),

		new FoodProduct("������", 56.99,12,1,2018),
		new FoodProduct("������� ", 856.99, 12, 10, 2018)
	};


	cout << "������ ���������(����������� �������) ....";
	for (int i = 0; i < 6; ++i)
		array[i]->Print();

	// ��� ������������� ����������� ������� 
	// ���������� ���������� ��� ����������� ���� � ������� ������� ���� ��������������

	cout << "��� ���� ����� ����������� �������" << endl;
	// ���������� ������ �� ���������� ������, ������������ ������ ����� �� ���������� 	
	cout << "���������� ������" << endl;
	array[3]->Print();


	// ���������� ������ ��� �� �������� 
	Product *  p = array[3]; // ���������� � �������� ����
	cout << "���������� ������ ��� ������� " << endl;
	// ��� ������� ����� ��������� ������� ����������� ������� 
	// �� ���� ������� ����� �� ���� �������� � �������� ������ 
	// ����� ������ ����� ������� ������ � ���������� 
	p->Print();

	// �������� ����������� ���������� ������
	for (int i = 0; i < 6; ++i)
		delete array[i];

	cout << "������� ����� ������ ��� ����������� ....";
	_getch();

	return 0;
}

