#pragma once
#include "Product.h"

// ������� ����� 
class ElectricalGoods :
	public Product
{
protected:
	//������ �����������  A++/ A+ /B ...
	char *  energyConsumption;
public:
	ElectricalGoods();
	ElectricalGoods(char *  energyConsumption_, char * productName_, double cost_);
	virtual ~ElectricalGoods();

	virtual  void  Print()  override;

	// ������ 
	char * get_energyConsumption();
	// ������
	void set_energyConsumption(char * energyConsumption_);

	// ������������� ������������ ���������� � ������� 
	// �������������� �������� ����� � �������
	friend istream &operator>>(istream &stream, ElectricalGoods &o);
};

