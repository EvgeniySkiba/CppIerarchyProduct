#pragma once
#include "Product.h"

// електро товар 
class ElectricalGoods :
	public Product
{
protected:
	//энерго потребление  A++/ A+ /B ...
	char *  energyConsumption;
public:
	ElectricalGoods();
	ElectricalGoods(char *  energyConsumption_, char * productName_, double cost_);
	virtual ~ElectricalGoods();

	virtual  void  Print()  override;

	// геттер 
	char * get_energyConsumption();
	// сеттер
	void set_energyConsumption(char * energyConsumption_);

	// предусмотрено динамическое добавление с консоли 
	// переопределяем оператор ввода с консоли
	friend istream &operator>>(istream &stream, ElectricalGoods &o);
};

