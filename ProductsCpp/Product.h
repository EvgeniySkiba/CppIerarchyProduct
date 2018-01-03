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
	/// конструктор по умолчанию 
	///---------------------
	Product();
	///---------------------
	/// конструктор с параметрами 
	///---------------------
	Product(char * productName_, double cost_);
	///---------------------
	/// конструктор копирования
	///---------------------
	Product(const Product & object);
	~Product();

	// виртуальный - каждый наследник вносит свою реализацию
	virtual void  Print() = 0;

	// inline - для быстроты в header
	double getCost(){ return cost; }
	char * getName(){ return productName; }

	void setCost(double cost_);
	void setName(char * name_);
};

#endif