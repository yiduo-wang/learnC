#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;

class str
{
public:
	str(const char* str = "hello world")
	{
		_str = (char*)malloc(strlen(str) + 1);
		strcpy(_str, str);
	}
	~str()
	{
		free(_str);
		_str = nullptr;
	}
	str(const str& str)
	{
		_str = (char*)malloc(strlen(str._str) + 1);
		strcpy(_str, str._str);
	}
	str& operator=(const str& str)
	{
		_str = (char*)malloc(strlen(str._str) + 1);
		strcpy(_str, str._str);
		return *this;
	}
	void Print()
	{
		cout << _str << endl;
	}
private:
	char* _str;
};

int main()
{
	str s1("hello");
	str s2;
	s2 = s1;
	s2.Print();
	system("pause");
}

//class Date
//{
//public:
//	Date(int year = 1990, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date& operator=(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//		return *this;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2(2001, 2, 2);
//	d2 = d1;
//	d2.Print();
//	system("pause");
//}

//class str
//{
//public:
//	str(const char* str = "hello world")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str,str);
//	}
//	~str()
//	{
//		free(_str);
//		_str = nullptr;
//	}
//	str(const str& str)
//	{
//		_str = (char*)malloc(strlen(str._str) + 1);
//		strcpy(_str, str._str);
//	}
//	void Print()
//	{
//		cout << _str << endl;
//	}
//private:
//	char* _str;
//};
//
//int main()
//{
//	str s1;
//	s1.Print();
//	str s2 = s1;
//	s2.Print();
//	system("pause");
//}

//class Date
//{
//public:
//	Date(int year = 1990, int month = 1, int day = 1)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void Print()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	Date d2=d1;
//	d1.Print();
//	d2.Print();
//	system("pause");
//}

//class str
//{
//public:
//	str(const char* str = "hello,world")
//	{
//		_str = (char*)malloc(strlen(str) + 1);
//		strcpy(_str, str);
//	}
//
//	~str()
//	{
//		free(_str);
//		cout << "~str()" << endl;
//	}
//private:
//	char* _str;
//};
//
//class string
//{
//private:
//	int _a;
//	str _s;
//};
//
//int main()
//{
//	string b;
//	
//}

//struct Date
//{
//	void Info(int year, int month=5, int day=3)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << _year << "-" << _month << "-" << _day<<endl;
//	}
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Info(1998);
//	system("pause");
//}

//class Date
//{
//public:
//	void Info(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//
//int main()
//{
//	Date d1;
//	d1.Info(1223, 02, 01);
//	system("pause");
//}

//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << endl;
//	}
//
//	void Show()
//	{
//		cout << "Show()" << endl;
//	}
//private:
//	int _year=5;
//};
//
//int main()
//{
//	Date* p = nullptr;
//	//p->Print();
//	p->Show();
//	system("pause");
//}