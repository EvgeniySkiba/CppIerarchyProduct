#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <conio.h>
#include <iomanip>// setw

#define DELIMETER '|'

using namespace std;

class Product
{
protected:
	char * productName;
	double cost;
public:
	///---------------------
	/// ����������� �� ��������� 
	///---------------------
	Product();
	///---------------------
	/// ����������� � ����������� 
	///---------------------
	Product(char * productName_, double cost_);
	///---------------------
	/// ����������� �����������
	///---------------------
	Product(const Product & object);
	~Product();

	// ����������� - ������ ��������� ������ ���� ����������
	virtual void  Print() = 0;

	// inline - ��� �������� � header
	double getCost(){ return cost; }
	char * getName(){ return productName; }

	void setCost(double cost_);
	void setName(char * name_);
};

#endif