#include <iostream>
using namespace std;

//类里面默认的6个函数
/*
//构造函数
//如果用户显示定义了构造函数，编译器将不在生成，没有定义构造函数，编译器会生成默认构造函数
class Date {
public:
	void SetDate(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
	void Display() {
		cout << _year << "-" << _month << "-" << _day << endl;
	}
	//1.无参数构造
	Date()
	{}
	//2.带参数构造
	Date(int year, int month, int day) {
		_year = year;
		_month = month;
		_day = day;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main() {
	Date d1;//调用无参构造函数
	Date d2(1982, 12, 20);//调用带参构造函数
	//如果通过无参构造函数创建对象时，对象后面不用跟括号，否则就成了函数声明
	Date d1, d2;
	d1.SetDate(2018, 1, 9);
	d1.Display();
	d2.SetDate(2018, 12, 20);
	d2.Display();
	return 0;
}
*/

//析构函数
//1.析构函数名是在类名前加上字符~
//2.析构函数无参数无返回值
//3.一个类有且只有一个析构函数。若未显示定义，系统会自动生成默认的析构函数
//4.对象生命周期结束时，C++编译系统自动调用析构函数
//typedef int DataType;
//class Seqlist {
//public:
//	Seqlist(int capacity = 10) {
//		_data = (DataType*)malloc(capacity * sizeof(DataType));
//		assert(_data != NULL);
//		_size = 0;
//		_capacity = capacity;
//		cout << "Creat Seqlist Object:" << this << endl;
//	}
//	~Seqlist() {
//		free(_data);//释放堆上的空间
//		_data = NULL;//将指针置为空
//		_capacity = 0;
//		_size = 0;
//		cout << "Free Seqlist Object:" << this << endl;
//	}
//private:
//	int *_data;
//	size_t _size;
//	size_t _capacity;
//};
//
//int main() {
//	Seqlist();
//	return 0;
//}

//拷贝构造函数(用对象初始化对象时，会触发拷贝构造函数)
//若未显示定义，系统生成默认的拷贝构造函数
/*
class Date {
public:
	Date(int year = 1992, int month = 12, int day = 20) {
		_year = year;
		_month = month;
		_day = day;
		cout << "year=" << _year << ",month=" << _month << ",_day=" << _day << endl;
	}
	Date(const Date &d) {//参数传引用，防止出现无限递归
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "d.year=" << _year << ",d.month=" << _month << ",d._day=" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main() {
	Date d1;
	Date d2(d1);
	return 0;
}
*/

//赋值运算符重载
//1.参数类型
//2.返回值
//3.检测是否自己给自己赋值
//4.返回*this
//5.一个类如果没有定义赋值运算符重载，编译器也会生成一个完成对象按字节序的值拷贝
class Date {
public:
	Date(int year = 1992, int month = 12, int day = 20) {
		_year = year;
		_month = month;
		_day = day;
		cout << "year=" << _year << ",month=" << _month << ",_day=" << _day << endl;
	}
	Date(const Date &d) {//参数传引用，防止出现无限递归
		_year = d._year;
		_month = d._month;
		_day = d._day;
		cout << "d.year=" << _year << ",d.month=" << _month << ",d._day=" << _day << endl;
	}
	Date &operator=(const Date &d) {
		if (this != &d) {
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
		cout << "year=" << _year << ",month=" << _month << ",_day=" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};

int main() {
	Date d1;
	Date d2(2002, 11, 26);
	d1 = d2;
	return 0;
}
/*
class Test {
public:
	Test(int data = 0):m_data(data)//参数列表初始化
	{
		//m_data = data;
	}
	Test(const Test &t) {
		m_data = t.m_data;
	}
	Test& operator=(const Test &t) {
		if (this != &t)
			m_data = t.m_data;
		return *this;
	}
	~Test()
	{}
public:
	Test* operator&()
	{
		return this;
	}
	const Test* operator&()const
	{
		return this;
	}
private:
	int m_data;
};

void main() {
	const Test t;
	Test t1 = t;
	Test t2;
	t2 = t1;

	const Test *pt = &t;
}
*/

//class Person {
//public:
//	void PrintPerson() {
//		cout << _name << " " << _sex << " " << _age << endl;
//	}
//public:
//	const char* _name;
//	const char* _sex;
//	int _age;
//};
//
//int main() {
//	Person man;
//	man._name = "jack";
//	man._sex = "男";
//	man._age = 12;
//	man.PrintPerson();
//	return 0;
//}

//class Person {
//public:
//	void showInfo() {
//		cout << _name << "-" << _sex << "-" << _age << endl;
//	}
//private:
//	char* _name;
//	char* _sex;
//	int _age;
//};

/*//this指针
class Test {
public:
	//void SetData(Test *const this,int data)
	void SetData(int data) {
		m_data = data;
	}
	void GetData() {
		cout << m_data << endl;
	}
private:
	int m_data;
};
int main() {
	Test t1, t2;
	t1.SetData(10);
	t2.SetData(20);
	t1.GetData();
	t2.GetData();
	return 0;
}
*/