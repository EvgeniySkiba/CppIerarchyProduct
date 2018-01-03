#pragma once

#include "Product.h"
#include "DateTime.h"

///Продукт питания  (P2)
class FoodProduct :
	public  Product
{
protected :
	// срок годности 
	Date shelfLife;
public:
	FoodProduct();
	FoodProduct(char * productName_, double cost_, int day_, int mounth, int year_);
	virtual ~FoodProduct()   ;

	virtual void Print() override;
	void set_shelfLife(int day_, int mounth, int year);
	Date get_shelfLife();

	// предусмотрено динамическое добавление с консоли 
	friend istream &operator>>(istream &stream, FoodProduct &o);
};

