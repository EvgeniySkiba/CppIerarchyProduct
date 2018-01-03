#pragma once
#include "ElectricalGoods.h"

// p11
class Watcher :
	public ElectricalGoods
{
protected :
	// число оборотов в минуту 
	int numRevolutionsPerMin;
public:
	Watcher();
	Watcher(int numRevolutionsPerMin, char *  energyConsumption_, char * productName_, double cost_);
	virtual ~Watcher();

	virtual void Print() override;

	int get_numRevolutionsPerMin(){ return numRevolutionsPerMin; }
	void set_numRevolutionsPerMin(int numRevolutionsPerMin_){ numRevolutionsPerMin = numRevolutionsPerMin_; }

	// предусмотрено динамическое добавление с консоли 
	friend istream &operator>>(istream &stream, Watcher &o);
};

