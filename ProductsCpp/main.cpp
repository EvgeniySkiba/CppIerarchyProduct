#include"ElectricalGoods.h"
#include "FoodProduct.h"
#include "Watcher.h"
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	setlocale(LC_CTYPE, ".1251");

	// массив продуктов 
	Product * array[7] = 
	{
		new ElectricalGoods("B","Электро Чайник", 356.99),
		new ElectricalGoods("A+", "Утюг", 756.99),
		new ElectricalGoods("B+", "Водонагреватель", 2356.99),

		new Watcher(1000, "B+", "zanussi zwse 7", 12896.99),
		new Watcher(1400,"A+++", "Samsung Wf 60 F1R1 G0WD", 18936.99),

		new FoodProduct("Молоко", 56.99,12,1,2018),
		new FoodProduct("Колбаса ", 856.99, 12, 10, 2018)
	};


	cout << "Список продуктов(виртуальная функция) ....";
	for (int i = 0; i < 6; ++i)
		array[i]->Print();

	// при использовании виртуальных функций 
	// вызывается реализации для конкретного типа в котором функция была переопределена

	cout << "Для чего нужны виртуальные функции" << endl;
	// отобразить данные по стиральной машине, испольщуется прямой вызов из экземпляра 	
	cout << "Стиральная машина" << endl;
	array[3]->Print();


	// отобразить данные как по продукту 
	Product *  p = array[3]; // приведение к базовому типу
	cout << "Стиральная машина как продукт " << endl;
	// при запуске будет построена таблица виртуальных функций 
	// по этой причине когда мы даже приведем к базовому классу 
	// будет вызван метод который описан в наследнике 
	p->Print();

	// очистить динамически выделенную память
	for (int i = 0; i < 6; ++i)
		delete array[i];

	cout << "Введите любой символ для продолжения ....";
	_getch();

	return 0;
}

