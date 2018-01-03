#include "Watcher.h"

Watcher::Watcher()
{
	numRevolutionsPerMin = 0;
}

Watcher::Watcher(int numRevolutionsPerMin_, char *  energyConsumption_, char * productName_, double cost_) : ElectricalGoods(energyConsumption_,  productName_, cost_)
{
	numRevolutionsPerMin = numRevolutionsPerMin_;
}

Watcher::~Watcher()
{
	// ����� ������ ���� int 
	cout << "����������" << " Watcher" << endl;
}

void Watcher::Print() 
{
	ElectricalGoods::Print();
	cout << setw(18) << "������� � ������  : " << this->numRevolutionsPerMin << endl;
	cout.setf(ios::left);
	cout << "**************"<<endl;
}

istream &operator>>(istream &stream, Watcher &o)
{
	cout << "������� �������� :" << endl;
	cin.clear();
	//������� ����� �� ��������� � ��� ��������
	cin.sync();

	// ���������� ����� - �� ������� ������ ������������ ���������� ���������� 
	char * productName = new char[1000];
	// ������������ ���������� ��������
	cin >> setw(1000) >> productName;
	o.setName(productName);

	cout << "������� ����� ������ ����������  :" << endl;
	cin.clear();
	//������� ����� �� ��������� � ��� ��������
	cin.sync();

	// ���������� ����� - �� ������� ������ ������������ ���������� ���������� 
	char * energyConsumption = new char[1000];
	// ������������ ���������� ��������
	cin >> setw(1000) >> energyConsumption;
	o.set_energyConsumption(energyConsumption);


	cout << "������� ���������� �������, � ��� :" << endl;
	cin>>o.numRevolutionsPerMin;

	cout << "������� ��������� " << endl;
	cin>>o.cost;

	// �������� ��������� ������ 
	delete[] productName;
	delete[] energyConsumption;

	return stream;
}

