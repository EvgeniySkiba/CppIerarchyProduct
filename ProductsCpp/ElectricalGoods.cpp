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
	cout << setw(18) << " Класс энергосбережения  : " << this->energyConsumption << endl;
}



istream &operator>>(istream &stream, ElectricalGoods &o)
{		
	cout << "Введите название :" << endl;
	cin.clear();
	//очищает поток от имеющихся в нем символов
	cin.sync();
	// магическое число - по заданию нельзя использовать голбальные переменные 
	char * productName = new char[1000];
	// максимальное количество символов
	cin >> setw(1000) >> productName;
	o.setName(productName);	

	cin.clear();
	//очищает поток от имеющихся в нем символов
	cin.sync();
	cout << "Введите класс енерго збережения  :" << endl;
	// магическое число - по заданию нельзя использовать голбальные переменные 
	char * energyConsumption = new char[1000];
	// максимальное количество символов
	cin >> setw(1000) >> energyConsumption;
	o.set_energyConsumption(energyConsumption);

	cin.clear();
	//очищает поток от имеющихся в нем символов
	cin.sync();
	cout << "Введите стоимость " << endl;
	cin>>o.cost;

	// очистить временную память 
	delete[] productName;
	delete[] energyConsumption;

	return stream;
}