
#pragma once 

#include <iostream>
using namespace std;

///----------------------
/// структура Дата, упрощенный вариант 
///----------------------
struct  Date
{
	//день
	int Day;
	// месяц
	int Mounth;
	//год
	int Year;

	//конструктор по умолчанию
	Date()
	{
		// по умолч 1 янв 1960
		Day = 1;
		Mounth = 1;
		Year = 1960;
	}

	// констуктор с параметрами
	Date(int pDay, int pMounth, int pYear)
	{
		Year = pYear;

		// если  значени не может быть применено 
		if (Mounth<1 && Mounth> 12)
		{
			Mounth = 1;
		}
		else
		{
			Mounth = pMounth;
		}

		// проверям корректность
		if (pDay < 1)
		{
			Day = 1;
		}
		else if ((Mounth == 1 || Mounth == 3 || Mounth == 5 || Mounth == 7 || Mounth == 8 || Mounth == 10 || Mounth == 12) && pDay >31)
		{
			pDay = 1;
		}
		else if ((Mounth == 4 || Mounth == 6 || Mounth == 9 || Mounth == 10) && pDay >30)
		{
			pDay = 1;
		}
		// высокосный  год
		else if (pYear % 4 == 0 && pDay >29)
		{
			pDay = 1;
		}
		else if (pYear % 4 != 0 && pDay >28)
		{
			pDay = 1;
		}
		else
		{
			Day = pDay;
		}
	}


	/// переопределяем оператор присваивания 
	Date& operator= (const Date &book)
	{
		if (this == &book)
		{
			return *this;
		}

		Day = book.Day;
		Mounth = book.Mounth;
		Year = book.Year;	

		return *this;
	}
};

