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
	// здесь только поле int 
	cout << "ƒеструктор" << " Watcher" << endl;
}

void Watcher::Print() 
{
	ElectricalGoods::Print();
	cout << setw(18) << "ќбороты в минуту  : " << this->numRevolutionsPerMin << endl;
	cout.setf(ios::left);
	cout << "**************"<<endl;
}

istream &operator>>(istream &stream, Watcher &o)
{
	cout << "¬ведите название :" << endl;
	cin.clear();
	//очищает поток от имеющихс€ в нем символов
	cin.sync();

	// магическое число - по заданию нельз€ использовать голбальные переменные 
	char * productName = new char[1000];
	// максимальное количество символов
	cin >> setw(1000) >> productName;
	o.setName(productName);

	cout << "¬ведите класс енерго збережени€  :" << endl;
	cin.clear();
	//очищает поток от имеющихс€ в нем символов
	cin.sync();

	// магическое число - по заданию нельз€ использовать голбальные переменные 
	char * energyConsumption = new char[1000];
	// максимальное количество символов
	cin >> setw(1000) >> energyConsumption;
	o.set_energyConsumption(energyConsumption);


	cout << "¬ведите количество боротов, в мин :" << endl;
	cin>>o.numRevolutionsPerMin;

	cout << "¬ведите стоимость " << endl;
	cin>>o.cost;

	// очистить временную пам€ть 
	delete[] productName;
	delete[] energyConsumption;

	return stream;
}

