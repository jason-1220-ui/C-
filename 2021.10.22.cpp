#include <iostream>
using namespace std;

//������Ĭ�ϵ�6������
/*
//���캯��
//����û���ʾ�����˹��캯�������������������ɣ�û�ж��幹�캯����������������Ĭ�Ϲ��캯��
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
	//1.�޲�������
	Date()
	{}
	//2.����������
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
	Date d1;//�����޲ι��캯��
	Date d2(1982, 12, 20);//���ô��ι��캯��
	//���ͨ���޲ι��캯����������ʱ��������治�ø����ţ�����ͳ��˺�������
	Date d1, d2;
	d1.SetDate(2018, 1, 9);
	d1.Display();
	d2.SetDate(2018, 12, 20);
	d2.Display();
	return 0;
}
*/

//��������
//1.������������������ǰ�����ַ�~
//2.���������޲����޷���ֵ
//3.һ��������ֻ��һ��������������δ��ʾ���壬ϵͳ���Զ�����Ĭ�ϵ���������
//4.�����������ڽ���ʱ��C++����ϵͳ�Զ�������������
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
//		free(_data);//�ͷŶ��ϵĿռ�
//		_data = NULL;//��ָ����Ϊ��
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

//�������캯��(�ö����ʼ������ʱ���ᴥ���������캯��)
//��δ��ʾ���壬ϵͳ����Ĭ�ϵĿ������캯��
/*
class Date {
public:
	Date(int year = 1992, int month = 12, int day = 20) {
		_year = year;
		_month = month;
		_day = day;
		cout << "year=" << _year << ",month=" << _month << ",_day=" << _day << endl;
	}
	Date(const Date &d) {//���������ã���ֹ�������޵ݹ�
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

//��ֵ���������
//1.��������
//2.����ֵ
//3.����Ƿ��Լ����Լ���ֵ
//4.����*this
//5.һ�������û�ж��帳ֵ��������أ�������Ҳ������һ����ɶ����ֽ����ֵ����
class Date {
public:
	Date(int year = 1992, int month = 12, int day = 20) {
		_year = year;
		_month = month;
		_day = day;
		cout << "year=" << _year << ",month=" << _month << ",_day=" << _day << endl;
	}
	Date(const Date &d) {//���������ã���ֹ�������޵ݹ�
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
	Test(int data = 0):m_data(data)//�����б��ʼ��
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
//	man._sex = "��";
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

/*//thisָ��
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