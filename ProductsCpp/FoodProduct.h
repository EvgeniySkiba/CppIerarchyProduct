#pragma once

#include "Product.h"
#include "DateTime.h"

///������� �������  (P2)
class FoodProduct :
	public  Product
{
protected :
	// ���� �������� 
	Date shelfLife;
public:
	FoodProduct();
	FoodProduct(char * productName_, double cost_, int day_, int mounth, int year_);
	virtual ~FoodProduct()   ;

	virtual void Print() override;
	void set_shelfLife(int day_, int mounth, int year);
	Date get_shelfLife();

	// ������������� ������������ ���������� � ������� 
	friend istream &operator>>(istream &stream, FoodProduct &o);
};

