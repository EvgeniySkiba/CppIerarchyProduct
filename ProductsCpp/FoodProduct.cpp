#include "FoodProduct.h"


FoodProduct::FoodProduct()
{
	shelfLife = Date(1, 1, 1960);
}

FoodProduct::~FoodProduct()
{
	// здесь только структура - нет динамически выдел€емой пам€ти 
	cout << "ƒеструктор" << " FoodProduct" << endl;
}

FoodProduct::FoodProduct(char * productName_, double cost_, int day_, int mounth_, int year_) :Product(productName_, cost_) {
	shelfLife = Date(day_, mounth_, year_);
}

void FoodProduct::Print() 
{
	Product::Print();
	cout << setw(18) << "—рок годности до  : " << this->shelfLife.Day << "/" << this->shelfLife.Mounth << "/" << this->shelfLife.Year << endl;
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
	cout << "¬ведите название :" << endl;
	cin.clear();
	//очищает поток от имеющихс€ в нем символов
	cin.sync();

	// магическое число - по заданию нельз€ использовать голбальные переменные 
	char * productName = new char[1000];
	// максимальное количество символов
	cin >> setw(1000) >> productName;
	o.setName(productName);

   // срок годности 
	cin.clear();
	//очищает поток от имеющихс€ в нем символов
	cin.sync();
	cout << "¬ведите день окончани€ срока годности  " << endl;
	int day = 0;
	cin >> day;

	cin.clear();
	//очищает поток от имеющихс€ в нем символов
	cin.sync();
	cout << "¬ведите мес€ц окончани€ срока годности  " << endl;
	int mounth = 0;
	cin >> mounth;

	cin.clear();
	//очищает поток от имеющихс€ в нем символов
	cin.sync();
	cout << "¬ведите год окончани€ срока годности  " << endl;
	int  year = 0;
	cin >> year;

	cin.clear();
	cin.sync();
	cout << "¬ведите стоимость  " << endl;
	cin >> o.cost;

	o.set_shelfLife(day, mounth, year);

	// очистить временную пам€ть 
	delete[] productName;
	return stream;
}
