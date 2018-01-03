#include "FoodProduct.h"


FoodProduct::FoodProduct()
{
	shelfLife = Date(1, 1, 1960);
}

FoodProduct::~FoodProduct()
{
	// ����� ������ ��������� - ��� ����������� ���������� ������ 
	cout << "����������" << " FoodProduct" << endl;
}

FoodProduct::FoodProduct(char * productName_, double cost_, int day_, int mounth_, int year_) :Product(productName_, cost_) {
	shelfLife = Date(day_, mounth_, year_);
}

void FoodProduct::Print() 
{
	Product::Print();
	cout << setw(18) << "���� �������� ��  : " << this->shelfLife.Day << "/" << this->shelfLife.Mounth << "/" << this->shelfLife.Year << endl;
	cout.setf(ios::left);
}

void FoodProduct::set_shelfLife(int day_, int mounth_, int year_)
{
	Date date(day_, mounth_, year_);

	this->shelfLife.Day = day_;


}

Date FoodProduct::get_shelfLife()
{
	return this->shelfLife;
}

istream &operator>>(istream &stream, FoodProduct &o)
{
	cout << "������� �������� :" << endl;
	cin.clear();
	//������� ����� �� ��������� � ��� ��������
	cin.sync();

	// ���������� ����� - �� ������� ������ ������������ ���������� ���������� 
	char * productName = new char[1000];
	// ������������ ���������� ��������
	cin >> setw(1000) >> productName;
	o.setName(productName);

   // ���� �������� 
	cin.clear();
	//������� ����� �� ��������� � ��� ��������
	cin.sync();
	cout << "������� ���� ��������� ����� ��������  " << endl;
	int day = 0;
	cin >> day;

	cin.clear();
	//������� ����� �� ��������� � ��� ��������
	cin.sync();
	cout << "������� ����� ��������� ����� ��������  " << endl;
	int mounth = 0;
	cin >> mounth;

	cin.clear();
	//������� ����� �� ��������� � ��� ��������
	cin.sync();
	cout << "������� ��� ��������� ����� ��������  " << endl;
	int  year = 0;
	cin >> year;

	cin.clear();
	cin.sync();
	cout << "������� ���������  " << endl;
	cin >> o.cost;

	o.set_shelfLife(day, mounth, year);

	// �������� ��������� ������ 
	delete[] productName;
	return stream;
}
