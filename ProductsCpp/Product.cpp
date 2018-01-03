#include "Product.h"

Product::Product()
{
	productName = new char[1];
	productName[0] = '\0';

	cost = 0;
}

Product::Product(char * productName_, double cost_)
{
	int len = 0;
	len = strlen(productName_);
	productName = new char[len + 1];
	strcpy(productName, productName_);
	productName[len] = '\0';

	cost = cost_;
}

///---------------------
/// конструктор копирования
///---------------------
Product::Product(const Product & object)
{
	int len = strlen(object.productName);

	///_name = new char[len+1];
	strcpy(productName, object.productName);
	productName[len] = '\0';

	cost = object.cost;
}

void Product::setName(char * name_)
{
	int len = 0;
	len = strlen(name_);
	productName = new char[len + 1];
	strcpy(productName, name_);
	productName[len] = '\0';
}

void Product::setCost(double cost_)
{
	cost = cost_;
}

Product::~Product(void)
{
	if (productName)
	{
		delete[] productName;	
	}
}

void  Product::Print()
{
	cout << "\n";
	cout.setf(ios::left);

	cout << setw(18) << " Наименование : " << this->productName << endl;
	cout.setf(ios::left);
	cout << setw(18) << " Стоимость: " << this->cost << endl;
	cout.setf(ios::left);
}
	
