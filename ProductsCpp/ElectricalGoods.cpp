#include "ElectricalGoods.h"


ElectricalGoods::ElectricalGoods()
{
	energyConsumption = new char[1];
	energyConsumption[0] = '\0';
}

ElectricalGoods::ElectricalGoods(char *  energyConsumption_, char * productName_, double cost_) :Product(productName_, cost_)
{
	int len = 0;

	len = strlen(energyConsumption_);
	energyConsumption = new char[len + 1];
	strcpy(energyConsumption, energyConsumption_);
	energyConsumption[len] = '\0';
}

ElectricalGoods::~ElectricalGoods()
{
	if (energyConsumption)
	{
		delete[]energyConsumption;
	}
}

char * ElectricalGoods::get_energyConsumption(){
	return this->energyConsumption;
}

void ElectricalGoods::set_energyConsumption(char * energyConsumption_)
{
	int len = strlen(energyConsumption_);
	energyConsumption = new char[len + 1];
	strcpy(energyConsumption, energyConsumption_);
	energyConsumption[len] = '\0';
}

void  ElectricalGoods::Print()
{
	Product::Print();
	cout << setw(18) << " ����� ����������������  : " << this->energyConsumption << endl;
}



istream &operator>>(istream &stream, ElectricalGoods &o)
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

	cin.clear();
	//������� ����� �� ��������� � ��� ��������
	cin.sync();
	cout << "������� ����� ������ ����������  :" << endl;
	// ���������� ����� - �� ������� ������ ������������ ���������� ���������� 
	char * energyConsumption = new char[1000];
	// ������������ ���������� ��������
	cin >> setw(1000) >> energyConsumption;
	o.set_energyConsumption(energyConsumption);

	cin.clear();
	//������� ����� �� ��������� � ��� ��������
	cin.sync();
	cout << "������� ��������� " << endl;
	cin>>o.cost;

	// �������� ��������� ������ 
	delete[] productName;
	delete[] energyConsumption;

	return stream;
}